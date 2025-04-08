/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : fonv.c
 *
 * Title       : FALLOUT: NEW VEGAS SOURCE
 * Description : Fallout: New Vegas Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fonv.h"
#include "reader.h"
#include "writer.h"

FONVSAVE* readFONVSave(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return NULL;
    }

    FONVSAVE* save = (FONVSAVE*)malloc(FONVSAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    save->save = fopen(saveName, "r+w+b");

    if (save->save == NULL)
    {
        closeFONVSave(save);

        return NULL;
    }

    save->saveFileName = (char*)malloc(strlen(saveName) + 1);

    if (save->saveFileName == NULL)
    {
        closeFONVSave(save);

        return NULL;
    }

    strcpy(save->saveFileName, saveName);

    long unsigned int address = 0;
    bool fail = false;

    save->propAddresses[FONVSAVE_PROPS_SAVE_SIGNATURE] = address;
    fail |= !readFixedString(save->save, save->saveSignature, FONVSAVE_SIGNATURE_LENGTH, &address, 0, true);

    save->propAddresses[FONVSAVE_PROPS_ENGINE_VERSION] = address + 4;
    fail |= !readUInt(save->save, &save->engineVersion, &address, 4, true);

    save->propAddresses[FONVSAVE_PROPS_SNAPSHOT_WIDTH] = address + 66;
    fail |= !readUInt(save->save, &save->snapshotWidth, &address, 66, true);

    save->propAddresses[FONVSAVE_PROPS_SNAPSHOT_HEIGHT] = address + 1;
    fail |= !readUInt(save->save, &save->snapshotHeight, &address, 1, true);

    save->propAddresses[FONVSAVE_PROPS_SAVE_NUMBER] = address + 1;
    fail |= !readUInt(save->save, &save->saveNumber, &address, 1, true);

    save->propAddresses[FONVSAVE_PROPS_PLAYER_NAME] = address + 1;
    fail |= !readString(save->save, &save->playerName, &address, 1, 1, true);

    save->propAddresses[FONVSAVE_PROPS_PLAYER_TITLE] = address + 1;
    fail |= !readString(save->save, &save->playerTitle, &address, 1, 1, true);

    save->propAddresses[FONVSAVE_PROPS_PLAYER_LEVEL] = address + 1;
    fail |= !readUInt(save->save, &save->playerLevel, &address, 1, true);

    save->propAddresses[FONVSAVE_PROPS_PLAYER_LOCATION] = address + 1;
    fail |= !readString(save->save, &save->playerLocation, &address, 1, 1, true);

    save->propAddresses[FONVSAVE_PROPS_PLAYER_PLAYTIME] = address + 1;
    fail |= !readString(save->save, &save->playerPlaytime, &address, 1, 1, true);

    save->snapshotLength = save->snapshotWidth * save->snapshotHeight * FONVSAVE_SNAPSHOT_COLOR_BYTES;

    if (save->snapshotLength == 0 || save->snapshotLength > FONVSAVE_MAX_SNAPSHOT_LENGTH)
    {
        closeFONVSave(save);

        return NULL;
    }

    save->snapshot = (unsigned char*)malloc(save->snapshotLength);

    if (save->snapshot == NULL)
    {
        closeFONVSave(save);

        return NULL;
    }

    save->propAddresses[FONVSAVE_PROPS_SNAPSHOT] = address + 1;
    fail |= !readUByteArray(save->save, save->snapshot, save->snapshotLength, &address, 0, true);

    if (fail)
    {
        closeFONVSave(save);

        return NULL;
    }

    return save;
}

bool writeFONVSave(
    FONVSAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    return true;
}

bool isFONVSave(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return false;
    }

    FONVSAVE* save = (FONVSAVE*)malloc(FONVSAVE_SIZE);

    if (save == NULL)
    {
        return false;
    }

    memset(save, 0, FONVSAVE_SIZE);

    save->save = fopen(saveName, "r+b");

    if (save->save == NULL)
    {
        closeFONVSave(save);

        return false;
    }

    long unsigned int address = 0;

    readFixedString(save->save, save->saveSignature, FONVSAVE_SIGNATURE_LENGTH, &address, 0, true);

    int r_strcmp = strcmp(save->saveSignature, FONVSAVE_SIGNATURE);

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

    closeFONVSave(save);

    return nv != '|';
}

