#include "../src/cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fonv.fos";

    if (!isFONVSave(saveName))
    {
        return -1;
    }

    FONVSAVE* save = readFONVSave(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFONVSave(save);

    closeFONVSave(save);

    return 0;
}
