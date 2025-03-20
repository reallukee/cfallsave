/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : writer.c
 *
 * Title       : WRITER SOURCE
 * Description : Writer Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "writer.h"

bool writeFixedString(
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

    size_t r_fwrite = fwrite(value, CHAR_SIZE, length, source);

    if (r_fwrite != length)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + length;
    }

    return true;
}

bool writeString(
    FILE* source,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
)
{
    return true;
}

bool writeCURSEDString(
    FILE* source,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
)
{
    return true;
}



bool writeUByte(
    FILE* source,
    unsigned char* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UBYTE_SIZE = sizeof(unsigned char);

    size_t r_fwrite = fwrite(value, UBYTE_SIZE, 1, source);

    if (r_fwrite != 1)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + UBYTE_SIZE;
    }

    return true;
}

bool writeUShort(
    FILE* source,
    short unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int USHORT_SIZE = sizeof(short unsigned int);

    size_t r_fwrite = fwrite(value, USHORT_SIZE, 1, source);

    if (r_fwrite != 1)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + USHORT_SIZE;
    }

    return true;
}

bool writeUInt(
    FILE* source,
    unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UINT_SIZE = sizeof(unsigned int);

    size_t r_fwrite = fwrite(value, UINT_SIZE, 1, source);

    if (r_fwrite != 1)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + UINT_SIZE;
    }

    return true;
}

bool writeULong(
    FILE* source,
    long unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int ULONG_SIZE = sizeof(long unsigned int);

    size_t r_fwrite = fwrite(value, ULONG_SIZE, 1, source);

    if (r_fwrite != 1)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + ULONG_SIZE;
    }

    return true;
}

bool writeFloat(
    FILE* source,
    float* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (source == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(source, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int FLOAT_SIZE = sizeof(float);

    size_t r_fwrite = fwrite(value, FLOAT_SIZE, 1, source);

    if (r_fwrite != 1)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + FLOAT_SIZE;
    }

    return true;
}



bool writeUByteArray(
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

    size_t r_fwrite = fwrite(value, UBYTE_SIZE, length, source);

    if (r_fwrite != length)
    {
        return false;
    }

    if (updateAddress)
    {
        *address += skip + length;
    }

    return true;
}
