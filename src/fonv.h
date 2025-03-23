/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fonv.h
 *
 * Title       : FALLOUT: NEW VEGAS HEADER
 * Description : Fallout: New Vegas Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FONV_H
#define CFALLSAVE_FONV_H

#include "header.h"

#define FONVSAVE_GAME_NAME          "Fallout: New Vegas"
#define FONVSAVE_SIGNATURE          "FO3SAVEGAME"
#define FONVSAVE_SIGNATURE_LENGTH   11
#define FONVSAVE_PROPS_COUNT        11
#define FONVSAVE_SAVE_STANDARD_EXT  ".fos"

typedef enum FONVSAVE_PROPS
{
    FONVSAVE_PROPS_SAVE_SIGNATURE   = 0,
    FONVSAVE_PROPS_ENGINE_VERSION   = 1,
    FONVSAVE_PROPS_SAVE_NUMBER      = 2,
    FONVSAVE_PROPS_PLAYER_NAME      = 3,
    FONVSAVE_PROPS_PLAYER_LEVEL     = 4,
    FONVSAVE_PROPS_PLAYER_TITLE     = 5,
    FONVSAVE_PROPS_PLAYER_LOCATION  = 6,
    FONVSAVE_PROPS_PLAYER_PLAYTIME  = 7,
    FONVSAVE_PROPS_SNAPSHOT_WIDTH   = 8,
    FONVSAVE_PROPS_SNAPSHOT_HEIGHT  = 9,
    FONVSAVE_PROPS_SNAPSHOT         = 10
} FONVSAVE_PROPS;

#define FONVSAVE_MAX_SNAPSHOT_WIDTH     512
#define FONVSAVE_MAX_SNAPSHOT_HEIGHT    288
#define FONVSAVE_MAX_SNAPSHOT_LENGTH    442368

#define FONVSAVE_SNAPSHOT_COLOR_BYTES   3

typedef struct FONVSAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FONVSAVE_SIGNATURE_LENGTH + 1];
    unsigned int engineVersion;
    unsigned int saveNumber;

    char* playerName;
    unsigned int playerLevel;
    char* playerTitle;
    char* playerLocation;
    char* playerPlaytime;

    unsigned int snapshotWidth;
    unsigned int snapshotHeight;
    long unsigned int snapshotLength;
    unsigned char* snapshot;

    long unsigned int propAddresses[FONVSAVE_PROPS_COUNT];
} FONVSAVE;

#define FONVSAVE_PROPS_SIZE sizeof(FONVSAVE_PROPS)
#define FONVSAVE_SIZE       sizeof(FONVSAVE)



CFALLSAVE_API FONVSAVE* readFONVSave(
    const char* saveName
);

CFALLSAVE_API bool writeFONVSave(
    FONVSAVE* save
);

CFALLSAVE_API bool isFONVSave(
    const char* saveName
);

CFALLSAVE_API bool isFONVSaveOpen(
    FONVSAVE* save
);

CFALLSAVE_API void closeFONVSave(
    FONVSAVE* save
);



CFALLSAVE_API bool getFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
    void** destination
);

CFALLSAVE_API bool setFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
    void** value
);



CFALLSAVE_API bool readFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
    void** destination
);

CFALLSAVE_API bool writeFONVSaveProp(
    FONVSAVE* save,
    FONVSAVE_PROPS prop,
    void** value
);



CFALLSAVE_API bool printFONVSave(
    FONVSAVE* save
);

CFALLSAVE_API bool printFONVSaveProps(
    FONVSAVE* save
);

CFALLSAVE_API bool printFONVSavePropAddresses(
    FONVSAVE* save
);

CFALLSAVE_API bool printFONVSaveSnapshot(
    FONVSAVE* save
);

#endif // !CFALLSAVE_FONV_H
