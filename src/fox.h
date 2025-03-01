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

#ifndef CFALLSAVE_FOX_H
#define CFALLSAVE_FOX_H

#include "header.h"

#include "fo1.h"
#include "fo2.h"
#include "fo3.h"
#include "fonv.h"
#include "fo4.h"

typedef enum
{
    FOXSAVE_TYPE_FO1,
    FOXSAVE_TYPE_FO2,
    FOXSAVE_TYPE_FO3,
    FOXSAVE_TYPE_FONV,
    FOXSAVE_TYPE_FO4
} FOXSAVE_TYPE;



typedef struct
{
    FOXSAVE_TYPE saveType;

    void* save;
} FOXSAVE;

#define FOXSAVE_SIZE sizeof(FOXSAVE)



CFALLSAVE_API FOXSAVE* readFOXSave(
    const char* saveName
);

CFALLSAVE_API void printFOXSave(
    FOXSAVE* save
);

CFALLSAVE_API void closeFOXSave(
    FOXSAVE* save
);

#endif // !CFALLSAVE_FOX_H
