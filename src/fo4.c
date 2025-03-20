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
#include "writer.h"

FO4SAVE* readFO4Save(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return NULL;
    }

    FO4SAVE* save = (FO4SAVE*)malloc(FO4SAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    save->save = fopen(saveName, "r+w+b");

    if (save->save == NULL)
    {
        closeFO4Save(save);

        return NULL;
    }

    save->saveFileName = (char*)malloc(strlen(saveName) + 1);

    if (save->saveFileName == NULL)
    {
        closeFO4Save(save);

        return NULL;
    }

    strcpy(save->saveFileName, saveName);

    long unsigned int address = 0;
    bool fail = false;

    save->propAddresses[FO4SAVE_PROPS_SAVE_SIGNATURE] = address;
    fail |= !readFixedString(save->save, save->saveSignature, FO4SAVE_SIGNATURE_LENGTH, &address, 0, true);

    save->propAddresses[FO4SAVE_PROPS_ENGINE_VERSION] = address + 4;
    fail |= !readUInt(save->save, &save->engineVersion, &address, 4, true);

    save->propAddresses[FO4SAVE_PROPS_SAVE_NUMBER] = address;
    fail |= !readUInt(save->save, &save->saveNumber, &address, 0, true);

    save->propAddresses[FO4SAVE_PROPS_PLAYER_NAME] = address;
    fail |= !readString(save->save, &save->playerName, &address, 0, 0, true);

    save->propAddresses[FO4SAVE_PROPS_PLAYER_LEVEL] = address;
    fail |= !readUInt(save->save, &save->playerLevel, &address, 0, true);

    save->propAddresses[FO4SAVE_PROPS_PLAYER_LOCATION] = address;
    fail |= !readString(save->save, &save->playerLocation, &address, 0, 0, true);

    save->propAddresses[FO4SAVE_PROPS_PLAYER_PLAYTIME] = address;
    fail |= !readString(save->save, &save->playerPlaytime, &address, 0, 0, true);

    save->propAddresses[FO4SAVE_PROPS_PLAYER_RACE] = address;
    fail |= !readString(save->save, &save->playerRace, &address, 0, 0, true);

    save->propAddresses[FO4SAVE_PROPS_PLAYER_SEX] = address;
    fail |= !readUShort(save->save, &save->playerSex, &address, 0, true);

    save->propAddresses[FO4SAVE_PROPS_PLAYER_CURRENT_XP] = address;
    fail |= !readFloat(save->save, &save->playerCurrentXp, &address, 0, true);

    save->propAddresses[FO4SAVE_PROPS_PLAYER_REQUIRED_XP] = address;
    fail |= !readFloat(save->save, &save->playerRequiredXp, &address, 0, true);

    save->propAddresses[FO4SAVE_PROPS_SNAPSHOT_WIDTH] = address + 8;
    fail |= !readUInt(save->save, &save->snapshotWidth, &address, 8, true);

    save->propAddresses[FO4SAVE_PROPS_SNAPSHOT_HEIGHT] = address;
    fail |= !readUInt(save->save, &save->snapshotHeight, &address, 0, true);

    save->snapshotLength = save->snapshotWidth * save->snapshotHeight * FO4SAVE_SNAPSHOT_COLOR_BYTES;

    if (save->snapshotLength == 0 || save->snapshotLength > FO4SAVE_MAX_SNAPSHOT_LENGTH)
    {
        closeFO4Save(save);

        return NULL;
    }

    save->snapshot = (unsigned char*)malloc(save->snapshotLength);

    if (save->snapshot == NULL)
    {
        closeFO4Save(save);

        return NULL;
    }

    save->propAddresses[FO4SAVE_PROPS_SNAPSHOT] = address;
    fail |= !readUByteArray(save->save, save->snapshot, save->snapshotLength, &address, 0, true);

    if (fail)
    {
        closeFO4Save(save);

        return NULL;
    }

    return save;
}

bool writeFO4Save(
    FO4SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    return true;
}

bool isFO4Save(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return false;
    }

    FO4SAVE* save = (FO4SAVE*)malloc(FO4SAVE_SIZE);

    if (save == NULL)
    {
        return false;
    }

    memset(save, 0, FO4SAVE_SIZE);

    save->save = fopen(saveName, "r+b");

    if (save->save == NULL)
    {
        closeFO4Save(save);

        return false;
    }

    long unsigned int address = 0;

    readFixedString(save->save, save->saveSignature, FO4SAVE_SIGNATURE_LENGTH, &address, 0, true);

    int r_strcmp = strcmp(save->saveSignature, FO4SAVE_SIGNATURE);

    closeFO4Save(save);

    return r_strcmp == 0;
}

