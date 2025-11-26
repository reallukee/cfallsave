/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : main.c
 *
 * Title       : MAIN
 * Description : Main
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.3.0
 * License     : MIT
 */

#include "cfallsave.h"

int main(int argc, const char* argv[])
{
    printf("Version: %s\n", cfs_getFriendlyVersion());
    printf("Minimum version: %s\n", cfs_getMinFriendlyVersion());

    const char* saveName = "fo4.fos";

    if (argc > 1)
    {
        saveName = argv[1];
    }

    if (!isFO4Save(saveName))
    {
        return 1;
    }

    FO4SAVE* save = readFO4Save(saveName);

    if (!isFO4SaveOpen(save))
    {
        return 1;
    }

    printFO4Save(save);

    closeFO4Save(save);

    return 0;
}
