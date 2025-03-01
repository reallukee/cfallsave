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

#ifndef CFALLSAVE_FO1_H
#define CFALLSAVE_FO1_H

#include "header.h"

#define FO1_SAVE_SIGNATURE         "FALLOUT SAVE FILE"
#define FO1_SAVE_SIGNATURE_LENGTH  17

typedef struct
{
    char saveSignature[FO1_SAVE_SIGNATURE_LENGTH + 1];
    char saveName[32];

    char playerName[32];
} FO1SAVE;

#define FO1SAVE_SIZE sizeof(FO1SAVE)



CFALLSAVE_API FO1SAVE* readFO1Save(
    const char* saveName
);

CFALLSAVE_API bool isFO1Save(
    const char* saveName
);

CFALLSAVE_API void printFO1Save(
    FO1SAVE* save
);

CFALLSAVE_API void closeFO1Save(
    FO1SAVE* save
);

#endif  // !CFALLSAVE_FO1_H
