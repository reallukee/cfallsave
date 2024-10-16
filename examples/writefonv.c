/**
 * CFallSave
 *
 * Version : 1.0
 * Author  : Reallukee
 * License : MIT
 */

#include "../src/cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fonv.fos";

    if (!isFONVSave(saveName))
    {
        return 1;
    }

    FONVSAVE* save = readFONVSave(saveName, true);

    if (save == NULL)
    {
        return 1;
    }

    printFONVSave(save);

    writeFONVSave(save, "newfoNV.fos");

    closeFONVSave(save);

    return 0;
}
