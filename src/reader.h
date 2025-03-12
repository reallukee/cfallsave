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

bool readFixedString(
    FILE* source,
    char* destination,
    unsigned long length,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

bool readString(
    FILE* source,
    char** destination,
    unsigned long* address,
    unsigned long skipLength,
    unsigned long skipString,
    bool updateAddress
);

bool readCURSEDString(
    FILE* source,
    char** destination,
    unsigned long* address,
    unsigned long skipLength,
    unsigned long skipString,
    bool updateAddress
);



bool readUByte(
    FILE* source,
    unsigned char* destination,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

bool readUShort(
    FILE* source,
    unsigned short* destination,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

bool readUInt(
    FILE* source,
    unsigned int* destination,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

bool readULong(
    FILE* source,
    unsigned long* destination,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

bool readFloat(
    FILE* source,
    float* destination,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);



bool readUByteArray(
    FILE* source,
    unsigned char* destination,
    unsigned long length,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

#endif // !CFALLSAVE_READER_H
