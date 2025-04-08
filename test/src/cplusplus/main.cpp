#include <iostream>
#include "../../../src/cplusplus/cfallsave.hpp"

using namespace std;
using namespace cfallsavepp;

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
    printf("********************\n");
    printf("* CFallSave++ Test *\n");
    printf("*      v%s      *\n", CFALLSAVEPP_VERSION_S);
    printf("********************\n");

    printf("\n");

    printf(" * read <Fallout 4 Save>");
}

bool readSave(char* saveName)
{
    if (!FO4Save::isSave(saveName))
    {
        return false;
    }

    FO4Save* save = new FO4Save(saveName);

    if (!save->isOpen())
    {
        return false;
    }

    save->printSave();

    delete save;

    return true;
}
