/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo4.c
 *
 * Title       : FALLOUT 4 SOURCE
 * Description : Fallout 4 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo4.h"

#include "reader.h"

FO4SAVE* readFO4Save(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return NULL;
    }

    FO4SAVE* save = (FO4SAVE*)malloc(FO4SAVE_SIZE);

    if (save == NULL)
    {
        fclose(file);

        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO4SAVE_SIGNATURE_LENGTH, &address, 0);

    if (strcmp(save->saveSignature, FO4SAVE_SIGNATURE) != 0)
    {
        closeFO4Save(save);

        fclose(file);

        return NULL;
    }

    bool ok = true;

    ok &= readUInt(file, &save->engineVersion, &address, 4);
    ok &= readUInt(file, &save->saveNumber, &address, 0);
    ok &= readString(file, &save->playerName, &address, 0, 0);
    ok &= readUInt(file, &save->playerLevel, &address, 0);
    ok &= readString(file, &save->playerLocation, &address, 0, 0);
    ok &= readString(file, &save->playerPlaytime, &address, 0, 0);
    ok &= readString(file, &save->playerRace, &address, 0, 0);
    ok &= readUShort(file, &save->playerSex, &address, 0);
    ok &= readFloat(file, &save->playerCurrentXp, &address, 0);
    ok &= readFloat(file, &save->playerRequiredXp, &address, 0);
    ok &= readUInt(file, &save->snapshotWidth, &address, 8);
    ok &= readUInt(file, &save->snapshotHeight, &address, 0);

    unsigned long snapshotLength = save->snapshotWidth * save->snapshotHeight * 4;

    save->snapshot = (unsigned char*)malloc(snapshotLength);

    if (save->snapshot == NULL)
    {
        closeFO4Save(save);

        fclose(file);

        return NULL;
    }

    ok &= readUByteArray(file, save->snapshot, snapshotLength, &address, 0);

    if (!ok)
    {
        closeFO4Save(save);
    }

    fclose(file);

    return save;
}

bool isFO4Save(
    const char* saveName
)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return false;
    }

    FO4SAVE* save = (FO4SAVE*)malloc(FO4SAVE_SIZE);

    if (save == NULL)
    {
        fclose(file);

        return false;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO4SAVE_SIGNATURE_LENGTH, &address, 0);

    int r_strcmp = strcmp(save->saveSignature, FO4SAVE_SIGNATURE);

    closeFO4Save(save);

    fclose(file);

    return r_strcmp == 0;
}

void printFO4Save(
    FO4SAVE* save
)
{
    if (save == NULL)
    {
        return;
    }

    printf("Save Signature     : %s\n", save->saveSignature);
    printf("Engine Version     : %u\n", save->engineVersion);
    printf("Save Number        : %u\n", save->saveNumber);

    printf("\n");

    printf("Player Name        : %s\n", save->playerName);
    printf("Player Level       : %u\n", save->playerLevel);
    printf("Player Location    : %s\n", save->playerLocation);
    printf("Player Playtime    : %s\n", save->playerPlaytime);
    printf("Player Race        : %s\n", save->playerRace);
    printf("Player Sex         : %u\n", save->playerSex);
    printf("Player Current Xp  : %f\n", save->playerCurrentXp);
    printf("Player Required Xp : %f\n", save->playerRequiredXp);

    printf("\n");

    printf("Snapshot Width     : %u\n", save->snapshotWidth);
    printf("Snapshot Height    : %u\n", save->snapshotHeight);

    unsigned long snapshotLength = save->snapshotWidth * save->snapshotHeight * 4;

    printf("Snapshot Length    : %lu\n", snapshotLength);
}

void printFO4SaveSnapshot(
    FO4SAVE* save
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

void closeFO4Save(
    FO4SAVE* save
)
{
    if (save != NULL)
    {
        free(save->playerName);
        free(save->playerLocation);
        free(save->playerPlaytime);
        free(save->playerRace);
        free(save->snapshot);

        free(save);
    }
}
