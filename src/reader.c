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
 * Description : Reader Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "reader.h"

bool readFixedString(
    FILE* source,
    char* destination,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || destination == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int CHAR_SIZE = sizeof(char);

    size_t r_fread = fread(destination, CHAR_SIZE, length, source);

    if (r_fread != length)
    {
        return false;
    }

    destination[length] = '\0';

    if (updateAddress)
    {
        *address += skip + length;
    }

    return true;
}

bool readString(
    FILE* source,
    char** destination,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
)
{
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

    if (*destination != NULL)
    {
        free(*destination);
    }

    *destination = (char*)malloc(length + 1);

    if (*destination == NULL)
    {
        return false;
    }

    bool r_readFixedString = readFixedString(source, *destination, length, address, skipString, updateAddress);

    if (!r_readFixedString)
    {
        free(*destination);

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
    char** destination,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
)
{
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

    char* cursedProperty = (char*)malloc(length * 2 + 1);

    if (cursedProperty == NULL)
    {
        return false;
    }

    bool r_readFixedString = readFixedString(source, cursedProperty, length * 2, address, skipString, updateAddress);

    if (!r_readFixedString)
    {
        free(cursedProperty);

        return false;
    }

    if (*destination != NULL)
    {
        free(*destination);
    }

    *destination = (char*)malloc(length + 1);

    if (*destination == NULL)
    {
        free(cursedProperty);

        return false;
    }

    for (int i = 0, j = 0; i < length * 2 && j < length; i += 2, j++)
    {
        (*destination)[j] = cursedProperty[i];
    }

    (*destination)[length] = '\0';

    free(cursedProperty);

    if (!updateAddress)
    {
        *address -= 2;
    }

    return true;
}



bool readUByte(
    FILE* source,
    unsigned char* destination,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || destination == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UBYTE_SIZE = sizeof(unsigned char);

    size_t r_fread = fread(destination, UBYTE_SIZE, 1, source);

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
    short unsigned int* destination,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || destination == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int USHORT_SIZE = sizeof(short unsigned int);

    size_t r_fread = fread(destination, USHORT_SIZE, 1, source);

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
    unsigned int* destination,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || destination == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UINT_SIZE = sizeof(unsigned int);

    size_t r_fread = fread(destination, UINT_SIZE, 1, source);

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
    long unsigned int* destination,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || destination == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int ULONG_SIZE = sizeof(long unsigned int);

    size_t r_fread = fread(destination, ULONG_SIZE, 1, source);

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
    float* destination,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || destination == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int FLOAT_SIZE = sizeof(float);

    size_t r_fread = fread(destination, FLOAT_SIZE, 1, source);

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
    unsigned char* destination,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || destination == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UBYTE_SIZE = sizeof(unsigned char);

    size_t r_fread = fread(destination, UBYTE_SIZE, length, source);

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
