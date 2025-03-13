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
#include "writer.h"

FO3SAVE* readFO3Save(
    const char* saveName
)
{
    FO3SAVE* save = (FO3SAVE*)malloc(FO3SAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    save->save = fopen(saveName, "r+w+b");

    if (save->save == NULL)
    {
        closeFO3Save(save);

        return NULL;
    }

    save->saveFileName = (char*)malloc(strlen(saveName) + 1);

    if (save->saveFileName == NULL)
    {
        closeFO3Save(save);

        return NULL;
    }

    strcpy(save->saveFileName, saveName);

    unsigned long address = 0;
    bool fail = false;

    save->propAddresses[FO3SAVE_PROPS_SAVE_SIGNATURE] = address;
    fail |= !readFixedString(save->save, save->saveSignature, FO3SAVE_SIGNATURE_LENGTH, &address, 0, true);

    save->propAddresses[FO3SAVE_PROPS_ENGINE_VERSION] = address + 4;
    fail |= !readUInt(save->save, &save->engineVersion, &address, 4, true);

    save->propAddresses[FO3SAVE_PROPS_SNAPSHOT_WIDTH] = address + 1;
    fail |= !readUInt(save->save, &save->snapshotWidth, &address, 1, true);

    save->propAddresses[FO3SAVE_PROPS_SNAPSHOT_HEIGHT] = address + 1;
    fail |= !readUInt(save->save, &save->snapshotHeight, &address, 1, true);

    save->propAddresses[FO3SAVE_PROPS_SAVE_NUMBER] = address + 1;
    fail |= !readUInt(save->save, &save->saveNumber, &address, 1, true);

    save->propAddresses[FO3SAVE_PROPS_PLAYER_NAME] = address + 1;
    fail |= !readString(save->save, &save->playerName, &address, 1, 1, true);

    save->propAddresses[FO3SAVE_PROPS_PLAYER_TITLE] = address + 1;
    fail |= !readString(save->save, &save->playerTitle, &address, 1, 1, true);

    save->propAddresses[FO3SAVE_PROPS_PLAYER_LEVEL] = address + 1;
    fail |= !readUInt(save->save, &save->playerLevel, &address, 1, true);

    save->propAddresses[FO3SAVE_PROPS_PLAYER_LOCATION] = address + 1;
    fail |= !readString(save->save, &save->playerLocation, &address, 1, 1, true);

    save->propAddresses[FO3SAVE_PROPS_PLAYER_PLAYTIME] = address + 1;
    fail |= !readString(save->save, &save->playerPlaytime, &address, 1, 1, true);

    save->snapshotLength = save->snapshotWidth * save->snapshotHeight * FO3SAVE_SNAPSHOT_COLOR_BYTES;

    if (save->snapshotLength == 0 || save->snapshotLength > FO3SAVE_MAX_SNAPSHOT_LENGTH)
    {
        closeFO3Save(save);

        return NULL;
    }

    save->snapshot = (unsigned char*)malloc(save->snapshotLength);

    if (save->snapshot == NULL)
    {
        closeFO3Save(save);

        return NULL;
    }

    save->propAddresses[FO3SAVE_PROPS_SNAPHOST] = address + 1;
    fail |= !readUByteArray(save->save, save->snapshot, save->snapshotLength, &address, 1, true);

    if (fail)
    {
        closeFO3Save(save);

        return NULL;
    }

    return save;
}

bool writeFO3Save(
    FO3SAVE* save,
    char* saveName
)
{
    return false;
}

bool isFO3Save(
    const char* saveName
)
{
    FO3SAVE* save = (FO3SAVE*)malloc(FO3SAVE_SIZE);

    if (save == NULL)
    {
        return false;
    }

    save->save = fopen(saveName, "r+b");

    if (save->save == NULL)
    {
        closeFO3Save(save);

        return false;
    }

    unsigned long address = 0;

    readFixedString(save->save, save->saveSignature, FO3SAVE_SIGNATURE_LENGTH, &address, 0, true);

    int r_strcmp = strcmp(save->saveSignature, FO3SAVE_SIGNATURE);

    if (r_strcmp != 0)
    {
        return false;
    }

    if (fseek(save->save, 24, SEEK_SET) != 0)
    {
        return false;
    }

    char nv = 0;

    if (fread(&nv, 1, 1, save->save) != 1)
    {
        return false;
    }

    closeFO3Save(save);

    return nv == '|';
}

void closeFO3Save(
    FO3SAVE* save
)
{
    if (save != NULL)
    {
        if (save->save != NULL)
        {
            fclose(save->save);
        }

        free(save->saveFileName);

        free(save->playerName);
        free(save->playerTitle);
        free(save->playerLocation);
        free(save->playerPlaytime);
        free(save->snapshot);

        free(save);
    }
}



bool readFO3SaveProp(
    FO3SAVE* save,
    FO3SAVE_PROPS prop,
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
    case FO3SAVE_PROPS_SAVE_SIGNATURE:
        result = readFixedString(save->save, (char*)value, FO3SAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FO3SAVE_PROPS_ENGINE_VERSION:
    case FO3SAVE_PROPS_SAVE_NUMBER:
    case FO3SAVE_PROPS_PLAYER_LEVEL:
    case FO3SAVE_PROPS_SNAPSHOT_WIDTH:
    case FO3SAVE_PROPS_SNAPSHOT_HEIGHT:
        result = readUInt(save->save, (unsigned int*)value, &save->propAddresses[prop], 0, false);
        break;

    case FO3SAVE_PROPS_PLAYER_NAME:
    case FO3SAVE_PROPS_PLAYER_TITLE:
    case FO3SAVE_PROPS_PLAYER_LOCATION:
    case FO3SAVE_PROPS_PLAYER_PLAYTIME:
        result = readString(save->save, (char**)value, &save->propAddresses[prop], 0, 1, false);
        break;

    case FO3SAVE_PROPS_SNAPHOST:
        result = readUByteArray(save->save, (unsigned char*)value, save->snapshotLength, &save->propAddresses[prop], 0, false);
        break;

    default:
        break;
    }

    return result;
}

bool writeFO3SaveProp(
    FO3SAVE* save,
    FO3SAVE_PROPS prop,
    void* value
)
{
    return false;
}



bool printFO3Save(
    FO3SAVE* save
)
{
    bool fail = false;

    fail |= printFO3SaveProps(save);

    printf("\n");

    fail |= printFO3SavePropAddresses(save);

    return fail;
}

bool printFO3SaveProps(
    FO3SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    printf("*****************\n");
    printf("* FO3SAVE PROPS *\n");
    printf("*****************\n");

    printf("\n");

    printf("Game Name       : %s\n", FO3SAVE_GAME_NAME);
    printf("Save Name       : %s\n", save->saveFileName);

    printf("\n");

    printf("Save Signature  : %s\n", save->saveSignature);
    printf("Engine Version  : %u\n", save->engineVersion);
    printf("Save Number     : %u\n", save->saveNumber);
    printf("Player Name     : %s\n", save->playerName);
    printf("Player Level    : %u\n", save->playerLevel);
    printf("Player Title    : %s\n", save->playerTitle);
    printf("Player Location : %s\n", save->playerLocation);
    printf("Player Playtime : %s\n", save->playerPlaytime);
    printf("Snapshot Width  : %u\n", save->snapshotWidth);
    printf("Snapshot Height : %u\n", save->snapshotHeight);
    printf("Snapshot Length : %lu\n", save->snapshotLength);

    return true;
}

bool printFO3SavePropAddresses(
    FO3SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    printf("***************************\n");
    printf("* FO3SAVE PROPS ADDRESSES *\n");
    printf("***************************\n");

    printf("\n");

    printf("%-15s : %s\n", "Game Name", FO3SAVE_GAME_NAME);
    printf("%-15s : %s\n", "Save Name", save->saveFileName);

    printf("\n");

    const char* propNames[] = {
        "Save Signature",
        "Engine Version",
        "Save Number",
        "Player Name",
        "Player Level",
        "Player Title",
        "Player Location",
        "Player Playtime",
        "Snapshot Width",
        "Snapshot Height"
    };

    unsigned long* propAddresses[] = {
        &save->propAddresses[FO3SAVE_PROPS_SAVE_SIGNATURE],
        &save->propAddresses[FO3SAVE_PROPS_ENGINE_VERSION],
        &save->propAddresses[FO3SAVE_PROPS_SAVE_NUMBER],
        &save->propAddresses[FO3SAVE_PROPS_PLAYER_NAME],
        &save->propAddresses[FO3SAVE_PROPS_PLAYER_LEVEL],
        &save->propAddresses[FO3SAVE_PROPS_PLAYER_TITLE],
        &save->propAddresses[FO3SAVE_PROPS_PLAYER_LOCATION],
        &save->propAddresses[FO3SAVE_PROPS_PLAYER_PLAYTIME],
        &save->propAddresses[FO3SAVE_PROPS_SNAPSHOT_WIDTH],
        &save->propAddresses[FO3SAVE_PROPS_SNAPSHOT_HEIGHT]
    };

    for (unsigned long i = 0; i < FO3SAVE_PROPS_COUNT - 1; i++)
    {
        printf("%-15s : %016lu %04lX\n", propNames[i], *propAddresses[i], *propAddresses[i]);
    }

    return true;
}

bool printFO3SaveSnapshot(
    FO3SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    for (unsigned long i = 0; i < save->snapshotLength; i += FO3SAVE_SNAPSHOT_COLOR_BYTES)
    {
        printf("R : %03u", save->snapshot[i + 0]);
        printf("G : %03u", save->snapshot[i + 1]);
        printf("B : %03u", save->snapshot[i + 2]);

        if ((i / 4 + 1) % 5 == 0)
        {
            printf("\n");
        }
        else
        {
            printf("  ");
        }
    }

    return true;
}
