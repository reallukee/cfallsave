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

#define FO3SAVE_SIGNATURE           "FO3SAVEGAME"
#define FO3SAVE_SIGNATURE_LENGTH    11

typedef struct FO3SAVE
{
    char saveSignature[FO3SAVE_SIGNATURE_LENGTH + 1];
    unsigned engineVersion;
    unsigned saveNumber;

    char* playerName;
    unsigned playerLevel;
    char* playerTitle;
    char* playerLocation;
    char* playerPlaytime;

    unsigned snapshotWidth;
    unsigned snapshotHeight;
    unsigned char* snapshot;
} FO3SAVE;

#define FO3SAVE_SIZE sizeof(FO3SAVE)



CFALLSAVE_API FO3SAVE* readFO3Save(
    const char* saveName
);

CFALLSAVE_API bool isFO3Save(
    const char* saveName
);

CFALLSAVE_API void printFO3Save(
    FO3SAVE* save
);

CFALLSAVE_API void printFO3SaveSnapshot(
    FO3SAVE* save
);

CFALLSAVE_API void closeFO3Save(
    FO3SAVE* save
);

#endif // !CFALLSAVE_FO3_H
