<div align="center">

![Fallout 3 Logo 192x192](../assets/fo3/fo3_logo_192x192.png)

# Fallout 3 Save Format

[Back to Documentation](../DOCS.md)

</div>



# Summary

* [Save File](#save-file)
* [Data Structure](#data-structure)
* [Data Types](#data-types)



# Save File

> [!NOTE]
> Fallout 3 Save Format IS VERY CLOSE to Fallout: New Vegas Save Format

| Property         | Save Type            | CFAllSave Type |
| :--------------- | :------------------- | :------------- |
| Save Signature   | char[12]             | char[12]       |
| Engine Version ? | unsigned             | unsigned       |
| Snapshot Width   | unsigned             | unsigned       |
| Snapshot Height  | unsigned             | unsigned       |
| Save Number      | unsigned             | unsigned       |
| Player Name      | short + '\|' + char* | char*          |
| Player Level     | unsigned             | unsigned       |
| Player Title     | short + '\|' + char* | char*          |
| Player Location  | short + '\|' + char* | char*          |
| Player Playtime  | short + '\|' + char* | char*          |
| Snapshot         | unsigned char*       | unsigned char* |



# Data Structure

> Source: [fo3.h](../src/fo3.h)

```c
#define FO3SAVE_GAME_NAME           "Fallout 3"
#define FO3SAVE_SIGNATURE           "FO3SAVEGAME"
#define FO3SAVE_SIGNATURE_LENGTH    11
#define FO3SAVE_PROPS_COUNT         11

typedef enum FO3SAVE_PROPS
{
    FO3SAVE_PROPS_SAVE_SIGNATURE    = 0,
    FO3SAVE_PROPS_ENGINE_VERSION    = 1,
    FO3SAVE_PROPS_SAVE_NUMBER       = 2,
    FO3SAVE_PROPS_PLAYER_NAME       = 3,
    FO3SAVE_PROPS_PLAYER_LEVEL      = 4,
    FO3SAVE_PROPS_PLAYER_TITLE      = 5,
    FO3SAVE_PROPS_PLAYER_LOCATION   = 6,
    FO3SAVE_PROPS_PLAYER_PLAYTIME   = 7,
    FO3SAVE_PROPS_SNAPSHOT_WIDTH    = 8,
    FO3SAVE_PROPS_SNAPSHOT_HEIGHT   = 9,
    FO3SAVE_PROPS_SNAPHOST          = 10
} FO3SAVE_PROPS;

#define FO3SAVE_MAX_SNAPSHOT_WIDTH      512
#define FO3SAVE_MAX_SNAPSHOT_HEIGHT     288
#define FO3SAVE_MAX_SNAPSHOT_LENGTH     442368

#define FO3SAVE_SNAPSHOT_COLOR_BYTES    3

typedef struct FO3SAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FO3SAVE_SIGNATURE_LENGTH + 1];
    unsigned int engineVersion;
    unsigned int saveNumber;

    char* playerName;
    unsigned int playerLevel;
    char* playerTitle;
    char* playerLocation;
    char* playerPlaytime;

    unsigned int snapshotWidth;
    unsigned int snapshotHeight;
    unsigned long snapshotLength;
    unsigned char* snapshot;

    unsigned long propAddresses[FO3SAVE_PROPS_COUNT];
} FO3SAVE;
```



# Data Types

## char[n]

`char[n] = '\n'`

## short + '|' + char*

```binary
0C 00   7C   4A 6F 68 6E 20 46 61 6C 6C 6F 75 74
```

| Bytes                               | Type      | Value        |
| :---------------------------------- | :-------- | :----------- |
| 0C 00                               | Length    | 12           |
| 7C                                  | Separator | \|           |
| 4A 6F 68 6E 20 46 61 6C 6C 6F 75 74 | Value     | John Fallout |
