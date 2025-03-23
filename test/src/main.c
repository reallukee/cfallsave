#include "../../src/cfallsave.h"

void commandLineArgs(int argc, char* argv[]);

void help();

bool readSave(char* saveName);



int main(int argc, char* argv[])
{
    commandLineArgs(argc, argv);

    return 0;
}



void commandLineArgs(int argc, char* argv[])
{
    if (argc == 1)
    {
        return help();
    }

    if (strcmp(argv[1], "read") == 0 && argc > 2)
    {
        readSave(argv[2]);
    }
}

void help()
{
    printf("******************\n");
    printf("* CFallSave Test *\n");
    printf("*     v%s     *\n", CFALLSAVE_VERSION_S);
    printf("******************\n");
}

bool readSave(char* saveName)
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
