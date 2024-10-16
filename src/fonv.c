/**
 * CFallSave
 *
 * Version : 1.0
 * Author  : Reallukee
 * License : MIT
 */

#include "fonv.h"

FONVSAVE* readFONVSave(char* saveName, bool readProperties)
{
    FILE* file = fopen(saveName, "r+w+b");

    if (file == NULL)
    {
        return NULL;
    }

    FONVSAVE* save = malloc(sizeof(FONVSAVE));

    if (save == NULL)
    {
        return NULL;
    }

    save->saveFile = file;

    if (readProperties)
    {
        if (!readFONVProperties(save))
        {
            return NULL;
        }
    }

    return save;
}

bool isFONVSave(char* saveName)
{
    FILE* file = fopen(saveName, "r+b");

    if (file == NULL)
    {
        return NULL;
    }

    char saveSignature[SAVE_SIGNATURE_LENGTH + 1];

    if (fread(saveSignature, 1, SAVE_SIGNATURE_LENGTH, file) != SAVE_SIGNATURE_LENGTH)
    {
        return false;
    }

    saveSignature[SAVE_SIGNATURE_LENGTH] = '\0';

    if (strcmp(saveSignature, SAVE_SIGNATURE) != 0)
    {
        return false;
    }

    if (fseek(file, 24, SEEK_SET) != 0)
    {
        return false;
    }

    char nv;

    if (fread(&nv, 1, 1, file) != 1)
    {
        return false;
    }

    return nv != '|';
}

bool readFONVProperties(FONVSAVE* save)
{
    unsigned long address = 0x00;

    save->saveSignatureAddress = getNextFONVPropertyAddress(address, 0);
    readFONVArrayProperty(save, save->saveSignature, &address, 0, SAVE_SIGNATURE_LENGTH, true);

    if (strcmp(save->saveSignature, SAVE_SIGNATURE) != 0)
    {
        return false;
    }

    save->snapshotWidthAddress = getNextFONVPropertyAddress(address, 74);
    readFONVProperty(save, &save->snapshotWidth, &address, 74, 4, true);

    save->snapshotHeightAddress = getNextFONVPropertyAddress(address, 1);
    readFONVProperty(save, &save->snapshotHeight, &address, 1, 4, true);

    save->saveNumberAddress = getNextFONVPropertyAddress(address, 1);
    readFONVProperty(save, &save->saveNumber, &address, 1, 4, true);

    save->characterNameAddress = getNextFONVPropertyAddress(address, 1);
    readFONVStringProperty(save, &save->characterName, &address, 1, true);

    save->characterTitleAddress = getNextFONVPropertyAddress(address, 1);
    readFONVStringProperty(save, &save->characterTitle, &address, 1, true);

    save->characterLevelAddress = getNextFONVPropertyAddress(address, 1);
    readFONVProperty(save, &save->characterLevel, &address, 1, 4, true);

    save->characterLocationAddress = getNextFONVPropertyAddress(address, 1);
    readFONVStringProperty(save, &save->characterLocation, &address, 1, true);

    save->characterPlaytimeAddress = getNextFONVPropertyAddress(address, 1);
    readFONVStringProperty(save, &save->characterPlaytime, &address, 1, true);

    save->snapshotLength = save->snapshotWidth * save->snapshotHeight;

    save->snapshotAddress = getNextFONVPropertyAddress(address, 0);
    readFONVArrayProperty(save, save->snapshot, &address, 0, save->snapshotLength, true);

    return true;
}

bool writeFONVSave(FONVSAVE* save, char* saveName)
{
    if (save == NULL)
    {
        return false;
    }

    return fflush(save->saveFile) == 0;
}

bool closeFONVSave(FONVSAVE* save)
{
    if (save == NULL)
    {
        return false;
    }

    free(save);

    return true;
}



unsigned long getNextFONVPropertyAddress(unsigned long address, unsigned long skip)
{
    return address + skip;
}



bool readFONVProperty(FONVSAVE* save, void* property, unsigned long* address, unsigned long skip, unsigned size, bool next)
{
    if (save == NULL || save->saveFile == NULL || property == NULL || address == NULL)
    {
        return false;
    }

    if (size == 0)
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

bool readFONVStringProperty(FONVSAVE* save, void** property, unsigned long* address, unsigned long skip, bool next)
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

    if (fseek(save->saveFile, 0x01, SEEK_CUR) != 0)
    {
        return false;
    }

    if (fread(*property, size, length, save->saveFile) != length)
    {
        return false;
    }

    ((char*)*property)[length] = '\0';

    if (next)
    {
        *address += length + skip + sizeof(length) + 1;
    }

    return true;
}

bool readFONVArrayProperty(FONVSAVE* save, void* property, unsigned long* address, unsigned long skip, int length, bool next)
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



bool writeFONVProperty(FONVSAVE* save, void* property, void* value, unsigned long* address, unsigned long skip, unsigned size, bool next)
{
    if (save == NULL || save->saveFile == NULL || property == NULL || value == NULL || address == NULL)
    {
        return false;
    }

    if (size == 0)
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

    readFONVProperty(save, property, address, skip, size, next);

    return true;
}

bool writeFONVStringProperty(FONVSAVE* save, void** property, void* value, unsigned long* address, unsigned long skip, bool next)
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

    readFONVStringProperty(save, property, address, skip, next);

    return true;
}

bool writeFONVArrayProperty(FONVSAVE* save, void* property, void* value, unsigned long* address, unsigned long skip, int length, bool next)
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

    readFONVArrayProperty(save, property, address, skip, length, next);

    return true;
}



void printFONVSave(FONVSAVE* save)
{
    printf("%#08X Save Signature     : %s \n", save->saveSignatureAddress, save->saveSignature);
    printf("%#08X Snapshot Width     : %u \n", save->snapshotWidthAddress, save->snapshotWidth);
    printf("%#08X Snapshot Height    : %u \n", save->snapshotHeightAddress, save->snapshotHeight);
    printf("%#08X Save Number        : %u \n", save->saveNumberAddress, save->saveNumber);
    printf("%#08X Character Name     : %s \n", save->characterNameAddress, save->characterName);
    printf("%#08X Character Title    : %s \n", save->characterTitleAddress, save->characterTitle);
    printf("%#08X Character Location : %s \n", save->characterLocationAddress, save->characterLocation);
    printf("%#08X Character Playtime : %s \n", save->characterPlaytimeAddress, save->characterPlaytime);
}
