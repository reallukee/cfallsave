// Compile and execute using:
//
//   gcc fonv.c ../src/fonv.c -o fonv.out && ./fonv.out

#include "../src/fonv.h"

int main()
{
    FILE* save = fopen("fonv.fos", "wb");

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

    fwrite(FONVSAVE_SIGNATURE, 1, FONVSAVE_SIGNATURE_LENGTH, save);

    fwrite(emptyBuffer, 4, sizeof(*emptyBuffer), save);

    unsigned int engineVersion = 48;
    fwrite(&engineVersion, sizeof(engineVersion), 1, save);

    fwrite(&separator, 1, sizeof(separator), save);

    fwrite(emptyBuffer, 64, sizeof(*emptyBuffer), save);

    fwrite(&separator, 1, sizeof(separator), save);

    unsigned int snapshotWidth = FONVSAVE_MAX_SNAPSHOT_WIDTH;
    fwrite(&snapshotWidth, sizeof(snapshotWidth), 1, save);

    fwrite(&separator, 1, sizeof(separator), save);

    unsigned int snapshotHeight = FONVSAVE_MAX_SNAPSHOT_HEIGHT;
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

    short unsigned int playerLocationLength = 30;
    char playerLocation[] = "La Zona contaminata del Mojave";
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

    unsigned long snapshotLength = FONVSAVE_MAX_SNAPSHOT_LENGTH;
    unsigned char* snapshot = (unsigned char*)calloc(snapshotLength, 1);
    fwrite(snapshot, sizeof(*snapshot), snapshotLength, save);
    free(snapshot);

    fflush(save);

    fclose(save);

    free(emptyBuffer);

    return 0;
}
