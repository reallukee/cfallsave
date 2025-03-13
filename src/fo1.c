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

    unsigned long address = 0;
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
    FO1SAVE* save,
    char* saveName
)
{
    return false;
}

bool isFO1Save(
    const char* saveName
)
{
    FO1SAVE* save = (FO1SAVE*)malloc(FO1SAVE_SIZE);

    if (save == NULL)
    {
        return false;
    }

    save->save = fopen(saveName, "r+b");

    if (save->save == NULL)
    {
        closeFO1Save(save);

        return false;
    }

    unsigned long address = 0;

    readFixedString(save->save, save->saveSignature, FO1SAVE_SIGNATURE_LENGTH, &address, 0, true);

    int r_strcmp = strcmp(save->saveSignature, FO1SAVE_SIGNATURE);

    closeFO1Save(save);

    return r_strcmp == 0;
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



bool readFO1SaveProp(
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
        result = readFixedString(save->save, (char*)value, FO1SAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FO1SAVE_PROPS_SAVE_NAME:
    case FO1SAVE_PROPS_PLAYER_NAME:
        result = readFixedString(save->save, (char*)value, 32, &save->propAddresses[prop], 0, false);
        break;

    default:
        break;
    }

    return result;
}

bool writeFO1SaveProp(
    FO1SAVE* save,
    FO1SAVE_PROPS prop,
    void* value
)
{
    return false;
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
    printf("Save Name      : %s\n", save->saveFileName);

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

    printf("***************************\n");
    printf("* FO1SAVE PROPS ADDRESSES *\n");
    printf("***************************\n");

    printf("\n");

    printf("%-14s : %s\n", "Save Name", save->saveName);

    printf("\n");

    const char* propNames[] = {
        "Save Signature",
        "Save Name",
        "Player Name"
    };

    unsigned long* propAddresses[] = {
        &save->propAddresses[FO1SAVE_PROPS_SAVE_SIGNATURE],
        &save->propAddresses[FO1SAVE_PROPS_SAVE_NAME],
        &save->propAddresses[FO1SAVE_PROPS_PLAYER_NAME]
    };

    for (unsigned long i = 0; i < FO1SAVE_PROPS_COUNT - 1; i++)
    {
        printf("%-14s : %016lu %04lX\n", propNames[i], *propAddresses[i], *propAddresses[i]);
    }

    return true;
}
