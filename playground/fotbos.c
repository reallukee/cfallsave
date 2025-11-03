// Compile and execute using:
//
//   gcc fotbos.c ../src/fotbos.c -o fotbos.bin && ./fotbos.bin

#include "../src/fotbos.h"

int main()
{
    FILE* save = fopen("fotbos.sav", "wb");

    if (save == NULL)
    {
        return false;
    }

    unsigned char* emptyBuffer = (unsigned char*)calloc(64, 1);

    if (emptyBuffer == NULL)
    {
        return false;
    }

    fwrite(FOTBOSSAVE_SIGNATURE, 1, FOTBOSSAVE_SIGNATURE_LENGTH, save);

    fwrite(emptyBuffer, 8, sizeof(*emptyBuffer), save);

    short unsigned int saveNameLength = 13;
    char saveName[] = "N\0e\0w\0 \0S\0a\0v\0e\0 \0G\0a\0m\0e\0";
    fwrite(&saveNameLength, sizeof(saveNameLength), 1, save);
    fwrite(emptyBuffer, 2, sizeof(*emptyBuffer), save);
    fwrite(saveName, sizeof(*saveName), saveNameLength * 2, save);

    short unsigned int playerNameLength = 12;
    char playerName[] = "J\0o\0h\0n\0 \0F\0a\0l\0l\0o\0u\0t\0";
    fwrite(&playerNameLength, sizeof(playerNameLength), 1, save);
    fwrite(emptyBuffer, 2, sizeof(*emptyBuffer), save);
    fwrite(playerName, sizeof(*playerName), playerNameLength * 2, save);

    short unsigned int playerLocationLength = 12;
    char playerLocation[] = "B\0r\0a\0h\0m\0i\0n\0 \0W\0o\0o\0d\0";
    fwrite(&playerLocationLength, sizeof(playerLocationLength), 1, save);
    fwrite(emptyBuffer, 2, sizeof(*emptyBuffer), save);
    fwrite(playerLocation, sizeof(*playerLocation), playerLocationLength * 2, save);

    short unsigned int gameDateTimeLength = 3;
    char gameDateTime[] = "J\0a\0n\0";
    fwrite(&gameDateTimeLength, sizeof(gameDateTimeLength), 1, save);
    fwrite(emptyBuffer, 2, sizeof(*emptyBuffer), save);
    fwrite(gameDateTime, sizeof(*gameDateTime), gameDateTimeLength * 2, save);

    fflush(save);

    fclose(save);

    free(emptyBuffer);

    return 0;
}
