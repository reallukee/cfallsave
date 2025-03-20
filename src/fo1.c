/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo1.c
 *
 * Title       : FALLOUT 1 SOURCE
 * Description : Fallout 1 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo1.h"
#include "reader.h"
#include "writer.h"

FO1SAVE* readFO1Save(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return NULL;
    }

    FO1SAVE* save = (FO1SAVE*)malloc(FO1SAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    save->save = fopen(saveName, "r+w+b");

    if (save->save == NULL)
    {
        closeFO1Save(save);

        return NULL;
    }

    save->saveFileName = (char*)malloc(strlen(saveName) + 1);

    if (save->saveFileName == NULL)
    {
        closeFO1Save(save);

        return NULL;
    }

    strcpy(save->saveFileName, saveName);

    long unsigned int address = 0;
    bool fail = false;

    save->propAddresses[FO1SAVE_PROPS_SAVE_SIGNATURE] = address;
    fail |= !readFixedString(save->save, save->saveSignature, FO1SAVE_SIGNATURE_LENGTH, &address, 0, true);

    save->propAddresses[FO1SAVE_PROPS_PLAYER_NAME] = address + 12;
    fail |= !readFixedString(save->save, save->playerName, 32, &address, 12, true);

    save->propAddresses[FO1SAVE_PROPS_SAVE_NAME] = address;
    fail |= !readFixedString(save->save, save->saveName, 32, &address, 0, true);

    if (fail)
    {
        closeFO1Save(save);

        return NULL;
    }

    return save;
}

bool writeFO1Save(
    FO1SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    return true;
}

bool isFO1Save(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return false;
    }

    FO1SAVE* save = (FO1SAVE*)malloc(FO1SAVE_SIZE);

    if (save == NULL)
    {
        return false;
    }

    memset(save, 0, FO1SAVE_SIZE);

    save->save = fopen(saveName, "r+b");

    if (save->save == NULL)
    {
        closeFO1Save(save);

        return false;
    }

    long unsigned int address = 0;

    readFixedString(save->save, save->saveSignature, FO1SAVE_SIGNATURE_LENGTH, &address, 0, true);

    int r_strcmp = strcmp(save->saveSignature, FO1SAVE_SIGNATURE);

    closeFO1Save(save);

    return r_strcmp == 0;
}

bool isFO1SaveOpen(
    FO1SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    return save->save != NULL;
}

void closeFO1Save(
    FO1SAVE* save
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



bool getFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void** destination
)
{
    if (save == NULL || destination == NULL)
    {
        return false;
    }

    return false;
}

bool setFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void** value
)
{
    if (save == NULL || value == NULL)
    {
        return false;
    }

    return false;
}



bool readFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
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
    case FO1SAVE_PROPS_SAVE_SIGNATURE:
        result = readFixedString(save->save, (char*)destination, FO1SAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FO1SAVE_PROPS_SAVE_NAME:
    case FO1SAVE_PROPS_PLAYER_NAME:
        result = readFixedString(save->save, (char*)destination, 32, &save->propAddresses[prop], 0, false);
        break;

    default:
        break;
    }

    return result;
}

bool writeFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
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
    case FO1SAVE_PROPS_SAVE_SIGNATURE:
        result = writeFixedString(save->save, (char*)value, FO1SAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FO1SAVE_PROPS_SAVE_NAME:
    case FO1SAVE_PROPS_PLAYER_NAME:
        result = writeFixedString(save->save, (char*)value, 32, &save->propAddresses[prop], 0, false);
        break;

    default:
        break;
    }

    return result;
}



bool printFO1Save(
    FO1SAVE* save
)
{
    bool fail = false;

    fail |= printFO1SaveProps(save);

    printf("\n");

    fail |= printFO1SavePropAddresses(save);

    return fail;
}

bool printFO1SaveProps(
    FO1SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    printf("*****************\n");
    printf("* FO1SAVE PROPS *\n");
    printf("*****************\n");

    printf("\n");

    printf("Game Name      : %s\n", FO1SAVE_GAME_NAME);
    printf("Save File Name : %s\n", save->saveFileName);

    printf("\n");

    printf("Save Signature : %s\n", save->saveSignature);
    printf("Player Name    : %s\n", save->playerName);
    printf("Save Name      : %s\n", save->saveName);

    return true;
}

bool printFO1SavePropAddresses(
    FO1SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    printf("**************************\n");
    printf("* FO1SAVE PROP ADDRESSES *\n");
    printf("**************************\n");

    printf("\n");

    printf("%-14s : %s\n", "Save File Name", save->saveName);

    printf("\n");

    const char* propNames[] = {
        "Save Signature",
        "Save Name",
        "Player Name"
    };

    long unsigned int* propAddresses[FO1SAVE_PROPS_COUNT] = {
        &save->propAddresses[FO1SAVE_PROPS_SAVE_SIGNATURE],
        &save->propAddresses[FO1SAVE_PROPS_SAVE_NAME],
        &save->propAddresses[FO1SAVE_PROPS_PLAYER_NAME]
    };

    for (long unsigned int i = 0; i < FO1SAVE_PROPS_COUNT; i++)
    {
        printf("%-14s : %016lu %04lX\n", propNames[i], *propAddresses[i], *propAddresses[i]);
    }

    return true;
}
