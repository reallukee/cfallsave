#include "../../src/cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fotbos.sav";

    if (!isFOTBOSSave(saveName))
    {
        return -1;
    }

    FOTBOSSAVE* save = readFOTBOSSave(saveName);

    if (!isFOTBOSSaveOpen(save))
    {
        return -1;
    }

    printFOTBOSSave(save);

    closeFOTBOSSave(save);

    return 0;
}
