// Compile and execute using:
//
//   gcc fo3.c ../src/fo3.c -o fo3.bin && ./fo3.bin

#include "../src/fo3.h"

int main()
{
    FILE* save = fopen("fo3.fos", "wb");

    if (save == NULL)
    {
        return false;
    }

    unsigned char* emptyBuffer = (unsigned char*)calloc(64, 1);

    if (emptyBuffer == NULL)
    {
        return false;
    }

    char separator = '|';

    fwrite(FO3SAVE_SIGNATURE, 1, FO3SAVE_SIGNATURE_LENGTH, save);

    fwrite(emptyBuffer, 4, sizeof(*emptyBuffer), save);

    unsigned int engineVersion = 48;
    fwrite(&engineVersion, sizeof(engineVersion), 1, save);

    fwrite(&separator, 1, sizeof(separator), save);

    unsigned int snapshotWidth = FO3SAVE_MAX_SNAPSHOT_WIDTH;
    fwrite(&snapshotWidth, sizeof(snapshotWidth), 1, save);

    fwrite(&separator, 1, sizeof(separator), save);

    unsigned int snapshotHeight = FO3SAVE_MAX_SNAPSHOT_HEIGHT;
    fwrite(&snapshotHeight, sizeof(snapshotHeight), 1, save);

    fwrite(&separator, 1, sizeof(separator), save);

    unsigned int saveNumber = 100;
    fwrite(&saveNumber, sizeof(saveNumber), 1, save);

    fwrite(&separator, 1, sizeof(separator), save);

    short unsigned int playerNameLength = 12;
    char playerName[] = "John Fallout";
    fwrite(&playerNameLength, sizeof(playerNameLength), 1, save);
    fwrite(&separator, 1, sizeof(separator), save);
    fwrite(playerName, sizeof(*playerName), playerNameLength, save);

    fwrite(&separator, 1, sizeof(separator), save);

    short unsigned int playerTitleLength = 6;
    char playerTitle[] = "Messia";
    fwrite(&playerTitleLength, sizeof(playerTitleLength), 1, save);
    fwrite(&separator, 1, sizeof(separator), save);
    fwrite(playerTitle, sizeof(*playerTitle), playerTitleLength, save);

    fwrite(&separator, 1, sizeof(separator), save);

    unsigned int playerLevel = 30;
    fwrite(&playerLevel, sizeof(playerLevel), 1, save);

    fwrite(&separator, 1, sizeof(separator), save);

    short unsigned int playerLocationLength = 34;
    char playerLocation[] = "La Zona contaminata della Capitale";
    fwrite(&playerLocationLength, sizeof(playerLocationLength), 1, save);
    fwrite(&separator, 1, sizeof(separator), save);
    fwrite(playerLocation, sizeof(*playerLocation), playerLocationLength, save);

    fwrite(&separator, 1, sizeof(separator), save);

    short unsigned int playerPlaytimeLength = 9;
    char playerPlaytime[] = "090.00.00";
    fwrite(&playerPlaytimeLength, sizeof(playerPlaytimeLength), 1, save);
    fwrite(&separator, 1, sizeof(separator), save);
    fwrite(playerPlaytime, sizeof(*playerPlaytime), playerPlaytimeLength, save);

    fwrite(&separator, 1, sizeof(separator), save);

    unsigned long snapshotLength = FO3SAVE_MAX_SNAPSHOT_LENGTH;
    unsigned char* snapshot = (unsigned char*)calloc(snapshotLength, 1);
    fwrite(snapshot, sizeof(*snapshot), snapshotLength, save);
    free(snapshot);

    fflush(save);

    fclose(save);

    free(emptyBuffer);

    return 0;
}
