<div align="center">

![Fallout Tactics: Brotherhood of Steel Logo 192x192](../assets/fotbos/fotbos_logo_192x192.png)

# *Fallout Tactics: Brotherhood of Steel* Save Format

[Back to Documentation](../DOCS.md)

</div>



# Summary

* [Save File](#save-file)
* [Data Structure](#data-structure)
* [Data Types](#data-types)



# Save File

| Property          | Save Type                     | CFAllSave Type |
| :---------------- | :---------------------------- | :------------- |
| `Save Signature`  | `char[8]`                     | `char[8]`      |
| `Save Name`       | `short + "0x20 0x20" + char*` | `char*`        |
| `Player Name`     | `short + "0x20 0x20" + char*` | `char*`        |
| `Player Location` | `short + "0x20 0x20" + char*` | `char*`        |
| `Game Date Time`  | `short + "0x20 0x20" + char*` | `char*`        |



# Data Structure

> Headers: [`fotbos.h`](../src/fotbos.h)

```c
#define FOTBOSSAVE_GAME_NAME            "Fallout Tactics: Brotherhood of Steel"
#define FOTBOSSAVE_SIGNATURE            "<saveh>"
#define FOTBOSSAVE_SIGNATURE_LENGTH     7
#define FOTBOSSAVE_PROPS_COUNT          5
#define FOTBOSSAVE_SAVE_STANDARD_EXT    ".sav"

typedef enum FOTBOSSAVE_PROPS
{
    FOTBOSSAVE_PROPS_SAVE_SIGNATURE     = 0,
    FOTBOSSAVE_PROPS_SAVE_NAME          = 1,
    FOTBOSSAVE_PROPS_PLAYER_NAME        = 2,
    FOTBOSSAVE_PROPS_PLAYER_LOCATION    = 3,
    FOTBOSSAVE_PROPS_GAME_DATE_TIME     = 4
} FOTBOSSAVE_PROPS;

typedef struct FOTBOSSAVE
{
    FILE* save;

    char* saveFileName;

    char saveSignature[FOTBOSSAVE_SIGNATURE_LENGTH + 1];
    char* saveName;

    char* playerName;
    char* playerLocation;
    char* gameDateTime;

    long unsigned int propAddresses[FOTBOSSAVE_PROPS_COUNT];
} FOTBOSSAVE;

#define FOTBOSSAVE_PROPS_SIZE   sizeof(FOTBOSSAVE_PROPS)
#define FOTBOSSAVE_SIZE         sizeof(FOTBOSSAVE)
```



# Data Types

## `char[n]`

`char[n] = '\n'`
