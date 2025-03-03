/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * Author  : Reallukee
 * Version : 1.0
 * License : MIT
 */

#include <iostream>
#include "cfallsave.hpp"

using namespace std;
using namespace cfallsave;

int main()
{
    FO4Save* save = new FO4Save("fo4.fos");

    save->printSave();

    delete(save);

    return 0;
}
