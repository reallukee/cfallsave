<div align="center">

![Fallout 3 Logo 192x192](../assets/fo3/fo3_logo_192x192.png)

# *Fallout 3* Save Format

[Back to Documentation](../DOCS.md)

</div>



# Summary

* [Save File](#save-file)
* [Data Structure](#data-structure)
* [Data Types](#data-types)



# Save File

> [!NOTE]
> *Fallout 3* Save Format IS VERY CLOSE to *Fallout: New Vegas* Save Format

| Property           | Save Type                           | CFAllSave Type   |
| :----------------- | :---------------------------------- | :--------------- |
| `Save Signature`   | `char[12]`                          | `char[12]`       |
| `Engine Version` ? | `unsigned int`                      | `unsigned int`   |
| `Snapshot Width`   | `unsigned int`                      | `unsigned int`   |
| `Snapshot Height`  | `unsigned int`                      | `unsigned int`   |
| `Save Number`      | `unsigned int`                      | `unsigned int`   |
| `Player Name`      | `short unsigned int + '\|' + char*` | `char*`          |
| `Player Level`     | `unsigned int`                      | `unsigned int`   |
| `Player Title`     | `short unsigned int + '\|' + char*` | `char*`          |
| `Player Location`  | `short unsigned int + '\|' + char*` | `char*`          |
| `Player Playtime`  | `short unsigned int + '\|' + char*` | `char*`          |
| `Snapshot`         | `unsigned char*`                    | `unsigned char*` |

## Snapshot

RGB



# Data Structure

> Headers: [`fo3.h`](../src/fo3.h)

```c
#define FO3SAVE_GAME_NAME           "Fallout 3"
#define FO3SAVE_SIGNATURE           "FO3SAVEGAME"
#define FO3SAVE_SIGNATURE_LENGTH    11
#define FO3SAVE_PROPS_COUNT         11
#define FO3SAVE_SAVE_STANDARD_EXT   ".fos"

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
    FO3SAVE_PROPS_SNAPSHOT          = 10
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
    long unsigned int snapshotLength;
    unsigned char* snapshot;

    long unsigned int propAddresses[FO3SAVE_PROPS_COUNT];
} FO3SAVE;

#define FO3SAVE_PROPS_SIZE  sizeof(FO3SAVE_PROPS)
#define FO3SAVE_SIZE        sizeof(FO3SAVE)
```



# Data Types

## `char[n]`

`char[n] = '\n'`

## `short unsigned int + '|' + char*`

```binary
0C 00   7C   4A 6F 68 6E 20 46 61 6C 6C 6F 75 74
```

| Bytes                                 | Type      | Value          |
| :------------------------------------ | :-------- | :------------- |
| `0C 00`                               | Length    | `12`           |
| `7C`                                  | Separator | `\|`           |
| `4A 6F 68 6E 20 46 61 6C 6C 6F 75 74` | Value     | `John Fallout` |
