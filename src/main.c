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
 * Version     : 2.0.0
 * License     : MIT
 */

#include "cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fo4.fos";

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
