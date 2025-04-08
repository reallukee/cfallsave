/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : fo2.c
 *
 * Title       : FALLOUT 2 SOURCE
 * Description : Fallout 2 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo2.h"
#include "reader.h"
#include "writer.h"

FO2SAVE* readFO2Save(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return NULL;
    }

    FO2SAVE* save = (FO2SAVE*)malloc(FO2SAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    save->save = fopen(saveName, "r+w+b");

    if (save->save == NULL)
    {
        closeFO2Save(save);

        return NULL;
    }

    save->saveFileName = (char*)malloc(strlen(saveName) + 1);

    if (save->saveFileName == NULL)
    {
        closeFO2Save(save);

        return NULL;
    }

    strcpy(save->saveFileName, saveName);

    long unsigned int address = 0;
    bool fail = false;

    save->propAddresses[FO2SAVE_PROPS_SAVE_SIGNATURE] = address;
    fail |= !readFixedString(save->save, save->saveSignature, FO2SAVE_SIGNATURE_LENGTH, &address, 0, true);

    save->propAddresses[FO2SAVE_PROPS_PLAYER_NAME] = address + 12;
    fail |= !readFixedString(save->save, save->playerName, 32, &address, 12, true);

    save->propAddresses[FO2SAVE_PROPS_SAVE_NAME] = address;
    fail |= !readFixedString(save->save, save->saveName, 32, &address, 0, true);

    if (fail)
    {
        closeFO2Save(save);

        return NULL;
    }

    return save;
}

bool writeFO2Save(
    FO2SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    return true;
}

bool isFO2Save(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return false;
    }

    FO2SAVE* save = (FO2SAVE*)malloc(FO2SAVE_SIZE);

    if (save == NULL)
    {
        return false;
    }

    memset(save, 0, FO2SAVE_SIZE);

    save->save = fopen(saveName, "r+b");

    if (save->save == NULL)
    {
        closeFO2Save(save);

        return false;
    }

    long unsigned int address = 0;

    readFixedString(save->save, save->saveSignature, FO2SAVE_SIGNATURE_LENGTH, &address, 0, true);

    int r_strcmp = strcmp(save->saveSignature, FO2SAVE_SIGNATURE);

    closeFO2Save(save);

    return r_strcmp == 0;
}

bool isFO2SaveOpen(
    FO2SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    return save->save != NULL;
}

void closeFO2Save(
    FO2SAVE* save
)
{
    if (save != NULL)
    {
        if (save->save != NULL)
        {
            fclose(save->save);
        }

        free(save->saveFileName);

        free(save);
    }
}



bool getFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** destination
)
{
    if (save == NULL || destination == NULL)
    {
        return false;
    }

    switch (prop)
    {
    case FO2SAVE_PROPS_SAVE_SIGNATURE:
        strcpy((char*)destination, save->saveSignature);
        break;

    case FO2SAVE_PROPS_SAVE_NAME:
        strcpy((char*)destination, save->saveName);
        break;

    case FO2SAVE_PROPS_PLAYER_NAME:
        strcpy((char*)destination, save->playerName);
        break;

    default:
        break;
    }

    return false;
}

bool setFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** value
)
{
    if (save == NULL || value == NULL)
    {
        return false;
    }

    switch (prop)
    {
    case FO2SAVE_PROPS_SAVE_SIGNATURE:
        strcpy(save->saveSignature, (char*)value);
        break;

    case FO2SAVE_PROPS_SAVE_NAME:
        strcpy(save->saveName, (char*)value);
        break;

    case FO2SAVE_PROPS_PLAYER_NAME:
        strcpy(save->playerName, (char*)value);
        break;

    default:
        break;
    }

    return false;
}



bool readFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** destination
)
{
    if (save == NULL || save->save == NULL)
    {
        return false;
    }

    bool result = true;

    switch (prop)
    {
    case FO2SAVE_PROPS_SAVE_SIGNATURE:
        result = readFixedString(save->save, (char*)destination, FO2SAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FO2SAVE_PROPS_SAVE_NAME:
    case FO2SAVE_PROPS_PLAYER_NAME:
        result = readFixedString(save->save, (char*)destination, 32, &save->propAddresses[prop], 0, false);
        break;

    default:
        break;
    }

    return result;
}

bool writeFO2SaveProp(
    FO2SAVE* save,
    FO2SAVE_PROPS prop,
    void** value
)
{
    if (save == NULL || save->save == NULL)
    {
        return false;
    }

    bool result = true;

    switch (prop)
    {
    case FO2SAVE_PROPS_SAVE_SIGNATURE:
        result = writeFixedString(save->save, (char*)value, FO2SAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FO2SAVE_PROPS_SAVE_NAME:
    case FO2SAVE_PROPS_PLAYER_NAME:
        result = writeFixedString(save->save, (char*)value, 32, &save->propAddresses[prop], 0, false);
        break;

    default:
        break;
    }

    return result;
}



bool printFO2Save(
    FO2SAVE* save
)
{
    bool fail = false;

    fail |= printFO2SaveProps(save);

    printf("\n");

    fail |= printFO2SavePropAddresses(save);

    return fail;
}

bool printFO2SaveProps(
    FO2SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    printf("*****************\n");
    printf("* FO2SAVE PROPS *\n");
    printf("*****************\n");

    printf("\n");

    printf("Game Name      : %s\n", FO2SAVE_GAME_NAME);
    printf("Save File Name : %s\n", save->saveFileName);

    printf("\n");

    printf("Save Signature : %s\n", save->saveSignature);
    printf("Player Name    : %s\n", save->playerName);
    printf("Save Name      : %s\n", save->saveName);

    return true;
}

bool printFO2SavePropAddresses(
    FO2SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    printf("**************************\n");
    printf("* FO2SAVE PROP ADDRESSES *\n");
    printf("**************************\n");

    printf("\n");

    printf("%-14s : %s\n", "Save File Name", save->saveName);

    printf("\n");

    const char* propNames[] = {
        "Save Signature",
        "Save Name",
        "Player Name"
    };

    long unsigned int* propAddresses[FO2SAVE_PROPS_COUNT] = {
        &save->propAddresses[FO2SAVE_PROPS_SAVE_SIGNATURE],
        &save->propAddresses[FO2SAVE_PROPS_SAVE_NAME],
        &save->propAddresses[FO2SAVE_PROPS_PLAYER_NAME]
    };

    for (long unsigned int i = 0; i < FO2SAVE_PROPS_COUNT; i++)
    {
        printf("%-14s : %016lu %04lX\n", propNames[i], *propAddresses[i], *propAddresses[i]);
    }

    return true;
}
