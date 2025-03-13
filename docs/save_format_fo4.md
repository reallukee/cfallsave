<div align="center">

![Fallout 4 Logo 192x192](../assets/fo4/fo4_logo_192x192.png)

# Fallout 4 Save Format

[Back to Documentation](../DOCS.md)

</div>



# Summary

* [Save File](#save-file)
* [Data Structure](#data-structure)
* [Data Types](#data-types)



# Save File

| Property           | Save Type      | CFAllSave Type |
| :----------------- | :------------- | :------------- |
| Save Signature     | char[13]       | char[13]       |
| Engine Version     | unsigned       | unsigned       |
| Save Number        | unsigned       | unsigned       |
| Player Name        | short + char*  | char*          |
| Player Level       | unsigned       | unsigned       |
| Player Location    | short + char*  | char*          |
| Player Playtime    | short + char*  | char*          |
| Player Race        | short + char*  | char*          |
| Player Sex         | unsigned short | unsigned short |
| Player Current Xp  | float          | float          |
| Player Required Xp | float          | float          |
| Snapshot Width     | unsigned       | unsigned       |
| Snapshot Height    | unsigned       | unsigned       |
| Snapshot           | unsigned char* | unsigned char* |



# Data Structure

> Source: [fo4.h](../src/fo4.h)

```c
#define FO4SAVE_GAME_NAME           "Fallout 4"
#define FO4SAVE_SIGNATURE           "FO4_SAVEGAME"
#define FO4SAVE_SIGNATURE_LENGTH    12
#define FO4SAVE_PROPS_COUNT         14

typedef enum FO4SAVE_PROPS
{
    FO4SAVE_PROPS_SAVE_SIGNATURE        = 0,
    FO4SAVE_PROPS_ENGINE_VERSION        = 1,
    FO4SAVE_PROPS_SAVE_NUMBER           = 2,
    FO4SAVE_PROPS_PLAYER_NAME           = 3,
    FO4SAVE_PROPS_PLAYER_LEVEL          = 4,
    FO4SAVE_PROPS_PLAYER_LOCATION       = 5,
    FO4SAVE_PROPS_PLAYER_PLAYTIME       = 6,
    FO4SAVE_PROPS_PLAYER_RACE           = 7,
    FO4SAVE_PROPS_PLAYER_SEX            = 8,
    FO4SAVE_PROPS_PLAYER_CURRENT_XP     = 9,
    FO4SAVE_PROPS_PLAYER_REQUIRED_XP    = 10,
    FO4SAVE_PROPS_SNAPSHOT_WIDTH        = 11,
    FO4SAVE_PROPS_SNAPSHOT_HEIGHT       = 12,
    FO4SAVE_PROPS_SNAPSHOT              = 13
} FO4SAVE_PROPS;

#define FO4SAVE_MAX_SNAPSHOT_WIDTH      640
#define FO4SAVE_MAX_SNAPSHOT_HEIGHT     384
#define FO4SAVE_MAX_SNAPSHOT_LENGTH     983040

#define FO4SAVE_SNAPSHOT_COLOR_BYTES    4

typedef struct FO4SAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FO4SAVE_SIGNATURE_LENGTH + 1];
    unsigned int engineVersion;
    unsigned int saveNumber;

    char* playerName;
    unsigned int playerLevel;
    char* playerLocation;
    char* playerPlaytime;
    char* playerRace;
    unsigned short playerSex;
    float playerCurrentXp;
    float playerRequiredXp;

    unsigned int snapshotWidth;
    unsigned int snapshotHeight;
    unsigned long snapshotLength;
    unsigned char* snapshot;

    unsigned long propAddresses[FO4SAVE_PROPS_COUNT];
} FO4SAVE;
```



# Data Types

## char[n]

`char[n] = '\n'`

## short + char*

```binary
0C 00   4A 6F 68 6E 20 46 61 6C 6C 6F 75 74
```

| Bytes                               | Type   | Value        |
| :---------------------------------- | :----- | :----------- |
| 0C 00                               | Length | 12           |
| 4A 6F 68 6E 20 46 61 6C 6C 6F 75 74 | Value  | John Fallout |
