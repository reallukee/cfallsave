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

#define FO4SAVE_SIGNATURE           "FO4_SAVEGAME"
#define FO4SAVE_SIGNATURE_LENGTH    12

typedef struct FO4SAVE
{
    char saveSignature[FO4SAVE_SIGNATURE_LENGTH + 1];
    unsigned engineVersion;
    unsigned saveNumber;

    char* playerName;
    unsigned playerLevel;
    char* playerLocation;
    char* playerPlaytime;
    char* playerRace;
    unsigned short playerSex;
    float playerCurrentXp;
    float playerRequiredXp;

    unsigned snapshotWidth;
    unsigned snapshotHeight;
    unsigned char* snapshot;
} FO4SAVE;

#define FO4SAVE_SIZE sizeof(FO4SAVE)



CFALLSAVE_API FO4SAVE* readFO4Save(
    const char* saveName
);

CFALLSAVE_API bool isFO4Save(
    const char* saveName
);

CFALLSAVE_API void printFO4Save(
    FO4SAVE* save
);

CFALLSAVE_API void printFO4SaveSnapshot(
    FO4SAVE* save
);

CFALLSAVE_API void closeFO4Save(
    FO4SAVE* save
);

#endif  // !CFALLSAVE_FO4_H
