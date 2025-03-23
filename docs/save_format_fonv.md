<div align="center">

![Fallout: New Vegas Logo 192x192](../assets/fonv/fonv_logo_192x192.png)

# *Fallout: New Vegas* Save Format

[Back to Documentation](../DOCS.md)

</div>



# Summary

* [Save File](#save-file)
* [Data Structure](#data-structure)
* [Data Types](#data-types)



# Save File

> [!NOTE]
> *Fallout: New Vegas* Save Format IS VERY CLOSE to *Fallout 3* Save Format

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

> Headers: [`fonv.h`](../src/fonv.h)

```c
#define FONVSAVE_GAME_NAME          "Fallout: New Vegas"
#define FONVSAVE_SIGNATURE          "FO3SAVEGAME"
#define FONVSAVE_SIGNATURE_LENGTH   11
#define FONVSAVE_PROPS_COUNT        11
#define FONVSAVE_SAVE_STANDARD_EXT  ".fos"

typedef enum FONVSAVE_PROPS
{
    FONVSAVE_PROPS_SAVE_SIGNATURE   = 0,
    FONVSAVE_PROPS_ENGINE_VERSION   = 1,
    FONVSAVE_PROPS_SAVE_NUMBER      = 2,
    FONVSAVE_PROPS_PLAYER_NAME      = 3,
    FONVSAVE_PROPS_PLAYER_LEVEL     = 4,
    FONVSAVE_PROPS_PLAYER_TITLE     = 5,
    FONVSAVE_PROPS_PLAYER_LOCATION  = 6,
    FONVSAVE_PROPS_PLAYER_PLAYTIME  = 7,
    FONVSAVE_PROPS_SNAPSHOT_WIDTH   = 8,
    FONVSAVE_PROPS_SNAPSHOT_HEIGHT  = 9,
    FONVSAVE_PROPS_SNAPSHOT         = 10
} FONVSAVE_PROPS;

#define FONVSAVE_MAX_SNAPSHOT_WIDTH     512
#define FONVSAVE_MAX_SNAPSHOT_HEIGHT    288
#define FONVSAVE_MAX_SNAPSHOT_LENGTH    442368

#define FONVSAVE_SNAPSHOT_COLOR_BYTES   3

typedef struct FONVSAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FONVSAVE_SIGNATURE_LENGTH + 1];
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

    long unsigned int propAddresses[FONVSAVE_PROPS_COUNT];
} FONVSAVE;

#define FONVSAVE_PROPS_SIZE sizeof(FONVSAVE_PROPS)
#define FONVSAVE_SIZE       sizeof(FONVSAVE)
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
