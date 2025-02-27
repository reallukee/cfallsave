#include "../src/cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fo4.fos";

    if (!isFO4Save(saveName))
    {
        return -1;
    }

    FO4SAVE* save = readFO4Save(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFO4Save(save);

    closeFO4Save(save);

    return 0;
}
