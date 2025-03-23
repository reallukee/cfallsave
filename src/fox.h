/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fox.h
 *
 * Title       : FALLOUT X HEADER
 * Description : Fallout X Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_FOX_H
#define CFALLSAVE_FOX_H

#include "header.h"

#include "fo1.h"
#include "fo2.h"
#include "fotbos.h"
#include "fo3.h"
#include "fonv.h"
#include "fo4.h"

typedef enum FOXSAVE_TYPE
{
    FOXSAVE_TYPE_FO1,
    FOXSAVE_TYPE_FO2,
    FOXSAVE_TYPE_FOTBOS,
    FOXSAVE_TYPE_FO3,
    FOXSAVE_TYPE_FONV,
    FOXSAVE_TYPE_FO4
} FOXSAVE_TYPE;

typedef struct FOXSAVE
{
    FOXSAVE_TYPE saveType;

    void* save;
} FOXSAVE;

#define FOXSAVE_TYPE_SIZE   sizeof(FOXSAVE_TYPE)
#define FOXSAVE_SIZE        sizeof(FOXSAVE)



CFALLSAVE_API FOXSAVE* readFOXSave(
    const char* saveName
);

CFALLSAVE_API bool writeFOXSave(
    FOXSAVE* save
);

CFALLSAVE_API bool isFOXSaveOpen(
    FOXSAVE* save
);

CFALLSAVE_API void closeFOXSave(
    FOXSAVE* save
);



CFALLSAVE_API bool printFOXSave(
    FOXSAVE* save
);

CFALLSAVE_API bool printFOXSaveProps(
    FOXSAVE* save
);

CFALLSAVE_API bool printFOXSavePropAddresses(
    FOXSAVE* save
);

CFALLSAVE_API bool printFOXSaveSnapshot(
    FOXSAVE* save
);

#endif // !CFALLSAVE_FOX_H
