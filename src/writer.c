/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : writer.c
 *
 * Title       : WRITER SOURCE
 * Description : Questo file contiene le implementazioni
 *               dei metodi definiti nell'intestazione
 *               "writer.h".
 *               Questi metodi permettono la manipolazione
 *               in scrittura dei dati presenti all'interno
 *               di un file binario.
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "writer.h"

bool writeFixedString(
    FILE* destination,
    char* value,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (destination == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(destination, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int CHAR_SIZE = sizeof(char);

    size_t r_fwrite = fwrite(value, CHAR_SIZE, length, destination);

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
    FILE* destination,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
)
{
    if (destination == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    short unsigned int length = (short unsigned int)strlen(*value);

    bool r_writeUShort = writeUShort(destination, &length, address, skipLength, updateAddress);

    if (!r_writeUShort)
    {
        return false;
    }

    if (!updateAddress)
    {
        *address += 2;
    }

    bool r_writeFixedString = writeFixedString(destination, *value, length, address, skipString, updateAddress);

    if (!r_writeFixedString)
    {
        return false;
    }

    if (!updateAddress)
    {
        *address -= 2;
    }

    return true;
}

bool writeCURSEDString(
    FILE* destination,
    char** value,
    long unsigned int* address,
    long unsigned int skipLength,
    long unsigned int skipString,
    bool updateAddress
)
{
    if (destination == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    short unsigned int length = (short unsigned int)strlen(*value);

    bool r_writeUShort = writeUShort(destination, &length, address, skipLength, updateAddress);

    if (!r_writeUShort)
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

    for (int i = 0, j = 0; i < length && j < length * 2; i++, j += 2)
    {
        cursedValue[j] = (*value)[i];

        cursedValue[j + 1] = '\0';
    }

    bool r_writeFixedString = writeFixedString(destination, cursedValue, length * 2, address, skipString, updateAddress);

    if (!r_writeFixedString)
    {
        free(cursedValue);

        return false;
    }

    free(cursedValue);

    if (!updateAddress)
    {
        *address -= 2;
    }

    return true;
}



bool writeUByte(
    FILE* destination,
    unsigned char* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (destination == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(destination, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UBYTE_SIZE = sizeof(unsigned char);

    size_t r_fwrite = fwrite(value, UBYTE_SIZE, 1, destination);

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
    FILE* destination,
    short unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (destination == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(destination, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int USHORT_SIZE = sizeof(short unsigned int);

    size_t r_fwrite = fwrite(value, USHORT_SIZE, 1, destination);

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
    FILE* destination,
    unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (destination == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(destination, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UINT_SIZE = sizeof(unsigned int);

    size_t r_fwrite = fwrite(value, UINT_SIZE, 1, destination);

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
    FILE* destination,
    long unsigned int* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (destination == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(destination, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int ULONG_SIZE = sizeof(long unsigned int);

    size_t r_fwrite = fwrite(value, ULONG_SIZE, 1, destination);

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
    FILE* destination,
    float* value,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (destination == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(destination, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int FLOAT_SIZE = sizeof(float);

    size_t r_fwrite = fwrite(value, FLOAT_SIZE, 1, destination);

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
    FILE* destination,
    unsigned char* value,
    long unsigned int length,
    long unsigned int* address,
    long unsigned int skip,
    bool updateAddress
)
{
    if (destination == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    int r_fseek = fseek(destination, *address + skip, SEEK_SET);

    if (r_fseek != 0)
    {
        return false;
    }

    int UBYTE_SIZE = sizeof(unsigned char);

    size_t r_fwrite = fwrite(value, UBYTE_SIZE, length, destination);

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
