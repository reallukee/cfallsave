/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
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

bool writeFixedString(
    FILE* source,
    char* value,
    unsigned long length,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

bool writeString(
    FILE* source,
    char** value,
    unsigned long* address,
    unsigned long skipLength,
    unsigned long skipString,
    bool updateAddress
);

bool writeCURSEDString(
    FILE* source,
    char** value,
    unsigned long* address,
    unsigned long skipLength,
    unsigned long skipString,
    bool updateAddress
);



bool writeUByte(
    FILE* source,
    unsigned char value,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

bool writeUShort(
    FILE* source,
    unsigned short value,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

bool writeUInt(
    FILE* source,
    unsigned int value,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

bool writeULong(
    FILE* source,
    unsigned long value,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

bool writeFloat(
    FILE* source,
    float value,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);



bool writeUByteArray(
    FILE* source,
    unsigned char* value,
    unsigned long length,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
);

#endif // !CFALLSAVE_WRITER_H
