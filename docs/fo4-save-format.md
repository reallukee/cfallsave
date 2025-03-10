# Fallout 4 Save File Format

> [Back to Documentation](../DOCS.md)



| Property           | Type           | CFAllSave Type |
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



## Data Structure

Source: [fo4.h](../src/fo4.h)

```c
#define FO4SAVE_SIGNATURE           "FO4_SAVEGAME"
#define FO4SAVE_SIGNATURE_LENGTH    12

typedef struct FO4SAVE
{
    char saveSignature[FO4SAVE_SIGNATURE_LENGTH + 1];
    unsigned engineVersion;
    unsigned saveNumber;

    char* playerName;
    unsigned playerLevel;
    char* playerLocation;
    char* playerPlaytime;
    char* playerRace;
    unsigned short playerSex;
    float playerCurrentXp;
    float playerRequiredXp;

    unsigned snapshotWidth;
    unsigned snapshotHeight;
    unsigned char* snapshot;
} FO4SAVE;
```



## Data Types

### char[n]

`char[n] = '\n'`

### short + char*

```binary
0C 00   4A 6F 68 6E 20 46 61 6C 6C 6F 75 74
```

| Bytes                               | Type   | Value        |
| :---------------------------------- | :----- | :----------- |
| 0C 00                               | Length | 12           |
| 4A 6F 68 6E 20 46 61 6C 6C 6F 75 74 | Value  | John Fallout |
