// Compile and execute using:
//
//   gcc fo4.c ../src/fo4.c -o fo4.out && ./fo4.out

#include "../src/fo4.h"

int main()
{
    FILE* save = fopen("fo4.fos", "wb");

    if (save == NULL)
    {
        return false;
    }

    unsigned char* emptyBuffer = (unsigned char*)calloc(64, 1);

    if (emptyBuffer == NULL)
    {
        return false;
    }

    fwrite(FO4SAVE_SIGNATURE, 1, FO4SAVE_SIGNATURE_LENGTH, save);

    fwrite(emptyBuffer, 4, sizeof(*emptyBuffer), save);

    unsigned int engineVersion = 15;
    fwrite(&engineVersion, sizeof(engineVersion), 1, save);

    unsigned int saveNumber = 100;
    fwrite(&saveNumber, sizeof(saveNumber), 1, save);

    short unsigned int playerNameLength = 12;
    char playerName[] = "John Fallout";
    fwrite(&playerNameLength, sizeof(playerNameLength), 1, save);
    fwrite(playerName, sizeof(*playerName), playerNameLength, save);

    unsigned int playerLevel = 150;
    fwrite(&playerLevel, sizeof(playerLevel), 1, save);

    short unsigned int playerLocationLength = 12;
    char playerLocation[] = "Commonwealth";
    fwrite(&playerLocationLength, sizeof(playerLocationLength), 1, save);
    fwrite(playerLocation, sizeof(*playerLocation), playerLocationLength, save);

    short unsigned int playerPlaytimeLength = 36;
    char playerPlaytime[] = "7g.00h.00m.7 giorni.00 ore.00 minuti";
    fwrite(&playerPlaytimeLength, sizeof(playerPlaytimeLength), 1, save);
    fwrite(playerPlaytime, sizeof(*playerPlaytime), playerPlaytimeLength, save);

    short unsigned int playerRaceLength = 9;
    char playerRace[] = "HumanRace";
    fwrite(&playerRaceLength, sizeof(playerRaceLength), 1, save);
    fwrite(playerRace, sizeof(*playerRace), playerRaceLength, save);

    short unsigned int playerSex = 0;
    fwrite(&playerSex, sizeof(playerSex), 1, save);

    float playerCurrentXp = 7500.0;
    fwrite(&playerCurrentXp, sizeof(playerCurrentXp), 1, save);

    float playerRequiredXp = 0.0;
    fwrite(&playerRequiredXp, sizeof(playerRequiredXp), 1, save);

    fwrite(emptyBuffer, 8, sizeof(*emptyBuffer), save);

    unsigned int snapshotWidth = FO4SAVE_MAX_SNAPSHOT_WIDTH;
    fwrite(&snapshotWidth, sizeof(snapshotWidth), 1, save);

    unsigned int snapshotHeight = FO4SAVE_MAX_SNAPSHOT_HEIGHT;
    fwrite(&snapshotHeight, sizeof(snapshotHeight), 1, save);

    unsigned long snapshotLength = FO4SAVE_MAX_SNAPSHOT_LENGTH;
    unsigned char* snapshot = (unsigned char*)calloc(snapshotLength, 1);
    fwrite(snapshot, sizeof(*snapshot), snapshotLength, save);
    free(snapshot);

    fflush(save);

    fclose(save);

    free(emptyBuffer);

    return 0;
}
