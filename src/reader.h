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

#ifndef CFALLSAVE_READER_H
#define CFALLSAVE_READER_H

#include "header.h"

bool readFixedString(
    FILE* file,
    char* property,
    int length,
    unsigned long* address,
    unsigned long skip
);

bool readString(
    FILE* file,
    char** property,
    unsigned long* address,
    unsigned long skipLength,
    unsigned long skipString
);



bool readUByte(
    FILE* file,
    unsigned short* property,
    unsigned long* address,
    unsigned long skip
);

bool readUShort(
    FILE* file,
    unsigned short* property,
    unsigned long* address,
    unsigned long skip
);

bool readUInt(
    FILE* file,
    unsigned* property,
    unsigned long* address,
    unsigned long skip
);

bool readULong(
    FILE* file,
    unsigned long* property,
    unsigned long* address,
    unsigned long skip
);

bool readFloat(
    FILE* file,
    float* property,
    unsigned long* address,
    unsigned long skip
);



bool readUByteArray(
    FILE* file,
    unsigned char* property,
    int length,
    unsigned long* address,
    unsigned long skip
);

#endif // !CFALLSAVE_READER_H
