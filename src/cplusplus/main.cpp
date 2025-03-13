/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : main.cpp
 *
 * Title       : MAIN++
 * Description : Main++
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include <iostream>
#include "cfallsave.hpp"

using namespace std;
using namespace cfallsave;

int main()
{
    FO4Save* save = new FO4Save("fo4.fos");

    save->printSave();

    delete save;

    return 0;
}