bool isFONVSaveOpen(
    FONVSAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    return save->save != NULL;
}

void closeFONVSave(
    FONVSAVE* save
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



bool getFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
    void** destination
)
{
    if (save == NULL || destination == NULL)
    {
        return false;
    }

    switch (prop)
    {
    case FONVSAVE_PROPS_SAVE_SIGNATURE:
        strcpy((char*)destination, save->saveSignature);
        break;

    case FONVSAVE_PROPS_ENGINE_VERSION:
        *(unsigned int*)destination = save->engineVersion;
        break;

    case FONVSAVE_PROPS_SAVE_NUMBER:
        *(unsigned int*)destination = save->saveNumber;
        break;

    case FONVSAVE_PROPS_PLAYER_NAME:
        *destination = strdup(save->playerName);
        break;

    case FONVSAVE_PROPS_PLAYER_LEVEL:
        *(unsigned int*)destination = save->playerLevel;
        break;

    case FONVSAVE_PROPS_PLAYER_TITLE:
        *destination = strdup(save->playerTitle);
        break;

    case FONVSAVE_PROPS_PLAYER_LOCATION:
        *destination = strdup(save->playerLocation);
        break;

    case FONVSAVE_PROPS_PLAYER_PLAYTIME:
        *destination = strdup(save->playerPlaytime);
        break;

    case FONVSAVE_PROPS_SNAPSHOT_WIDTH:
        *(unsigned int*)destination = save->snapshotWidth;
        break;

    case FONVSAVE_PROPS_SNAPSHOT_HEIGHT:
        *(unsigned int*)destination = save->snapshotHeight;
        break;

    case FONVSAVE_PROPS_SNAPSHOT:
        break;

    default:
        break;
    }

    return false;
}

bool setFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
    void** value
)
{
    if (save == NULL || value == NULL)
    {
        return false;
    }

    switch (prop)
    {
    case FONVSAVE_PROPS_SAVE_SIGNATURE:
        strcpy(save->saveSignature, (char*)value);
        break;

    case FONVSAVE_PROPS_ENGINE_VERSION:
        save->engineVersion = *(unsigned int*)value;
        break;

    case FONVSAVE_PROPS_SAVE_NUMBER:
        save->saveNumber = *(unsigned int*)value;
        break;

    case FONVSAVE_PROPS_PLAYER_NAME:
        save->playerName = strdup(*(char**)value);
        break;

    case FONVSAVE_PROPS_PLAYER_LEVEL:
        save->playerLevel = *(unsigned int*)value;
        break;

    case FONVSAVE_PROPS_PLAYER_TITLE:
        save->playerTitle = strdup(*(char**)value);
        break;

    case FONVSAVE_PROPS_PLAYER_LOCATION:
        save->playerLocation = strdup(*(char**)value);
        break;

    case FONVSAVE_PROPS_PLAYER_PLAYTIME:
        save->playerPlaytime = strdup(*(char**)value);
        break;

    case FONVSAVE_PROPS_SNAPSHOT_WIDTH:
        save->snapshotWidth = *(unsigned int*)value;
        break;

    case FONVSAVE_PROPS_SNAPSHOT_HEIGHT:
        save->snapshotHeight = *(unsigned int*)value;
        break;

    case FONVSAVE_PROPS_SNAPSHOT:
        break;

    default:
        break;
    }

    return false;
}



bool readFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
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
    case FONVSAVE_PROPS_SAVE_SIGNATURE:
        result = readFixedString(save->save, (char*)destination, FONVSAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FONVSAVE_PROPS_ENGINE_VERSION:
    case FONVSAVE_PROPS_SAVE_NUMBER:
    case FONVSAVE_PROPS_PLAYER_LEVEL:
    case FONVSAVE_PROPS_SNAPSHOT_WIDTH:
    case FONVSAVE_PROPS_SNAPSHOT_HEIGHT:
        result = readUInt(save->save, (unsigned int*)destination, &save->propAddresses[prop], 0, false);
        break;

    case FONVSAVE_PROPS_PLAYER_NAME:
    case FONVSAVE_PROPS_PLAYER_TITLE:
    case FONVSAVE_PROPS_PLAYER_LOCATION:
    case FONVSAVE_PROPS_PLAYER_PLAYTIME:
        result = readString(save->save, (char**)destination, &save->propAddresses[prop], 0, 1, false);
        break;

    case FONVSAVE_PROPS_SNAPSHOT:
        result = readUByteArray(save->save, (unsigned char*)destination, save->snapshotLength, &save->propAddresses[prop], 0, false);
        break;

    default:
        break;
    }

    return result;
}

