/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo4.h
 *
 * Title       : FALLOUT 4 HEADER
 * Description : Fallout 4 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FO4_H
#define CFALLSAVE_FO4_H

#include "header.h"

#define FO4SAVE_GAME_NAME           "Fallout 4"
#define FO4SAVE_SIGNATURE           "FO4_SAVEGAME"
#define FO4SAVE_SIGNATURE_LENGTH    12
#define FO4SAVE_PROPS_COUNT         14

typedef enum FO4SAVE_PROPS
{
    FO4SAVE_PROPS_SAVE_SIGNATURE        = 0,
    FO4SAVE_PROPS_ENGINE_VERSION        = 1,
    FO4SAVE_PROPS_SAVE_NUMBER           = 2,
    FO4SAVE_PROPS_PLAYER_NAME           = 3,
    FO4SAVE_PROPS_PLAYER_LEVEL          = 4,
    FO4SAVE_PROPS_PLAYER_LOCATION       = 5,
    FO4SAVE_PROPS_PLAYER_PLAYTIME       = 6,
    FO4SAVE_PROPS_PLAYER_RACE           = 7,
    FO4SAVE_PROPS_PLAYER_SEX            = 8,
    FO4SAVE_PROPS_PLAYER_CURRENT_XP     = 9,
    FO4SAVE_PROPS_PLAYER_REQUIRED_XP    = 10,
    FO4SAVE_PROPS_SNAPSHOT_WIDTH        = 11,
    FO4SAVE_PROPS_SNAPSHOT_HEIGHT       = 12,
    FO4SAVE_PROPS_SNAPSHOT              = 13
} FO4SAVE_PROPS;

#define FO4SAVE_MAX_SNAPSHOT_WIDTH      640
#define FO4SAVE_MAX_SNAPSHOT_HEIGHT     384
#define FO4SAVE_MAX_SNAPSHOT_LENGTH     983040

#define FO4SAVE_SNAPSHOT_COLOR_BYTES    4

typedef struct FO4SAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FO4SAVE_SIGNATURE_LENGTH + 1];
    unsigned int engineVersion;
    unsigned int saveNumber;

    char* playerName;
    unsigned int playerLevel;
    char* playerLocation;
    char* playerPlaytime;
    char* playerRace;
    unsigned short playerSex;
    float playerCurrentXp;
    float playerRequiredXp;

    unsigned int snapshotWidth;
    unsigned int snapshotHeight;
    unsigned long snapshotLength;
    unsigned char* snapshot;

    unsigned long propAddresses[FO4SAVE_PROPS_COUNT];
} FO4SAVE;

#define FO4SAVE_PROPS_SIZE  sizeof(FO4SAVE_FIELDS)
#define FO4SAVE_SIZE        sizeof(FO4SAVE)



CFALLSAVE_API FO4SAVE* readFO4Save(
    const char* saveName
);

CFALLSAVE_API bool writeFO4Save(
    FO4SAVE* save,
    char* saveName
);

CFALLSAVE_API bool isFO4Save(
    const char* saveName
);

CFALLSAVE_API void closeFO4Save(
    FO4SAVE* save
);



CFALLSAVE_API bool readFO4SaveProperty(
    FO4SAVE* save,
    FO4SAVE_PROPS property,
    void** value
);

CFALLSAVE_API bool writeFO4SaveProperty(
    FO4SAVE* save,
    FO4SAVE_PROPS property,
    void* value
);



CFALLSAVE_API bool printFO4Save(
    FO4SAVE* save
);

CFALLSAVE_API bool printFO4SaveProps(
    FO4SAVE* save
);

CFALLSAVE_API bool printFO4SavePropAddresses(
    FO4SAVE* save
);

CFALLSAVE_API bool printFO4SaveSnapshot(
    FO4SAVE* save
);

#endif  // !CFALLSAVE_FO4_H
