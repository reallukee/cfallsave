/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fotbos.h
 *
 * Title       : FALLOUT TACTICS: BROTHERHOOD OF STEEL HEADER
 * Description : Fallout Tactics: Brotherhood of Steel Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FOTBOS_H
#define CFALLSAVE_FOTBOS_H

#include "header.h"

#define FOTBOS_SAVE_SIGNATURE           "<saveh>"
#define FOTBOS_SAVE_SIGNATURE_LENGTH    7

typedef struct FOTBOSSAVE
{
    char saveSignature[FOTBOS_SAVE_SIGNATURE_LENGTH + 1];
    char* saveName;

    char* playerName;
    char* playerLocation;
    char* gameDateTime;
} FOTBOSSAVE;

#define FOTBOSSAVE_SIZE sizeof(FOTBOSSAVE)



CFALLSAVE_API FOTBOSSAVE* readFOTBOSSave(
    const char* saveName
);

CFALLSAVE_API bool isFOTBOSSave(
    const char* saveName
);

CFALLSAVE_API void printFOTBOSSave(
    FOTBOSSAVE* save
);

CFALLSAVE_API void closeFOTBOSSave(
    FOTBOSSAVE* save
);

#endif // !CFALLSAVE_FOTBOS_H
