/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : writer.c
 *
 * Title       : WRITER HEADER
 * Description : Writer Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_WRITER_H
#define CFALLSAVE_WRITER_H

#include "header.h"

CFALLSAVE_API bool writeFixedString(
    FILE* source,
    char* value,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

CFALLSAVE_API bool writeString(
    FILE* source,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
);

CFALLSAVE_API bool writeCURSEDString(
    FILE* source,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
);



CFALLSAVE_API bool writeUByte(
    FILE* source,
    unsigned char* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

CFALLSAVE_API bool writeUShort(
    FILE* source,
    short unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

CFALLSAVE_API bool writeUInt(
    FILE* source,
    unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

CFALLSAVE_API bool writeULong(
    FILE* source,
    long unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

CFALLSAVE_API bool writeFloat(
    FILE* source,
    float* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);



CFALLSAVE_API bool writeUByteArray(
    FILE* source,
    unsigned char* value,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

#endif // !CFALLSAVE_WRITER_H
