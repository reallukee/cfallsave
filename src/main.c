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

    char value[] = "lucia";

    writeFO4StringProperty(save, &save->characterName, &value, &save->characterNameAddress, 0, false);

    printFO4Save(save);

    closeFO4Save(save);

    return 0;
}
