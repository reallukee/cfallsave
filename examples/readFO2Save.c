#include "../src/cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fo2.dat";

    if (!isFO2Save(saveName))
    {
        return -1;
    }

    FO2SAVE* save = readFO2Save(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFO2Save(save);

    closeFO2Save(save);

    return 0;
}
