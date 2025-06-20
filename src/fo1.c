/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
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

    FO1SAVE* save = (FO1SAVE*)calloc(1, FO1SAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    save->save = fopen(saveName, "rb+");

    if (save->save == NULL)
    {
        closeFO1Save(save);

        return NULL;
    }

    save->saveFileName = strdup(saveName);

    if (save->saveFileName == NULL)
    {
        closeFO1Save(save);

        return NULL;
    }

    long unsigned int address = 0;
    bool fail = false;

    save->propAddresses[FO1SAVE_PROPS_SAVE_SIGNATURE] = address;
    fail |= !readFixedString(save->save, save->saveSignature, FO1SAVE_SIGNATURE_LENGTH, &address, 0, true);

    save->propAddresses[FO1SAVE_PROPS_PLAYER_NAME] = address + 12;
    fail |= !readFixedString(save->save, save->playerName, FO1SAVE_STRING_SIZE, &address, 12, true);

    save->propAddresses[FO1SAVE_PROPS_SAVE_NAME] = address;
    fail |= !readFixedString(save->save, save->saveName, FO1SAVE_STRING_SIZE, &address, 0, true);

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
    if (save == NULL || save->save == NULL)
    {
        return false;
    }

    long unsigned int address = 0;
    bool fail = false;

    save->propAddresses[FO1SAVE_PROPS_SAVE_SIGNATURE] = address;
    fail |= !writeFixedString(save->save, save->saveSignature, FO1SAVE_SIGNATURE_LENGTH, &address, 0, true);

    save->propAddresses[FO1SAVE_PROPS_PLAYER_NAME] = address + 12;
    fail |= !writeFixedString(save->save, save->playerName, FO1SAVE_STRING_SIZE, &address, 12, true);

    save->propAddresses[FO1SAVE_PROPS_SAVE_NAME] = address;
    fail |= !writeFixedString(save->save, save->saveName, FO1SAVE_STRING_SIZE, &address, 0, true);

    fflush(save->save);

    return fail;
}

bool isFO1Save(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return false;
    }

    FO1SAVE* save = (FO1SAVE*)calloc(1, FO1SAVE_SIZE);

    if (save == NULL)
    {
        return false;
    }

    save->save = fopen(saveName, "rb+");

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

    switch (prop)
    {
    case FO1SAVE_PROPS_SAVE_SIGNATURE:
        strcpy((char*)destination, save->saveSignature);
        break;

    case FO1SAVE_PROPS_SAVE_NAME:
        strcpy((char*)destination, save->saveName);
        break;

    case FO1SAVE_PROPS_PLAYER_NAME:
        strcpy((char*)destination, save->playerName);
        break;

    default:
        break;
    }

    return true;
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

    switch (prop)
    {
    case FO1SAVE_PROPS_SAVE_SIGNATURE:
        strcpy(save->saveSignature, (char*)value);
        break;

    case FO1SAVE_PROPS_SAVE_NAME:
        strcpy(save->saveName, (char*)value);
        break;

    case FO1SAVE_PROPS_PLAYER_NAME:
        strcpy(save->playerName, (char*)value);
        break;

    default:
        break;
    }

    return true;
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
        result = readFixedString(save->save, (char*)destination, FO1SAVE_STRING_SIZE, &save->propAddresses[prop], 0, false);
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
        result = writeFixedString(save->save, (char*)value, FO1SAVE_STRING_SIZE, &save->propAddresses[prop], 0, false);
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
    if (save == NULL)
    {
        printf("***********\n");
        printf("* FO1SAVE *\n");
        printf("***********\n");

        printf("\n");

        printf("/!\\ SAVE NOT OPEN /!\\\n");

        return false;
    }

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
    printf("*****************\n");
    printf("* FO1SAVE PROPS *\n");
    printf("*****************\n");

    printf("\n");

    if (save == NULL)
    {
        printf("/!\\ SAVE NOT OPEN /!\\\n");

        return false;
    }

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
    printf("**************************\n");
    printf("* FO1SAVE PROP ADDRESSES *\n");
    printf("**************************\n");

    printf("\n");

    if (save == NULL)
    {
        printf("/!\\ SAVE NOT OPEN /!\\\n");

        return false;
    }

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



bool createFO1SampleSave()
{
    FILE* save = fopen("fo1.dat", "wb");

    if (save == NULL)
    {
        return false;
    }

    unsigned char* emptyBuffer = (unsigned char*)calloc(64, 1);

    fwrite(FO1SAVE_SIGNATURE, 1, FO1SAVE_SIGNATURE_LENGTH, save);

    fwrite(emptyBuffer, 12, sizeof(*emptyBuffer), save);

    char playerName[FO1SAVE_STRING_SIZE] = "John Fallout";
    fwrite(playerName, sizeof(*playerName), FO1SAVE_STRING_SIZE, save);

    char saveName[FO1SAVE_STRING_SIZE] = "Save 1";
    fwrite(saveName, sizeof(*saveName), FO1SAVE_STRING_SIZE, save);

    fflush(save);

    fclose(save);

    free(emptyBuffer);

    return true;
}
