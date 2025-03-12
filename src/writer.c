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
    unsigned long length,
    unsigned long* address,
    unsigned long skip,
    bool updateAddress
)
{
    return false;
}

bool writeString(
    FILE* source,
    char** value,
    unsigned long* address,
    unsigned long skipLength,
    unsigned long skipString,
    bool updateAddress
)
{
    return false;
}

bool writeCURSEDString(
    FILE* source,
    char** value,
    unsigned long* address,
    unsigned long skipLength,
    unsigned long skipString,
    bool updateAddress
)
{
    return false;
}



bool writeUByte(
    FILE* source,
    unsigned char value,
    unsigned long* address,
    unsigned long skip,
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

    size_t r_fwrite = fwrite(&value, UBYTE_SIZE, 1, source);

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
    unsigned short value,
    unsigned long* address,
    unsigned long skip,
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

    int USHORT_SIZE = sizeof(unsigned short);

    size_t r_fwrite = fwrite(&value, USHORT_SIZE, 1, source);

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
    unsigned int value,
    unsigned long* address,
    unsigned long skip,
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

    size_t r_fwrite = fwrite(&value, UINT_SIZE, 1, source);

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
    unsigned long value,
    unsigned long* address,
    unsigned long skip,
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

    int ULONG_SIZE = sizeof(unsigned long);

    size_t r_fwrite = fwrite(&value, ULONG_SIZE, 1, source);

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
    float value,
    unsigned long* address,
    unsigned long skip,
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

    size_t r_fwrite = fwrite(&value, FLOAT_SIZE, 1, source);

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
    unsigned long length,
    unsigned long* address,
    unsigned long skip,
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

    size_t r_fwrite = fwrite(&value, UBYTE_SIZE, length, source);

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
