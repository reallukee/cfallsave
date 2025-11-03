// Compile and execute using:
//
//   gcc fo1.c ../src/fo1.c -o fo1.bin && ./fo1.bin

#include "../src/fo1.h"

int main()
{
    FILE* save = fopen("fo1.dat", "wb");

    if (save == NULL)
    {
        return false;
    }

    unsigned char* emptyBuffer = (unsigned char*)calloc(64, 1);

    fwrite(FO1SAVE_SIGNATURE, 1, FO1SAVE_SIGNATURE_LENGTH, save);

    fwrite(emptyBuffer, 12, sizeof(*emptyBuffer), save);

    char playerName[FO1SAVE_STRING_SIZE] = "John Fallout";
    fwrite(playerName, sizeof(*playerName), FO1SAVE_STRING_SIZE, save);

    char saveName[FO1SAVE_STRING_SIZE] = "Save 1";
    fwrite(saveName, sizeof(*saveName), FO1SAVE_STRING_SIZE, save);

    fflush(save);

    fclose(save);

    free(emptyBuffer);

    return 0;
}
