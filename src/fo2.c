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

FO2SAVE* readFO2Save(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return NULL;
    }

    FO2SAVE* save = (FO2SAVE*)malloc(FO2SAVE_SIZE);

    if (save == NULL)
    {
        fclose(file);

        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO2SAVE_SIGNATURE_LENGTH, &address, 0);

    if (strcmp(save->saveSignature, FO2SAVE_SIGNATURE) != 0)
    {
        closeFO2Save(save);

        fclose(file);

        return NULL;
    }

    bool ok = true;

    ok &= readFixedString(file, save->playerName, 32, &address, 12);
    ok &= readFixedString(file, save->saveName, 32, &address, 0);

    if (!ok)
    {
        closeFO2Save(save);
    }

    fclose(file);

    return save;
}

bool isFO2Save(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return false;
    }

    FO2SAVE* save = (FO2SAVE*)malloc(FO2SAVE_SIZE);

    if (save == NULL)
    {
        fclose(file);

        return false;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO2SAVE_SIGNATURE_LENGTH, &address, 0);

    int r_strcmp = strcmp(save->saveSignature, FO2SAVE_SIGNATURE);

    closeFO2Save(save);

    fclose(file);

    return r_strcmp == 0;
}

void printFO2Save(
    FO2SAVE* save
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

void closeFO2Save(
    FO2SAVE* save
)
{
    if (save != NULL)
    {
        free(save);
    }
}
