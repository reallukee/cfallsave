/**
 * CFallSave
 *
 * Version : 1.0
 * Author  : Reallukee
 * License : MIT
 */

#include "fo4.h"

FO4SAVE* readFO4Save(char* saveName)
{
    FILE* file = fopen(saveName, "r+w+b");

    if (file == NULL)
    {
        return NULL;
    }

    FO4SAVE* save = malloc(sizeof(FO4SAVE));

    if (save == NULL)
    {
        return NULL;
    }

    save->saveFile = file;

    unsigned long address = 0x00;

    save->saveSignatureAddress = address;
    readFO4ArrayProperty(save, save->saveSignature, &address, 0, 12, true);
    
    save->engineVersionAddress = address;
    readFO4Property(save, &save->engineVersion, &address, 4, 4, true);

    save->saveNumberAddress = address;
    readFO4Property(save, &save->saveNumber, &address, 0, 4, true);

    save->characterNameAddress = address;
    readFO4StringProperty(save, &save->characterName, &address, 0, true);

    return save;
}

bool writeFO4Save(FO4SAVE* save, char* saveName)
{
    if (save == NULL)
    {
        return false;
    }

    return fflush(save->saveFile) == 0;
}

bool closeFO4Save(FO4SAVE* save)
{
    if (save == NULL)
    {
        return false;
    }

    free(save);

    return true;
}

void printFO4Save(FO4SAVE* save)
{
    printf("%#08X Save Signature %s \n", save->saveSignatureAddress, save->saveSignature);
    printf("%#08X Engine Version %u \n", save->engineVersionAddress, save->engineVersion);
    printf("%#08X Save Number    %u \n", save->saveNumberAddress, save->saveNumber);
    printf("%#08X Character Name %s \n", save->characterNameAddress, save->characterName);
}



bool readFO4Property(FO4SAVE* save, void* property, unsigned long* address, unsigned long skip, unsigned size, bool next)
{
    if (save == NULL || save->saveFile == NULL || property == NULL || address == NULL)
    {
        return false;
    }

    if (fseek(save->saveFile, *address + skip, SEEK_SET) != 0)
    {
        return false;
    }

    if (fread(property, size, 1, save->saveFile) != 1)
    {
        return false;
    }

    if (next)
    {
        *address += size + skip;
    }

    return true;
}

bool readFO4StringProperty(FO4SAVE* save, void** property, unsigned long* address, unsigned long skip, bool next)
{
    unsigned size = sizeof(**property);

    if (save == NULL || save->saveFile == NULL || address == NULL)
    {
        return false;
    }

    if (fseek(save->saveFile, *address + skip, SEEK_SET) != 0)
    {
        return false;
    }

    unsigned short length;

    if (fread(&length, sizeof(length), 1, save->saveFile) != 1)
    {
        return false;
    }

    *property = malloc(length + 1);

    if (fread(*property, size, length, save->saveFile) != length)
    {
        return false;
    }

    ((char*)*property)[length] = '\0';

    if (next)
    {
        *address += length + skip + sizeof(length);
    }

    return true;
}

bool readFO4ArrayProperty(FO4SAVE* save, void* property, unsigned long* address, unsigned long skip, int length, bool next)
{
    unsigned size = sizeof(*property);

    if (save == NULL || save->saveFile == NULL || property == NULL || address == NULL)
    {
        return false;
    }

    if (fseek(save->saveFile, *address + skip, SEEK_SET) != 0)
    {
        return false;
    }

    if (fread(property, size, length, save->saveFile) != length)
    {
        return false;
    }

    if (next)
    {
        *address += length + skip;
    }

    return true;
}



bool writeFO4Property(FO4SAVE* save, void* property, void* value, unsigned long* address, unsigned long skip, unsigned size, bool next)
{
   if (save == NULL || save->saveFile == NULL || property == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    if (fseek(save->saveFile, *address + skip, SEEK_SET) != 0)
    {
        return false;
    }

    if (fwrite(value, size, 1, save->saveFile) != 1)
    {
        return false;
    }

    readFO4Property(save, property, address, skip, size, next);

    return true;
}

bool writeFO4StringProperty(FO4SAVE* save, void** property, void* value, unsigned long* address, unsigned long skip, bool next)
{
    unsigned size = sizeof(**property);

    if (save == NULL || save->saveFile == NULL || address == NULL)
    {
        return false;
    }

    if (fseek(save->saveFile, *address + skip, SEEK_SET) != 0)
    {
        return false;
    }

    unsigned short length = 0;

    while (((char*)value)[length] != '\0')
    {
        length++;
    }

    if (fwrite(&length, sizeof(length), 1, save->saveFile) != 1)
    {
        return false;
    }

    if (fwrite(value, size, length, save->saveFile) != length)
    {
        return false;
    }

    readFO4StringProperty(save, property, address, skip, next);

    return true;
}

bool writeFO4ArrayProperty(FO4SAVE* save, void* property, void* value, unsigned long* address, unsigned long skip, int length, bool next)
{
    unsigned size = sizeof(*property);

    if (save == NULL || save->saveFile == NULL || property == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    if (fseek(save->saveFile, *address + skip, SEEK_SET) != 0)
    {
        return false;
    }

    if (fwrite(value, size, length, save->saveFile) != length)
    {
        return false;
    }

    readFO4ArrayProperty(save, property, address, skip, length, next);

    return true;
}
