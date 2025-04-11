#include <stdio.h>
#include "../../src/cfallsave.h"

void commandLineArgs(int argc, char* argv[]);
void help();
bool readFO1(char* saveName);
bool readFO2(char* saveName);
bool readFOTBOS(char* saveName);
bool readFO3(char* saveName);
bool readFONV(char* saveName);
bool readFO4(char* saveName);



int main(int argc, char* argv[])
{
    commandLineArgs(argc, argv);

    // createFO1SampleSave();
    // createFO2SampleSave();
    // createFOTBOSSampleSave();
    // createFO3SampleSave();
    // createFONVSampleSave();
    // createFO4SampleSave();

    return 0;
}



void commandLineArgs(int argc, char* argv[])
{
    if (argc == 1)
    {
        return help();
    }

    if (strcmp(argv[1], "read-fo1") == 0 && argc > 2)
    {
        readFO1(argv[2]);
    }

    if (strcmp(argv[1], "read-fo2") == 0 && argc > 2)
    {
        readFO2(argv[2]);
    }

    if (strcmp(argv[1], "read-fotbos") == 0 && argc > 2)
    {
        readFOTBOS(argv[2]);
    }

    if (strcmp(argv[1], "read-fo3") == 0 && argc > 2)
    {
        readFO3(argv[2]);
    }

    if (strcmp(argv[1], "read-fonv") == 0 && argc > 2)
    {
        readFONV(argv[2]);
    }

    if (strcmp(argv[1], "read-fo4") == 0 && argc > 2)
    {
        readFO4(argv[2]);
    }
}

void help()
{
    printf("\n");

    printf("******************\n");
    printf("* CFallSave Test *\n");
    printf("*     v%s     *\n", CFALLSAVE_VERSION_S);
    printf("******************\n");

    printf("\n");

    printf(" - read-fo1 <Save>\n");
    printf(" - read-fo2 <Save>\n");
    printf(" - read-fotbos <Save>\n");
    printf(" - read-fo3 <Save>\n");
    printf(" - read-fonv <Save>\n");
    printf(" - read-fo4 <Save>\n");

    printf("\n");
}

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
