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

FO1SAVE* readFO1Save(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return NULL;
    }

    FO1SAVE* save = (FO1SAVE*)malloc(FO1SAVE_SIZE);

    if (save == NULL)
    {
        fclose(file);

        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO1SAVE_SIGNATURE_LENGTH, &address, 0);

    if (strcmp(save->saveSignature, FO1SAVE_SIGNATURE) != 0)
    {
        closeFO1Save(save);

        fclose(file);

        return NULL;
    }

    bool ok = true;

    ok &= readFixedString(file, save->playerName, 32, &address, 12);
    ok &= readFixedString(file, save->saveName, 32, &address, 0);

    if (!ok)
    {
        closeFO1Save(save);
    }

    fclose(file);

    return save;
}

bool isFO1Save(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return false;
    }

    FO1SAVE* save = (FO1SAVE*)malloc(FO1SAVE_SIZE);

    if (save == NULL)
    {
        fclose(file);

        return false;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO1SAVE_SIGNATURE_LENGTH, &address, 0);

    int r_strcmp = strcmp(save->saveSignature, FO1SAVE_SIGNATURE);

    closeFO1Save(save);

    fclose(file);

    return r_strcmp == 0;
}

void printFO1Save(
    FO1SAVE* save
)
{
    if (save == NULL)
    {
        return;
    }

    printf("Save Signature : %s\n", save->saveSignature);

    printf("\n");

    printf("Player Name    : %s\n", save->playerName);
    printf("Save Name      : %s\n", save->saveName);
}

void closeFO1Save(
    FO1SAVE* save
)
{
    if (save != NULL)
    {
        free(save);
    }
}
