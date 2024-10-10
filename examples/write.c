/**
 * CFallSave
 *
 * Version : 1.0
 * Author  : Reallukee
 * License : MIT
 */

#include "cfallsave.h"

int main(int argc, char* argv[])
{
    FO4SAVE* save = readFO4Save("fo4.fos");

    if (save == NULL)
    {
        return -1;
    }

    printFO4Save(save);

    wroteFO4Save(save, "newfo4.fos");

    return 0;
}
