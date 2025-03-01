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

#include "reader.h"

bool readFixedString(
    FILE* file,
    char* property,
    int length,
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

    int r_fread = fread(property, CHAR_SIZE, length, file);

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

    int f_read = fread(property, UBYTE_SIZE, 1, file);

    if (f_read != 1)
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

    int f_read = fread(property, USHORT_SIZE, 1, file);

    if (f_read != 1)
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

    int f_read = fread(property, UINT_SIZE, 1, file);

    if (f_read != 1)
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

    int f_read = fread(property, ULONG_SIZE, 1, file);

    if (f_read != 1)
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

    int f_read = fread(property, FLOAT_SIZE, 1, file);

    if (f_read != 1)
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
    int length,
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

    int r_fread = fread(property, UBYTE_SIZE, length, file);

    if (r_fread != length)
    {
        *address -= skip;

        return false;
    }

    property[length + 1] = '\0';

    *address += length;

    return true;
}
