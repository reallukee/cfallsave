#include "commands.hpp"

bool readFO1(char* saveName)
{
    if (!isFO1Save(saveName))
    {
        return false;
    }

    FO1SAVE* save = readFO1Save(saveName);

    if (!isFO1SaveOpen(save))
    {
        return false;
    }

    printFO1Save(save);

    closeFO1Save(save);

    return true;
}

bool readFO2(char* saveName)
{
    if (!isFO2Save(saveName))
    {
        return false;
    }

    FO2SAVE* save = readFO2Save(saveName);

    if (!isFO2SaveOpen(save))
    {
        return false;
    }

    printFO2Save(save);

    closeFO2Save(save);

    return true;
}

bool readFOTBOS(char* saveName)
{
    if (!isFOTBOSSave(saveName))
    {
        return false;
    }

    FOTBOSSAVE* save = readFOTBOSSave(saveName);

    if (!isFOTBOSSaveOpen(save))
    {
        return false;
    }

    printFOTBOSSave(save);

    closeFOTBOSSave(save);

    return true;
}

bool readFO3(char* saveName)
{
    if (!isFO3Save(saveName))
    {
        return false;
    }

    FO3SAVE* save = readFO3Save(saveName);

    if (!isFO3SaveOpen(save))
    {
        return false;
    }

    printFO3Save(save);

    closeFO3Save(save);

    return true;
}

bool readFONV(char* saveName)
{
    if (!isFONVSave(saveName))
    {
        return false;
    }

    FONVSAVE* save = readFONVSave(saveName);

    if (!isFONVSaveOpen(save))
    {
        return false;
    }

    printFONVSave(save);

    closeFONVSave(save);

    return true;
}

bool readFO4(char* saveName)
{
    if (!isFO4Save(saveName))
    {
        return false;
    }

    FO4SAVE* save = readFO4Save(saveName);

    if (!isFO4SaveOpen(save))
    {
        return false;
    }

    printFO4Save(save);

    closeFO4Save(save);

    return true;
}
