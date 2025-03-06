/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo3.c
 *
 * Title       : FALLOUT 3 SOURCE
 * Description : Fallout 3 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo3.h"

#include "reader.h"

FO3SAVE* readFO3Save(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return NULL;
    }

    FO3SAVE* save = (FO3SAVE*)malloc(FO3SAVE_SIZE);

    if (save == NULL)
    {
        fclose(file);

        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO3SAVE_SIGNATURE_LENGTH, &address, 0);

    if (strcmp(save->saveSignature, FO3SAVE_SIGNATURE) != 0)
    {
        closeFO3Save(save);

        fclose(file);

        return NULL;
    }

    bool ok = true;

    ok &= readUInt(file, &save->engineVersion, &address, 4);
    ok &= readUInt(file, &save->snapshotWidth, &address, 1);
    ok &= readUInt(file, &save->snapshotHeight, &address, 1);
    ok &= readUInt(file, &save->saveNumber, &address, 1);
    ok &= readString(file, &save->playerName, &address, 1, 1);
    ok &= readString(file, &save->playerTitle, &address, 1, 1);
    ok &= readUInt(file, &save->playerLevel, &address, 1);
    ok &= readString(file, &save->playerLocation, &address, 1, 1);
    ok &= readString(file, &save->playerPlaytime, &address, 1, 1);

    unsigned long snapshotLength = save->snapshotWidth * save->snapshotHeight * 4;

    save->snapshot = (unsigned char*)malloc(snapshotLength);

    if (save->snapshot == NULL)
    {
        closeFO3Save(save);

        fclose(file);

        return NULL;
    }

    ok &= readUByteArray(file, save->snapshot, snapshotLength, &address, 0);

    if (!ok)
    {
        closeFO3Save(save);
    }

    fclose(file);

    return save;
}

bool isFO3Save(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return false;
    }

    FO3SAVE* save = (FO3SAVE*)malloc(FO3SAVE_SIZE);

    if (save == NULL)
    {
        fclose(file);

        return false;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO3SAVE_SIGNATURE_LENGTH, &address, 0);

    int r_strcmp = strcmp(save->saveSignature, FO3SAVE_SIGNATURE);

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

    closeFO3Save(save);

    fclose(file);

    return nv == '|';
}

void printFO3Save(
    FO3SAVE* save
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

    printf("Snapshot Length : %lu\n", snapshotLength);
}

void printFO3SaveSnapshot(
    FO3SAVE* save
)
{
    if (save == NULL)
    {
        return;
    }

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
}

void closeFO3Save(
    FO3SAVE* save
)
{
    if (save != NULL)
    {
        free(save->playerName);
        free(save->playerTitle);
        free(save->playerLocation);
        free(save->playerPlaytime);
        free(save->snapshot);

        free(save);
    }
}
