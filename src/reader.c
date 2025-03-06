/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
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
    FILE* file,
    char* property,
    unsigned long length,
    unsigned long* address,
    unsigned long skip
)
{
    if (file == NULL || property == NULL || address == NULL)
    {
        return false;
    }

    *address += skip;

    int r_fseek = fseek(file, *address, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int CHAR_SIZE = sizeof(char);

    size_t r_fread = fread(property, CHAR_SIZE, length, file);

    if (r_fread != length)
    {
        *address -= skip;

        return false;
    }

    property[length + 1] = '\0';

    *address += length;

    return true;
}

bool readString(
    FILE* file,
    char** property,
    unsigned long* address,
    unsigned long skipLength,
    unsigned long skipString
)
{
    unsigned short length = 0;

    readUShort(file, &length, address, skipLength);

    if (*property != NULL)
    {
        free(*property);
    }

    *property = (char*)malloc(length + 1);

    if (*property == NULL)
    {
        return false;
    }

    readFixedString(file, *property, length, address, skipString);

    return true;
}

bool readCURSEDString(
    FILE* file,
    char** property,
    unsigned long* address,
    unsigned long skipLength,
    unsigned long skipString
)
{
    unsigned short length = 0;

    readUShort(file, &length, address, skipLength);

    char* cursedPropery = (char*)malloc(length * 2 + 1);

    if (cursedPropery == NULL)
    {
        return false;
    }

    readFixedString(file, cursedPropery, length * 2, address, skipString);

    if (*property != NULL)
    {
        free(*property);
    }

    *property = (char*)malloc(length + 1);

    if (*property == NULL)
    {
        free(cursedPropery);

        return false;
    }

    for (int i = 0, j = 0; i < length * 2 && j < length; i += 2, j++)
    {
        (*property)[j] = cursedPropery[i];
    }

    (*property)[length] = '\0';

    free(cursedPropery);

    return true;
}



bool readUByte(
    FILE* file,
    unsigned short* property,
    unsigned long* address,
    unsigned long skip
)
{
    if (file == NULL || property == NULL || address == NULL)
    {
        return false;
    }

    *address += skip;

    int r_fseek = fseek(file, *address, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UBYTE_SIZE = sizeof(unsigned char);

    size_t r_fread = fread(property, UBYTE_SIZE, 1, file);

    if (r_fread != 1)
    {
        *address -= skip;

        return false;
    }

    *address += UBYTE_SIZE;

    return true;
}

bool readUShort(
    FILE* file,
    unsigned short* property,
    unsigned long* address,
    unsigned long skip
)
{
    if (file == NULL || property == NULL || address == NULL)
    {
        return false;
    }

    *address += skip;

    int r_fseek = fseek(file, *address, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int USHORT_SIZE = sizeof(unsigned short);

    size_t r_fread = fread(property, USHORT_SIZE, 1, file);

    if (r_fread != 1)
    {
        *address -= skip;

        return false;
    }

    *address += USHORT_SIZE;

    return true;
}

bool readUInt(
    FILE* file,
    unsigned* property,
    unsigned long* address,
    unsigned long skip
)
{
    if (file == NULL || property == NULL || address == NULL)
    {
        return false;
    }

    *address += skip;

    int r_fseek = fseek(file, *address, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UINT_SIZE = sizeof(unsigned int);

    size_t r_fread = fread(property, UINT_SIZE, 1, file);

    if (r_fread != 1)
    {
        *address -= skip;

        return false;
    }

    *address += UINT_SIZE;

    return true;
}

bool readULong(
    FILE* file,
    unsigned long* property,
    unsigned long* address,
    unsigned long skip
)
{
    if (file == NULL || property == NULL || address == NULL)
    {
        return false;
    }

    *address += skip;

    int r_fseek = fseek(file, *address, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int ULONG_SIZE = sizeof(unsigned long);

    size_t r_fread = fread(property, ULONG_SIZE, 1, file);

    if (r_fread != 1)
    {
        *address -= skip;

        return false;
    }

    *address += ULONG_SIZE;

    return true;
}

bool readFloat(
    FILE* file,
    float* property,
    unsigned long* address,
    unsigned long skip
)
{
    if (file == NULL || property == NULL || address == NULL)
    {
        return false;
    }

    *address += skip;

    int r_fseek = fseek(file, *address, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int FLOAT_SIZE = sizeof(float);

    size_t r_fread = fread(property, FLOAT_SIZE, 1, file);

    if (r_fread != 1)
    {
        *address -= skip;

        return false;
    }

    *address += FLOAT_SIZE;

    return true;
}



bool readUByteArray(
    FILE* file,
    unsigned char* property,
    long unsigned length,
    unsigned long* address,
    unsigned long skip
)
{
    if (file == NULL || property == NULL || address == NULL)
    {
        return false;
    }

    *address += skip;

    int r_fseek = fseek(file, *address, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UBYTE_SIZE = sizeof(unsigned char);

    size_t r_fread = fread(property, UBYTE_SIZE, length, file);

    if (r_fread != length)
    {
        *address -= skip;

        return false;
    }

    property[length + 1] = '\0';

    *address += length;

    return true;
}
