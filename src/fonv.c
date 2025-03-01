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

#include "fonv.h"

#include "reader.h"

FONVSAVE* readFONVSave(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return NULL;
    }

    FONVSAVE* save = (FONVSAVE*)malloc(FONVSAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FONV_SAVE_SIGNATURE_LENGTH, &address, 0);

    if (strcmp(save->saveSignature, FONV_SAVE_SIGNATURE) != 0)
    {
        closeFONVSave(save);

        return NULL;
    }

    readUInt(file, &save->engineVersion, &address, 4);
    readUInt(file, &save->snapshotWidth, &address, 66);
    readUInt(file, &save->snapshotHeight, &address, 1);
    readUInt(file, &save->saveNumber, &address, 1);
    readString(file, &save->playerName, &address, 1, 1);
    readString(file, &save->playerTitle, &address, 1, 1);
    readUInt(file, &save->playerLevel, &address, 1);
    readString(file, &save->playerLocation, &address, 1, 1);
    readString(file, &save->playerPlaytime, &address, 1, 1);

    unsigned long snapshotLength = save->snapshotWidth * save->snapshotHeight * 4;

    save->snapshot = (unsigned char*)malloc(snapshotLength);

    if (save->snapshot == NULL)
    {
        return NULL;
    }

    readUByteArray(file, save->snapshot, snapshotLength, &address, 0);

    fclose(file);

    return save;
}

bool isFONVSave(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return NULL;
    }

    FONVSAVE* save = (FONVSAVE*)malloc(FONVSAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FONV_SAVE_SIGNATURE_LENGTH, &address, 0);

    int r_strcmp = strcmp(save->saveSignature, FONV_SAVE_SIGNATURE);

    if (r_strcmp != 0)
    {
        return false;
    }

    if (fseek(file, 24, SEEK_SET) != 0)
    {
        return false;
    }

    char nv = 0;

    if (fread(&nv, 1, 1, file) != 1)
    {
        return false;
    }

    closeFONVSave(save);

    fclose(file);

    return nv != '|';
}

void printFONVSave(
    FONVSAVE* save
)
{
    if (save == NULL)
    {
        return;
    }

    printf("Save Signature  : %s\n", save->saveSignature);
    printf("Engine Version  : %u\n", save->engineVersion);
    printf("Save Number     : %u\n", save->saveNumber);

    printf("\n");

    printf("Player Name     : %s\n", save->playerName);
    printf("Player Level    : %u\n", save->playerLevel);
    printf("Player Title    : %s\n", save->playerTitle);
    printf("Player Location : %s\n", save->playerLocation);
    printf("Player Playtime : %s\n", save->playerPlaytime);

    printf("\n");

    printf("Snapshot Width  : %u\n", save->snapshotWidth);
    printf("Snapshot Height : %u\n", save->snapshotHeight);

    unsigned long snapshotLength = save->snapshotWidth * save->snapshotHeight * 4;

    for (unsigned long i = 0; i < snapshotLength; i += 4)
    {
        printf("R : %03u ", save->snapshot[i + 0]);
        printf("G : %03u ", save->snapshot[i + 1]);
        printf("B : %03u ", save->snapshot[i + 2]);
        printf("A : %03u ", save->snapshot[i + 3]);

        if ((i / 4 + 1) % 5 == 0)
        {
            printf("\n");
        }
        else
        {
            printf("  ");
        }
    }

    return;
}

void closeFONVSave(
    FONVSAVE* save
)
{
    if (save != NULL)
    {
        if (save->playerName != NULL)
        {
            free(save->playerName);
        }

        if (save->playerTitle != NULL)
        {
            free(save->playerTitle);
        }

        if (save->playerLocation != NULL)
        {
            free(save->playerLocation);
        }

        if (save->playerPlaytime != NULL)
        {
            free(save->playerPlaytime);
        }

        if (save->snapshot != NULL)
        {
            free(save->snapshot);
        }

        free(save);
    }
}
