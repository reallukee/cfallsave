/**
 * CFallSave
 *
 * Version : 1.0
 * Author  : Reallukee
 * License : MIT
 */

#include "fo4.h"

FO4SAVE* readFO4Save(char* saveName, bool readProperties)
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

    if (readProperties)
    {
        if (!readFO4Properties(save))
        {
            return NULL;
        }
    }

    return save;
}

bool isFO4Save(char* saveName)
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

    return strcmp(saveSignature, SAVE_SIGNATURE) == 0;
}

bool readFO4Properties(FO4SAVE* save)
{
    unsigned long address = 0x00;

    save->saveSignatureAddress = address;
    readFO4ArrayProperty(save, save->saveSignature, &address, 0, SAVE_SIGNATURE_LENGTH, true);

    if (strcmp(save->saveSignature, SAVE_SIGNATURE) != 0)
    {
        return false;
    }

    save->engineVersionAddress = getNextFO4PropertyAddress(address, 4);
    readFO4Property(save, &save->engineVersion, &address, 4, 4, true);

    save->saveNumberAddress = getNextFO4PropertyAddress(address, 0);
    readFO4Property(save, &save->saveNumber, &address, 0, 4, true);

    save->characterNameAddress = getNextFO4PropertyAddress(address, 0);
    readFO4StringProperty(save, &save->characterName, &address, 0, true);

    save->characterLevelAddress = getNextFO4PropertyAddress(address, 0);
    readFO4Property(save, &save->characterLevel, &address, 0, 4, true);

    save->characterLocationAddress = getNextFO4PropertyAddress(address, 0);
    readFO4StringProperty(save, &save->characterLocation, &address, 0, true);

    save->characterPlaytimeAddress = getNextFO4PropertyAddress(address, 0);
    readFO4StringProperty(save, &save->characterPlaytime, &address, 0, true);

    save->characterRaceAddress = getNextFO4PropertyAddress(address, 0);
    readFO4StringProperty(save, &save->characterRace, &address, 0, true);

    save->characterSexAddress = getNextFO4PropertyAddress(address, 0);
    readFO4Property(save, &save->characterSex, &address, 0, 2, true);

    save->characterCurrentXpAddress = getNextFO4PropertyAddress(address, 0);
    readFO4Property(save, &save->characterCurrentXp, &address, 0, 4, true);

    save->characterRequiredXpAddress = getNextFO4PropertyAddress(address, 0);
    readFO4Property(save, &save->characterRequiredXp, &address, 0, 4, true);

    save->snapshotWidthAddress = getNextFO4PropertyAddress(address, 8);
    readFO4Property(save, &save->snapshotWidth, &address, 8, 4, true);

    save->snapshotHeightAddress = getNextFO4PropertyAddress(address, 0);
    readFO4Property(save, &save->snapshotHeight, &address, 0, 4, true);

    save->snapshotLength = save->snapshotWidth * save->snapshotHeight * 4;

    save->snapshotAddress = getNextFO4PropertyAddress(address, 0);
    readFO4ArrayProperty(save, save->snapshot, &address, 0, save->snapshotLength, true);

    return true;
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



unsigned long getNextFO4PropertyAddress(unsigned long address, unsigned long skip)
{
    return address + skip;
}



bool readFO4Property(FO4SAVE* save, void* property, unsigned long* address, unsigned long skip, unsigned size, bool next)
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



void printFO4Save(FO4SAVE* save)
{
    printf("%#08X Save Signature        : %s \n", save->saveSignatureAddress, save->saveSignature);
    printf("%#08X Engine Version        : %u \n", save->engineVersionAddress, save->engineVersion);
    printf("%#08X Save Number           : %u \n", save->saveNumberAddress, save->saveNumber);
    printf("%#08X Character Name        : %s \n", save->characterNameAddress, save->characterName);
    printf("%#08X Character Level       : %u \n", save->characterLevelAddress, save->characterLevel);
    printf("%#08X Character Location    : %s \n", save->characterLocationAddress, save->characterLocation);
    printf("%#08X Character Playtime    : %s \n", save->characterPlaytimeAddress, save->characterPlaytime);
    printf("%#08X Character Race        : %s \n", save->characterRaceAddress, save->characterRace);
    printf("%#08X Character Sex         : %u \n", save->characterSexAddress, save->characterSex);
    printf("%#08X Character Current Xp  : %f \n", save->characterCurrentXpAddress, save->characterCurrentXp);
    printf("%#08X Character Required Xp : %f \n", save->characterRequiredXpAddress, save->characterRequiredXp);
    printf("%#08X Snapshot Widht        : %u \n", save->snapshotWidthAddress, save->snapshotWidth);
    printf("%#08X Snapshot Height       : %u \n", save->snapshotHeightAddress, save->snapshotHeight);
}
