#include "../src/cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fo1.dat";

    if (!isFO1Save(saveName))
    {
        return -1;
    }

    FO1SAVE* save = readFO1Save(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFO1Save(save);

    closeFO1Save(save);

    return 0;
}
