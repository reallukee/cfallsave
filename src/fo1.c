/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * Author  : Reallukee
 * Version : 1.0
 * License : MIT
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
        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO1_SAVE_SIGNATURE_LENGTH, &address, 0);

    if (strcmp(save->saveSignature, FO1_SAVE_SIGNATURE) != 0)
    {
        closeFO1Save(save);

        return NULL;
    }

    readFixedString(file, save->playerName, 32, &address, 12);
    readFixedString(file, save->saveName, 32, &address, 0);

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
        return NULL;
    }

    FO1SAVE* save = (FO1SAVE*)malloc(FO1SAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO1_SAVE_SIGNATURE_LENGTH, &address, 0);

    int r_strcmp = strcmp(save->saveSignature, FO1_SAVE_SIGNATURE);

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
