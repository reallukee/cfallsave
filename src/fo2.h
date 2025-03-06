/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo2.h
 *
 * Title       : FALLOUT 2 HEADER
 * Description : Fallout 2 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FO2_H
#define CFALLSAVE_FO2_H

#include "header.h"

#define FO2SAVE_SIGNATURE           "FALLOUT SAVE FILE"
#define FO2SAVE_SIGNATURE_LENGTH    17

typedef struct FO2SAVE
{
    char saveSignature[FO2SAVE_SIGNATURE_LENGTH + 1];
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
