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
    char* saveName = "fo3.fos";

    if (!isFO3Save(saveName))
    {
        return 1;
    }

    FO3SAVE* save = readFO3Save(saveName, true);

    if (save == NULL)
    {
        return 1;
    }

    printFO3Save(save);

    writeFO3Save(save, "newfo3.fos");

    closeFO3Save(save);

    return 0;
}
