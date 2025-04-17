/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : reader.h
 *
 * Title       : READER HEADER
 * Description : Questo file contiene le definizioni dei
 *               metodi che permettono la manipolazione
 *               in lettura dei dati presenti all'interno
 *               di un file binario.
 *               Le implementazioni sono all'interno del
 *               file sorgente "reader.c".
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
    char* value,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

bool readString(
    FILE* source,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
);

bool readCURSEDString(
    FILE* source,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
);



bool readUByte(
    FILE* source,
    unsigned char* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

bool readUShort(
    FILE* source,
    short unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

bool readUInt(
    FILE* source,
    unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

bool readULong(
    FILE* source,
    long unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

bool readFloat(
    FILE* source,
    float* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);



bool readUByteArray(
    FILE* source,
    unsigned char* value,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

#endif // !CFALLSAVE_READER_H
