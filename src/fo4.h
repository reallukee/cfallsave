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

#ifndef CFALLSAVE_FO4_H
#define CFALLSAVE_FO4_H

#include "header.h"

#define FO4_SAVE_SIGNATURE          "FO4_SAVEGAME"
#define FO4_SAVE_SIGNATURE_LENGTH   12

typedef struct
{
    char saveSignature[FO4_SAVE_SIGNATURE_LENGTH + 1];
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

CFALLSAVE_API void closeFO4Save(
    FO4SAVE* save
);

#endif  // !CFALLSAVE_FO4_H
