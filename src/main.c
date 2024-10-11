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
    FO3SAVE* save = readFO3Save("fo3.fos");

    if (save == NULL)
    {
        return 1;
    }

    printFO3Save(save);

    closeFO3Save(save);

    return 0;
}
