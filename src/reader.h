/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : reader.h
 *
 * Title       : READER HEADER
 * Description : Reader Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_READER_H
#define CFALLSAVE_READER_H

#include "header.h"

CFALLSAVE_API bool readFixedString(
    FILE* source,
    char* destination,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

CFALLSAVE_API bool readString(
    FILE* source,
    char** destination,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
);

CFALLSAVE_API bool readCURSEDString(
    FILE* source,
    char** destination,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
);



CFALLSAVE_API bool readUByte(
    FILE* source,
    unsigned char* destination,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

CFALLSAVE_API bool readUShort(
    FILE* source,
    short unsigned int* destination,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

CFALLSAVE_API bool readUInt(
    FILE* source,
    unsigned int* destination,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

CFALLSAVE_API bool readULong(
    FILE* source,
    long unsigned int* destination,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

CFALLSAVE_API bool readFloat(
    FILE* source,
    float* destination,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);



CFALLSAVE_API bool readUByteArray(
    FILE* source,
    unsigned char* destination,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

#endif // !CFALLSAVE_READER_H
