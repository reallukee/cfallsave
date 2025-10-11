/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fotbos.c
 *
 * Title       : FALLOUT TACTICS: BROTHERHOOD OF STEEL SOURCE
 * Description : Fallout Tactics: Brotherhood of Steel Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.2.0
 * License     : MIT
 */

#include "fotbos.h"
#include "reader.h"
#include "writer.h"

FOTBOSSAVE* readFOTBOSSave(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return NULL;
    }

    FOTBOSSAVE* save = (FOTBOSSAVE*)calloc(1, FOTBOSSAVE_SIZE);

    if (save == NULL)
    {
        return NULL;
    }

    save->save = fopen(saveName, "rb+");

    if (save->save == NULL)
    {
        closeFOTBOSSave(save);

        return NULL;
    }

    save->saveFileName = strdup(saveName);

    if (save->saveFileName == NULL)
    {
        closeFOTBOSSave(save);

        return NULL;
    }

    long unsigned int address = 0;
    bool fail = false;

    save->propAddresses[FOTBOSSAVE_PROPS_SAVE_SIGNATURE] = address;
    fail |= !readFixedString(save->save, save->saveSignature, FOTBOSSAVE_SIGNATURE_LENGTH, &address, 0, true);

    save->propAddresses[FOTBOSSAVE_PROPS_SAVE_NAME] = address + 8;
    fail |= !readCURSEDString(save->save, &save->saveName, &address, 8, 2, true);

    save->propAddresses[FOTBOSSAVE_PROPS_PLAYER_NAME] = address;
    fail |= !readCURSEDString(save->save, &save->playerName, &address, 0, 2, true);

    save->propAddresses[FOTBOSSAVE_PROPS_PLAYER_LOCATION] = address;
    fail |= !readCURSEDString(save->save, &save->playerLocation, &address, 0, 2, true);

    save->propAddresses[FOTBOSSAVE_PROPS_GAME_DATE_TIME] = address;
    fail |= !readCURSEDString(save->save, &save->gameDateTime, &address, 0, 2, true);

    if (fail)
    {
        closeFOTBOSSave(save);

        return NULL;
    }

    return save;
}

bool writeFOTBOSSave(
    FOTBOSSAVE* save
)
{
    if (save == NULL || save->save == NULL)
    {
        return false;
    }

    long unsigned int address = 0;
    bool fail = false;

    save->propAddresses[FOTBOSSAVE_PROPS_SAVE_SIGNATURE] = address;
    fail |= !writeFixedString(save->save, save->saveSignature, FOTBOSSAVE_SIGNATURE_LENGTH, &address, 0, true);

    save->propAddresses[FOTBOSSAVE_PROPS_SAVE_NAME] = address + 8;
    fail |= !writeCURSEDString(save->save, &save->saveName, &address, 8, 2, true);

    save->propAddresses[FOTBOSSAVE_PROPS_PLAYER_NAME] = address;
    fail |= !writeCURSEDString(save->save, &save->playerName, &address, 0, 2, true);

    save->propAddresses[FOTBOSSAVE_PROPS_PLAYER_LOCATION] = address;
    fail |= !writeCURSEDString(save->save, &save->playerLocation, &address, 0, 2, true);

    save->propAddresses[FOTBOSSAVE_PROPS_GAME_DATE_TIME] = address;
    fail |= !writeCURSEDString(save->save, &save->gameDateTime, &address, 0, 2, true);

    fflush(save->save);

    return fail;
}

bool isFOTBOSSave(
    const char* saveName
)
{
    if (saveName == NULL)
    {
        return false;
    }

    FOTBOSSAVE* save = (FOTBOSSAVE*)calloc(1, FOTBOSSAVE_SIZE);

    if (save == NULL)
    {
        return false;
    }

    save->save = fopen(saveName, "rb+");

    if (save->save == NULL)
    {
        closeFOTBOSSave(save);

        return false;
    }

    long unsigned int address = 0;

    readFixedString(save->save, save->saveSignature, FOTBOSSAVE_SIGNATURE_LENGTH, &address, 0, true);

    int r_strcmp = strcmp(save->saveSignature, FOTBOSSAVE_SIGNATURE);

    closeFOTBOSSave(save);

    return r_strcmp == 0;
}

bool isFOTBOSSaveOpen(
    FOTBOSSAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    return save->save != NULL;
}

void closeFOTBOSSave(
    FOTBOSSAVE* save
)
{
    if (save != NULL)
    {
        if (save->save != NULL)
        {
            fclose(save->save);
        }

        free(save->saveFileName);

        free(save->saveName);
        free(save->playerName);
        free(save->playerLocation);
        free(save->gameDateTime);

        free(save);
    }
}



bool getFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
    void** destination
)
{
    if (save == NULL || destination == NULL)
    {
        return false;
    }

    switch (prop)
    {
    case FOTBOSSAVE_PROPS_SAVE_SIGNATURE:
        strcpy((char*)destination, save->saveSignature);
        break;

    case FOTBOSSAVE_PROPS_SAVE_NAME:
        *destination = strdup(save->saveName);
        break;

    case FOTBOSSAVE_PROPS_PLAYER_NAME:
        *destination = strdup(save->playerName);
        break;

    case FOTBOSSAVE_PROPS_PLAYER_LOCATION:
        *destination = strdup(save->playerLocation);
        break;

    case FOTBOSSAVE_PROPS_GAME_DATE_TIME:
        *destination = strdup(save->gameDateTime);
        break;

    default:
        break;
    }

    return true;
}

