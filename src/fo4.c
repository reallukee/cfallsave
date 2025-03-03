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
        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO4_SAVE_SIGNATURE_LENGTH, &address, 0);

    if (strcmp(save->saveSignature, FO4_SAVE_SIGNATURE) != 0)
    {
        closeFO4Save(save);

        return NULL;
    }

    readUInt(file, &save->engineVersion, &address, 4);
    readUInt(file, &save->saveNumber, &address, 0);
    readString(file, &save->playerName, &address, 0, 0);
    readUInt(file, &save->playerLevel, &address, 0);
    readString(file, &save->playerLocation, &address, 0, 0);
    readString(file, &save->playerPlaytime, &address, 0, 0);
    readString(file, &save->playerRace, &address, 0, 0);
    readUShort(file, &save->playerSex, &address, 0);
    readFloat(file, &save->playerCurrentXp, &address, 0);
    readFloat(file, &save->playerRequiredXp, &address, 0);
    readUInt(file, &save->snapshotWidth, &address, 8);
    readUInt(file, &save->snapshotHeight, &address, 0);

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

bool isFO4Save(
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
        return NULL;
    }

    unsigned long address = 0;

    readFixedString(file, save->saveSignature, FO4_SAVE_SIGNATURE_LENGTH, &address, 0);

    int r_strcmp = strcmp(save->saveSignature, FO4_SAVE_SIGNATURE);

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
        if (save->playerName != NULL)
        {
            free(save->playerName);
        }

        if (save->playerLocation != NULL)
        {
            free(save->playerLocation);
        }

        if (save->playerPlaytime != NULL)
        {
            free(save->playerPlaytime);
        }

        if (save->playerRace != NULL)
        {
            free(save->playerRace);
        }

        if (save->snapshot != NULL)
        {
            free(save->snapshot);
        }

        free(save);
    }
}
