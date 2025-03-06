/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fotbos.c
 *
 * Title       : FALLOUT TACTICS: BROTHERHOOD OF STEEL SOURCE
 * Description : Fallout Tactics: Brotherhood of Steel Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fotbos.h"

#include "reader.h"

FOTBOSSAVE* readFOTBOSSave(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return NULL;
    }

    FOTBOSSAVE* save = (FOTBOSSAVE*)malloc(FOTBOSSAVE_SIZE);

    if (save == NULL)
    {
        fclose(file);

        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FOTBOS_SAVE_SIGNATURE_LENGTH, &address, 0);

    if (strcmp(save->saveSignature, FOTBOS_SAVE_SIGNATURE) != 0)
    {
        closeFOTBOSSave(save);

        fclose(file);

        return NULL;
    }

    bool ok = true;

    ok &= readCURSEDString(file, &save->saveName, &address, 8, 2);
    ok &= readCURSEDString(file, &save->playerName, &address, 0, 2);
    ok &= readCURSEDString(file, &save->playerLocation, &address, 0, 2);
    ok &= readCURSEDString(file, &save->gameDateTime, &address, 0, 2);

    if (!ok)
    {
        closeFOTBOSSave(save);
    }

    fclose(file);

    return save;
}

bool isFOTBOSSave(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return false;
    }

    FOTBOSSAVE* save = (FOTBOSSAVE*)malloc(FOTBOSSAVE_SIZE);

    if (save == NULL)
    {
        fclose(file);

        return false;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FOTBOS_SAVE_SIGNATURE_LENGTH, &address, 0);

    int r_strcmp = strcmp(save->saveSignature, FOTBOS_SAVE_SIGNATURE);

    closeFOTBOSSave(save);

    fclose(file);

    return r_strcmp == 0;
}

void printFOTBOSSave(
    FOTBOSSAVE* save
)
{
    if (save == NULL)
    {
        return;
    }

    printf("Save Signature  : %s\n", save->saveSignature);
    printf("Save Name       : %s\n", save->saveName);

    printf("\n");

    printf("Player Name     : %s\n", save->playerName);
    printf("Player Location : %s\n", save->playerLocation);
    printf("Game Date Time  : %s\n", save->gameDateTime);
}

void closeFOTBOSSave(
    FOTBOSSAVE* save
)
{
    if (save != NULL)
    {
        free(save->saveName);
        free(save->playerName);
        free(save->playerLocation);
        free(save->gameDateTime);

        free(save);
    }
}
