#include "../../src/cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fo3.fos";

    if (!isFO3Save(saveName))
    {
        return -1;
    }

    FO3SAVE* save = readFO3Save(saveName);

    if (!isFO3SaveOpen(save))
    {
        return -1;
    }

    printFO3Save(save);

    closeFO3Save(save);

    return 0;
}