bool isFO4SaveOpen(
    FO4SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    return save->save != NULL;
}

void closeFO4Save(
    FO4SAVE* save
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
        free(save->playerLocation);
        free(save->playerPlaytime);
        free(save->playerRace);
        free(save->snapshot);

        free(save);
    }
}



bool getFO4SaveProp(
    FO4SAVE* save,
    FO4SAVE_PROPS prop,
    void** destination
)
{
    if (save == NULL || destination == NULL)
    {
        return false;
    }

    return false;
}

bool setFO4SaveProp(
    FO4SAVE* save,
    FO4SAVE_PROPS prop,
    void** value
)
{
    if (save == NULL || value == NULL)
    {
        return false;
    }

    return false;
}



bool readFO4SaveProp(
    FO4SAVE* save,
    FO4SAVE_PROPS prop,
    void** destination
)
{
    if (save == NULL || save->save == NULL)
    {
        return false;
    }

    bool result = true;

    switch (prop)
    {
    case FO4SAVE_PROPS_SAVE_SIGNATURE:
        result = readFixedString(save->save, (char*)destination, FO4SAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FO4SAVE_PROPS_ENGINE_VERSION:
    case FO4SAVE_PROPS_SAVE_NUMBER:
    case FO4SAVE_PROPS_PLAYER_LEVEL:
    case FO4SAVE_PROPS_SNAPSHOT_WIDTH:
    case FO4SAVE_PROPS_SNAPSHOT_HEIGHT:
        result = readUInt(save->save, (unsigned int*)destination, &save->propAddresses[prop], 0, false);
        break;

    case FO4SAVE_PROPS_PLAYER_NAME:
    case FO4SAVE_PROPS_PLAYER_LOCATION:
    case FO4SAVE_PROPS_PLAYER_PLAYTIME:
    case FO4SAVE_PROPS_PLAYER_RACE:
        result = readString(save->save, (char**)destination, &save->propAddresses[prop], 0, 0, false);
        break;

    case FO4SAVE_PROPS_PLAYER_SEX:
        result = readUShort(save->save, (short unsigned int*)destination, &save->propAddresses[prop], 0, false);
        break;

    case FO4SAVE_PROPS_PLAYER_CURRENT_XP:
    case FO4SAVE_PROPS_PLAYER_REQUIRED_XP:
        result = readFloat(save->save, (float*)destination, &save->propAddresses[prop], 0, false);
        break;

    case FO4SAVE_PROPS_SNAPSHOT:
        result = readUByteArray(save->save, (unsigned char*)destination, save->snapshotLength, &save->propAddresses[prop], 0, false);
        break;

    default:
        break;
    }

    return result;
}

bool writeFO4SaveProp(
    FO4SAVE* save,
    FO4SAVE_PROPS prop,
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
    case FO4SAVE_PROPS_SAVE_SIGNATURE:
        result = writeFixedString(save->save, (char*)value, FO4SAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FO4SAVE_PROPS_ENGINE_VERSION:
    case FO4SAVE_PROPS_SAVE_NUMBER:
    case FO4SAVE_PROPS_PLAYER_LEVEL:
    case FO4SAVE_PROPS_SNAPSHOT_WIDTH:
    case FO4SAVE_PROPS_SNAPSHOT_HEIGHT:
        result = writeUInt(save->save, (unsigned int*)value, &save->propAddresses[prop], 0, false);
        break;

    case FO4SAVE_PROPS_PLAYER_NAME:
    case FO4SAVE_PROPS_PLAYER_LOCATION:
    case FO4SAVE_PROPS_PLAYER_PLAYTIME:
    case FO4SAVE_PROPS_PLAYER_RACE:
        result = writeString(save->save, (char**)value, &save->propAddresses[prop], 0, 0, false);
        break;

    case FO4SAVE_PROPS_PLAYER_SEX:
        result = writeUShort(save->save, (short unsigned int*)value, &save->propAddresses[prop], 0, false);
        break;

    case FO4SAVE_PROPS_PLAYER_CURRENT_XP:
    case FO4SAVE_PROPS_PLAYER_REQUIRED_XP:
        result = writeFloat(save->save, (float*)value, &save->propAddresses[prop], 0, false);
        break;

    case FO4SAVE_PROPS_SNAPSHOT:
        result = writeUByteArray(save->save, (unsigned char*)value, save->snapshotLength, &save->propAddresses[prop], 0, false);
        break;

    default:
        break;
    }

    return result;
}



bool printFO4Save(
    FO4SAVE* save
)
{
    bool fail = false;

    fail |= printFO4SaveProps(save);

    printf("\n");

    fail |= printFO4SavePropAddresses(save);

    return fail;
}

bool printFO4SaveProps(
    FO4SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    printf("*****************\n");
    printf("* FO4SAVE PROPS *\n");
    printf("*****************\n");

    printf("\n");

    printf("Game Name          : %s\n", FO4SAVE_GAME_NAME);
    printf("Save File Name     : %s\n", save->saveFileName);

    printf("\n");

    printf("Save Signature     : %s\n", save->saveSignature);
    printf("Engine Version     : %u\n", save->engineVersion);
    printf("Save Number        : %u\n", save->saveNumber);
    printf("Player Name        : %s\n", save->playerName);
    printf("Player Level       : %u\n", save->playerLevel);
    printf("Player Location    : %s\n", save->playerLocation);
    printf("Player Playtime    : %s\n", save->playerPlaytime);
    printf("Player Race        : %s\n", save->playerRace);
    printf("Player Sex         : %u\n", save->playerSex);
    printf("Player Current Xp  : %f\n", save->playerCurrentXp);
    printf("Player Required Xp : %f\n", save->playerRequiredXp);
    printf("Snapshot Width     : %u\n", save->snapshotWidth);
    printf("Snapshot Height    : %u\n", save->snapshotHeight);
    printf("Snapshot Length    : %lu\n", save->snapshotLength);

    return true;
}

bool printFO4SavePropAddresses(
    FO4SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    printf("**************************\n");
    printf("* FO4SAVE PROP ADDRESSES *\n");
    printf("**************************\n");

    printf("\n");

    printf("%-18s : %s\n", "Game Name", FO4SAVE_GAME_NAME);
    printf("%-18s : %s\n", "Save File Name", save->saveFileName);

    printf("\n");

    const char* propNames[] = {
        "Save Signature",
        "Engine Version",
        "Save Number",
        "Player Name",
        "Player Level",
        "Player Location",
        "Player Playtime",
        "Player Race",
        "Player Sex",
        "Player Current Xp",
        "Player Required Xp",
        "Snapshot Width",
        "Snapshot Height"
    };

    long unsigned int* propAddresses[FO4SAVE_PROPS_COUNT - 1] = {
        &save->propAddresses[FO4SAVE_PROPS_SAVE_SIGNATURE],
        &save->propAddresses[FO4SAVE_PROPS_ENGINE_VERSION],
        &save->propAddresses[FO4SAVE_PROPS_SAVE_NUMBER],
        &save->propAddresses[FO4SAVE_PROPS_PLAYER_NAME],
        &save->propAddresses[FO4SAVE_PROPS_PLAYER_LEVEL],
        &save->propAddresses[FO4SAVE_PROPS_PLAYER_LOCATION],
        &save->propAddresses[FO4SAVE_PROPS_PLAYER_PLAYTIME],
        &save->propAddresses[FO4SAVE_PROPS_PLAYER_RACE],
        &save->propAddresses[FO4SAVE_PROPS_PLAYER_SEX],
        &save->propAddresses[FO4SAVE_PROPS_PLAYER_CURRENT_XP],
        &save->propAddresses[FO4SAVE_PROPS_PLAYER_REQUIRED_XP],
        &save->propAddresses[FO4SAVE_PROPS_SNAPSHOT_WIDTH],
        &save->propAddresses[FO4SAVE_PROPS_SNAPSHOT_HEIGHT]
    };

    for (long unsigned int i = 0; i < FO4SAVE_PROPS_COUNT - 1; i++)
    {
        printf("%-18s : %016lu %04lX\n", propNames[i], *propAddresses[i], *propAddresses[i]);
    }

    return true;
}

bool printFO4SaveSnapshot(
    FO4SAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    for (long unsigned int i = 0; i < save->snapshotLength; i += FO4SAVE_SNAPSHOT_COLOR_BYTES)
    {
        printf("R : %03u", save->snapshot[i + 0]);
        printf("G : %03u", save->snapshot[i + 1]);
        printf("B : %03u", save->snapshot[i + 2]);
        printf("A : %03u", save->snapshot[i + 3]);

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
