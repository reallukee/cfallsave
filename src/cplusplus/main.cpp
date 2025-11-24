/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : main.cpp
 *
 * Title       : MAIN++
 * Description : Main++
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.3.0
 * License     : MIT
 */

#include "cfallsave++.hpp"

using namespace cfallsavepp;

int main(int argc, const char* argv[])
{
    printf("Version: %s\n", cfspp_getFriendlyVersion());
    printf("Minimum version: %s\n", cfspp_getMinFriendlyVersion());

    string saveName = "fo4.fos";

    if (argc > 1)
    {
        saveName = argv[1];
    }

    if (!FO4Save::isSave(saveName))
    {
        return 1;
    }

    FO4Save* save = new FO4Save(saveName);

    if (!save->isOpen())
    {
        return 1;
    }

    save->print();

    delete save;

    return 0;
}