bool setFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
    void** value
)
{
    if (save == NULL || value == NULL)
    {
        return false;
    }

    switch (prop)
    {
    case FOTBOSSAVE_PROPS_SAVE_SIGNATURE:
        strcpy(save->saveSignature, (char*)value);
        break;

    case FOTBOSSAVE_PROPS_SAVE_NAME:
        save->saveName = strdup(*(char**)value);
        break;

    case FOTBOSSAVE_PROPS_PLAYER_NAME:
        save->playerName = strdup(*(char**)value);
        break;

    case FOTBOSSAVE_PROPS_PLAYER_LOCATION:
        save->playerLocation = strdup(*(char**)value);
        break;

    case FOTBOSSAVE_PROPS_GAME_DATE_TIME:
        save->gameDateTime = strdup(*(char**)value);
        break;

    default:
        break;
    }

    return true;
}



bool readFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
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
    case FOTBOSSAVE_PROPS_SAVE_SIGNATURE:
        result = readFixedString(save->save, (char*)destination, FOTBOSSAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FOTBOSSAVE_PROPS_SAVE_NAME:
    case FOTBOSSAVE_PROPS_PLAYER_NAME:
    case FOTBOSSAVE_PROPS_PLAYER_LOCATION:
    case FOTBOSSAVE_PROPS_GAME_DATE_TIME:
        result = readCURSEDString(save->save, (char**)destination, &save->propAddresses[prop], 0, 2, false);
        break;

    default:
        break;
    }

    return result;
}

bool writeFOTBOSSaveProp(
    FOTBOSSAVE* save,
    FOTBOSSAVE_PROPS prop,
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
    case FOTBOSSAVE_PROPS_SAVE_SIGNATURE:
        result = writeFixedString(save->save, (char*)value, FOTBOSSAVE_SIGNATURE_LENGTH, &save->propAddresses[prop], 0, false);
        break;

    case FOTBOSSAVE_PROPS_SAVE_NAME:
    case FOTBOSSAVE_PROPS_PLAYER_NAME:
    case FOTBOSSAVE_PROPS_PLAYER_LOCATION:
    case FOTBOSSAVE_PROPS_GAME_DATE_TIME:
        result = writeCURSEDString(save->save, (char**)value, &save->propAddresses[prop], 0, 2, false);
        break;

    default:
        break;
    }

    return result;
}



bool printFOTBOSSave(
    FOTBOSSAVE* save
)
{
    if (save == NULL)
    {
        printf("**************\n");
        printf("* FOTBOSSAVE *\n");
        printf("**************\n");

        printf("\n");

        printf("/!\\ SAVE NOT OPEN /!\\\n");

        return false;
    }

    bool fail = false;

    fail |= printFOTBOSSaveProps(save);

    printf("\n");

    fail |= printFOTBOSSavePropAddresses(save);

    return fail;
}

bool printFOTBOSSaveProps(
    FOTBOSSAVE* save
)
{
    printf("********************\n");
    printf("* FOTBOSSAVE PROPS *\n");
    printf("********************\n");

    printf("\n");

    if (save == NULL)
    {
        printf("/!\\ SAVE NOT OPEN /!\\\n");

        return false;
    }

    printf("Game Name       : %s\n", FOTBOSSAVE_GAME_NAME);
    printf("Save File Name  : %s\n", save->saveFileName);

    printf("\n");

    printf("Save Signature  : %s\n", save->saveSignature);
    printf("Save Name       : %s\n", save->saveName);
    printf("Player Name     : %s\n", save->playerName);
    printf("Player Location : %s\n", save->playerLocation);
    printf("Game Date Time  : %s\n", save->gameDateTime);

    return true;
}

bool printFOTBOSSavePropAddresses(
    FOTBOSSAVE* save
)
{
    printf("*****************************\n");
    printf("* FOTBOSSAVE PROP ADDRESSES *\n");
    printf("*****************************\n");

    printf("\n");

    if (save == NULL)
    {
        printf("/!\\ SAVE NOT OPEN /!\\\n");

        return false;
    }

    printf("%-15s : %s\n", "Save File Name", save->saveName);

    printf("\n");

    const char* propNames[] = {
        "Save Signature",
        "Save Name",
        "Player Name",
        "Player Location",
        "Game Date Time",
    };

    long unsigned int* propAddresses[FOTBOSSAVE_PROPS_COUNT] = {
        &save->propAddresses[FOTBOSSAVE_PROPS_SAVE_SIGNATURE],
        &save->propAddresses[FOTBOSSAVE_PROPS_SAVE_NAME],
        &save->propAddresses[FOTBOSSAVE_PROPS_PLAYER_NAME],
        &save->propAddresses[FOTBOSSAVE_PROPS_PLAYER_LOCATION],
        &save->propAddresses[FOTBOSSAVE_PROPS_GAME_DATE_TIME]
    };

    for (long unsigned int i = 0; i < FOTBOSSAVE_PROPS_COUNT; i++)
    {
        printf("%-15s : %016lu %04lX\n", propNames[i], *propAddresses[i], *propAddresses[i]);
    }

    return true;
}
