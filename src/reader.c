/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : reader.c
 *
 * Title       : READER SOURCE
 * Description : Questo file contiene le implementazioni
 *               dei metodi definiti nell'intestazioni
 *               "reader.h".
 *               Questi metodi permettono la manipolazione
 *               in lettura dei dati presenti all'interno
 *               di un file binario.
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "reader.h"

bool readFixedString(
    FILE* source,
    char* value,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int CHAR_SIZE = sizeof(char);

    size_t r_fread = fread(value, CHAR_SIZE, length, source);

    if (r_fread != length)
    {
        return false;
    }

    value[length] = '\0';

    if (updateAddress)
    {
        *address += skip + length;
    }

    return true;
}

bool readString(
    FILE* source,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
)
{
    if (source == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    short unsigned int length = 0;

    bool r_readUShort = readUShort(source, &length, address, skipLength, updateAddress);

    if (!r_readUShort)
    {
        return false;
    }

    if (!updateAddress)
    {
        *address += 2;
    }

    if (*value != NULL)
    {
        free(*value);
    }

    *value = (char*)malloc(length + 1);

    if (*value == NULL)
    {
        return false;
    }

    bool r_readFixedString = readFixedString(source, *value, length, address, skipString, updateAddress);

    if (!r_readFixedString)
    {
        free(*value);

        return false;
    }

    if (!updateAddress)
    {
        *address -= 2;
    }

    return true;
}

bool readCURSEDString(
    FILE* source,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
)
{
    if (source == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    short unsigned int length = 0;

    bool r_readUShort = readUShort(source, &length, address, skipLength, updateAddress);

    if (!r_readUShort)
    {
        return false;
    }

    if (!updateAddress)
    {
        *address += 2;
    }

    char* cursedValue = (char*)malloc(length * 2);

    if (cursedValue == NULL)
    {
        return false;
    }

    bool r_readFixedString = readFixedString(source, cursedValue, length * 2, address, skipString, updateAddress);

    if (!r_readFixedString)
    {
        free(cursedValue);

        return false;
    }

    if (*value != NULL)
    {
        free(*value);
    }

    *value = (char*)malloc(length + 1);

    if (*value == NULL)
    {
        free(cursedValue);

        return false;
    }

    for (int i = 0, j = 0; i < length * 2 && j < length; i += 2, j++)
    {
        (*value)[j] = cursedValue[i];
    }

    (*value)[length] = '\0';

    free(cursedValue);

    if (!updateAddress)
    {
        *address -= 2;
    }

    return true;
}



bool readUByte(
    FILE* source,
    unsigned char* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UBYTE_SIZE = sizeof(unsigned char);

    size_t r_fread = fread(value, UBYTE_SIZE, 1, source);

    if (r_fread != 1)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + UBYTE_SIZE;
    }

    return true;
}

bool readUShort(
    FILE* source,
    short unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int USHORT_SIZE = sizeof(short unsigned int);

    size_t r_fread = fread(value, USHORT_SIZE, 1, source);

    if (r_fread != 1)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + USHORT_SIZE;
    }

    return true;
}

bool readUInt(
    FILE* source,
    unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UINT_SIZE = sizeof(unsigned int);

    size_t r_fread = fread(value, UINT_SIZE, 1, source);

    if (r_fread != 1)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + UINT_SIZE;
    }

    return true;
}

bool readULong(
    FILE* source,
    long unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int ULONG_SIZE = sizeof(long unsigned int);

    size_t r_fread = fread(value, ULONG_SIZE, 1, source);

    if (r_fread != 1)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + ULONG_SIZE;
    }

    return true;
}

bool readFloat(
    FILE* source,
    float* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int FLOAT_SIZE = sizeof(float);

    size_t r_fread = fread(value, FLOAT_SIZE, 1, source);

    if (r_fread != 1)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + FLOAT_SIZE;
    }

    return true;
}



bool readUByteArray(
    FILE* source,
    unsigned char* value,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UBYTE_SIZE = sizeof(unsigned char);

    size_t r_fread = fread(value, UBYTE_SIZE, length, source);

    if (r_fread != length)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + length;
    }

    return true;
}
