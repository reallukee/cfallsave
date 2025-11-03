// Compile and execute using:
//
//   gcc fo2.c ../src/fo2.c -o fo2.bin && ./fo2.bin

#include "../src/fo2.h"

int main()
{
    FILE* save = fopen("fo2.dat", "wb");

    if (save == NULL)
    {
        return false;
    }

    unsigned char* emptyBuffer = (unsigned char*)calloc(64, 1);

    fwrite(FO2SAVE_SIGNATURE, 1, FO2SAVE_SIGNATURE_LENGTH, save);

    fwrite(emptyBuffer, 12, sizeof(*emptyBuffer), save);

    char playerName[FO2SAVE_STRING_SIZE] = "John Fallout";
    fwrite(playerName, sizeof(*playerName), FO2SAVE_STRING_SIZE, save);

    char saveName[FO2SAVE_STRING_SIZE] = "Save 2";
    fwrite(saveName, sizeof(*saveName), FO2SAVE_STRING_SIZE, save);

    fflush(save);

    fclose(save);

    free(emptyBuffer);

    return 0;
}