bool writeFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
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
        case FONVSAVE_PROPS_SAVE_SIGNATURE:
        result = writeFixedString(save->save, (char*)value, FONVSAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FONVSAVE_PROPS_ENGINE_VERSION:
    case FONVSAVE_PROPS_SAVE_NUMBER:
    case FONVSAVE_PROPS_PLAYER_LEVEL:
    case FONVSAVE_PROPS_SNAPSHOT_WIDTH:
    case FONVSAVE_PROPS_SNAPSHOT_HEIGHT:
        result = writeUInt(save->save, (unsigned int*)value, &save->propAddresses[prop], 0, false);
        break;

    case FONVSAVE_PROPS_PLAYER_NAME:
    case FONVSAVE_PROPS_PLAYER_TITLE:
    case FONVSAVE_PROPS_PLAYER_LOCATION:
    case FONVSAVE_PROPS_PLAYER_PLAYTIME:
        result = writeString(save->save, (char**)value, &save->propAddresses[prop], 0, 1, false);
        break;

    case FONVSAVE_PROPS_SNAPSHOT:
        result = writeUByteArray(save->save, (unsigned char*)value, save->snapshotLength, &save->propAddresses[prop], 0, false);
        break;

    default:
        break;
    }

    return result;
}



bool printFONVSave(
    FONVSAVE* save
)
{
    bool fail = false;

    fail |= printFONVSaveProps(save);

    printf("\n");

    fail |= printFONVSavePropAddresses(save);

    return fail;
}

bool printFONVSaveProps(
    FONVSAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    printf("******************\n");
    printf("* FONVSAVE PROPS *\n");
    printf("******************\n");

    printf("\n");

    printf("Game Name       : %s\n", FONVSAVE_GAME_NAME);
    printf("Save File Name  : %s\n", save->saveFileName);

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

bool printFONVSavePropAddresses(
    FONVSAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    printf("***************************\n");
    printf("* FONVSAVE PROP ADDRESSES *\n");
    printf("***************************\n");

    printf("\n");

    printf("%-15s : %s\n", "Game Name", FONVSAVE_GAME_NAME);
    printf("%-15s : %s\n", "Save File Name", save->saveFileName);

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

    long unsigned int* propAddresses[FONVSAVE_PROPS_COUNT - 1] = {
        &save->propAddresses[FONVSAVE_PROPS_SAVE_SIGNATURE],
        &save->propAddresses[FONVSAVE_PROPS_ENGINE_VERSION],
        &save->propAddresses[FONVSAVE_PROPS_SAVE_NUMBER],
        &save->propAddresses[FONVSAVE_PROPS_PLAYER_NAME],
        &save->propAddresses[FONVSAVE_PROPS_PLAYER_LEVEL],
        &save->propAddresses[FONVSAVE_PROPS_PLAYER_TITLE],
        &save->propAddresses[FONVSAVE_PROPS_PLAYER_LOCATION],
        &save->propAddresses[FONVSAVE_PROPS_PLAYER_PLAYTIME],
        &save->propAddresses[FONVSAVE_PROPS_SNAPSHOT_WIDTH],
        &save->propAddresses[FONVSAVE_PROPS_SNAPSHOT_HEIGHT]
    };

    for (long unsigned int i = 0; i < FONVSAVE_PROPS_COUNT - 1; i++)
    {
        printf("%-15s : %016lu %04lX\n", propNames[i], *propAddresses[i], *propAddresses[i]);
    }

    return true;
}

bool printFONVSaveSnapshot(
    FONVSAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    for (long unsigned int i = 0; i < save->snapshotLength; i += FONVSAVE_SNAPSHOT_COLOR_BYTES)
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
