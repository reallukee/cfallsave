/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo3.h
 *
 * Title       : FALLOUT 3 HEADER
 * Description : Fallout 3 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FO3_H
#define CFALLSAVE_FO3_H

#include "header.h"

#define FO3SAVE_GAME_NAME           "Fallout 3"
#define FO3SAVE_SIGNATURE           "FO3SAVEGAME"
#define FO3SAVE_SIGNATURE_LENGTH    11
#define FO3SAVE_PROPS_COUNT         11

typedef enum FO3SAVE_PROPS
{
    FO3SAVE_PROPS_SAVE_SIGNATURE    = 0,
    FO3SAVE_PROPS_ENGINE_VERSION    = 1,
    FO3SAVE_PROPS_SAVE_NUMBER       = 2,
    FO3SAVE_PROPS_PLAYER_NAME       = 3,
    FO3SAVE_PROPS_PLAYER_LEVEL      = 4,
    FO3SAVE_PROPS_PLAYER_TITLE      = 5,
    FO3SAVE_PROPS_PLAYER_LOCATION   = 6,
    FO3SAVE_PROPS_PLAYER_PLAYTIME   = 7,
    FO3SAVE_PROPS_SNAPSHOT_WIDTH    = 8,
    FO3SAVE_PROPS_SNAPSHOT_HEIGHT   = 9,
    FO3SAVE_PROPS_SNAPHOST          = 10
} FO3SAVE_PROPS;

#define FO3SAVE_MAX_SNAPSHOT_WIDTH      512
#define FO3SAVE_MAX_SNAPSHOT_HEIGHT     288
#define FO3SAVE_MAX_SNAPSHOT_LENGTH     442368

#define FO3SAVE_SNAPSHOT_COLOR_BYTES    3

typedef struct FO3SAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FO3SAVE_SIGNATURE_LENGTH + 1];
    unsigned int engineVersion;
    unsigned int saveNumber;

    char* playerName;
    unsigned int playerLevel;
    char* playerTitle;
    char* playerLocation;
    char* playerPlaytime;

    unsigned int snapshotWidth;
    unsigned int snapshotHeight;
    unsigned long snapshotLength;
    unsigned char* snapshot;

    unsigned long propAddresses[FO3SAVE_PROPS_COUNT];
} FO3SAVE;

#define FO3SAVE_PROPS_SIZE  sizeof(FO3SAVE_PROPS)
#define FO3SAVE_SIZE        sizeof(FO3SAVE)



CFALLSAVE_API FO3SAVE* readFO3Save(
    const char* saveName
);

CFALLSAVE_API bool writeFO3Save(
    FO3SAVE* save,
    char* saveName
);

CFALLSAVE_API bool isFO3Save(
    const char* saveName
);

CFALLSAVE_API void closeFO3Save(
    FO3SAVE* save
);



CFALLSAVE_API bool readFO3SaveProperty(
    FO3SAVE* save,
    FO3SAVE_PROPS property,
    void** value
);

CFALLSAVE_API bool writeFO3SaveProperty(
    FO3SAVE* save,
    FO3SAVE_PROPS property,
    void* value
);



CFALLSAVE_API bool printFO3Save(
    FO3SAVE* save
);

CFALLSAVE_API bool printFO3SaveProps(
    FO3SAVE* save
);

CFALLSAVE_API bool printFO3SavePropAddresses(
    FO3SAVE* save
);

CFALLSAVE_API bool printFO3SaveSnapshot(
    FO3SAVE* save
);

#endif // !CFALLSAVE_FO3_H
