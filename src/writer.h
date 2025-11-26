/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : writer.h
 *
 * Title       : WRITER HEADER
 * Description : Questo file contiene le definizioni dei
 *               metodi che permettono la manipolazione
 *               in scrittura dei dati presenti all'interno
 *               di un file binario.
 *               Le implementazioni sono all'interno del
 *               file sorgente "writer.c".
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
    FILE* destination,
    char* value,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

bool writeString(
    FILE* destination,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
);

bool writeCURSEDString(
    FILE* destination,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
);



bool writeUByte(
    FILE* destination,
    unsigned char* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

bool writeUShort(
    FILE* destination,
    short unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

bool writeUInt(
    FILE* destination,
    unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

bool writeULong(
    FILE* destination,
    long unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

bool writeFloat(
    FILE* destination,
    float* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);



bool writeUByteArray(
    FILE* destination,
    unsigned char* value,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
);

#endif // !CFALLSAVE_WRITER_H
