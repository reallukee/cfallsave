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

#ifndef CFALLSAVE_FO2_H
#define CFALLSAVE_FO2_H

#include "header.h"

#define FO2_SAVE_SIGNATURE         "FALLOUT SAVE FILE"
#define FO2_SAVE_SIGNATURE_LENGTH  17

typedef struct
{
    char saveSignature[FO2_SAVE_SIGNATURE_LENGTH + 1];
    char saveName[32];

    char playerName[32];
} FO2SAVE;

#define FO2SAVE_SIZE sizeof(FO2SAVE)



CFALLSAVE_API FO2SAVE* readFO2Save(
    const char* saveName
);

CFALLSAVE_API bool isFO2Save(
    const char* saveName
);

CFALLSAVE_API void printFO2Save(
    FO2SAVE* save
);

CFALLSAVE_API void closeFO2Save(
    FO2SAVE* save
);

#endif  // !CFALLSAVE_FO2_H
