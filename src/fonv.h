/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * Author  : Reallukee
 * Version : 1.0
 * License : MIT
 */

#ifndef CFALLSAVE_FONV_H
#define CFALLSAVE_FONV_H

#include "header.h"

#define FONV_SAVE_SIGNATURE          "FO3SAVEGAME"
#define FONV_SAVE_SIGNATURE_LENGTH   11

typedef struct
{
    char saveSignature[12];
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

CFALLSAVE_API void closeFONVSave(
    FONVSAVE* save
);

#endif // !CFALLSAVE_FONV_H
