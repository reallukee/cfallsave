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

#define FONVSAVE_SIGNATURE          "FO3SAVEGAME"
#define FONVSAVE_SIGNATURE_LENGTH   11

typedef struct FONVSAVE
{
    char saveSignature[FONVSAVE_SIGNATURE_LENGTH + 1];
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
} FONVSAVE;

#define FONVSAVE_SIZE sizeof(FONVSAVE)



CFALLSAVE_API FONVSAVE* readFONVSave(
    const char* saveName
);

CFALLSAVE_API bool isFONVSave(
    const char* saveName
);

CFALLSAVE_API void printFONVSave(
    FONVSAVE* save
);

CFALLSAVE_API void printFONVSaveSnapshot(
    FONVSAVE* save
);

CFALLSAVE_API void closeFONVSave(
    FONVSAVE* save
);

#endif // !CFALLSAVE_FONV_H
