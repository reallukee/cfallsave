/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
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

    unsigned long address = 0;
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
    FO2SAVE* save,
    char* saveName
)
{
    return false;
}

bool isFO2Save(
    const char* saveName
)
{
    FO2SAVE* save = (FO2SAVE*)malloc(FO2SAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    save->save = fopen(saveName, "r+b");

    if (save->save == NULL)
    {
        closeFO2Save(save);

        return NULL;
    }

    unsigned long address = 0;

    readFixedString(save->save, save->saveSignature, FO2SAVE_SIGNATURE_LENGTH, &address, 0, true);

    int r_strcmp = strcmp(save->saveSignature, FO2SAVE_SIGNATURE);

    closeFO2Save(save);

    return r_strcmp == 0;
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



bool readFO2SaveProperty(
    FO2SAVE* save,
    FO2SAVE_PROPS property,
    void** value
)
{
    if (save == NULL || save->save == NULL)
    {
        return false;
    }

    bool result = true;

    switch (property)
    {
    case FO2SAVE_PROPS_SAVE_SIGNATURE:
        result = readFixedString(save->save, (char*)value, FO2SAVE_SIGNATURE_LENGTH, &save->propAddresses[property], 0, false);
        break;

    case FO2SAVE_PROPS_SAVE_NAME:
    case FO2SAVE_PROPS_PLAYER_NAME:
        result = readFixedString(save->save, (char*)value, 32, &save->propAddresses[property], 0, false);
        break;

    default:
        break;
    }

    return result;
}

bool writeFO2SaveProperty(
    FO2SAVE* save,
    FO2SAVE_PROPS property,
    void* value
)
{
    return false;
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
    printf("Save Name      : %s\n", save->saveFileName);

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

    printf("***************************\n");
    printf("* FO2SAVE PROPS ADDRESSES *\n");
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
        &save->propAddresses[FO2SAVE_PROPS_SAVE_SIGNATURE],
        &save->propAddresses[FO2SAVE_PROPS_SAVE_NAME],
        &save->propAddresses[FO2SAVE_PROPS_PLAYER_NAME]
    };

    for (unsigned long i = 0; i < FO2SAVE_PROPS_COUNT - 1; i++)
    {
        printf("%-14s : %016lu %04lX\n", propNames[i], *propAddresses[i], *propAddresses[i]);
    }

    return true;
}
