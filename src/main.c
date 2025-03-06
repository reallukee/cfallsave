/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
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
