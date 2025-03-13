<div align="center">

![Fallout 4 Logo 192x192](../assets/fo4/fo4_logo_192x192.png)

# Fallout 4 API

[Back to Documentation](../DOCS.md)

| Headers                             | Sources                             |
| :---------------------------------: | :---------------------------------: |
| [fo4.h](../src/fo4.h)               | [fo4.c](../src/fo4.c)               |
| [fo4.hpp](../src/cplusplus/fo4.hpp) | [fo4.cpp](../src/cplusplus/fo4.cpp) |

</div>



# Summary

* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)
* [Classes](#classes)



# Functions

* `FO4SAVE* readFO4Save(const char* saveName)`
* `bool writeFO4Save(FO4SAVE* save, char* saveName)`
* `bool isFO4Save(const char* saveName)`
* `void closeFO4Save(FO4SAVE* save)`
* `bool readFO4SaveProp(FO4SAVE* save, FO4SAVE_PROPS prop, void** value)`
* `bool writeFO4SaveProp(FO4SAVE* save, FO4SAVE_PROPS prop, void* value)`
* `bool printFO4Save(FO4SAVE* save)`
* `bool printFO4SaveProps(FO4SAVE* save)`
* `bool printFO4SavePropAddresses(FO4SAVE* save)`
* `bool printFO4SaveSnapshot(FO4SAVE* save)`



# Structures

## `FO4SAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FO4SAVE_SIGNATURE_LENGTH + 1]`
* `unsigned engineVersion`
* `unsigned saveNumber`
* `char* playerName`
* `unsigned playerLevel`
* `char* playerLocation`
* `char* playerPlaytime`
* `char* playerRace`
* `unsigned short playerSex`
* `float playerCurrentXp`
* `float playerRequiredXp`
* `unsigned snapshotWidth`
* `unsigned snapshotHeight`
* `unsigned long snapshotLength`
* `unsigned char* snapshot`
* `unsigned long propAddresses[FO4SAVE_PROPS_COUNT]`



# Enums

## `FO4SAVE_PROPS`

| Field                              | Value |
| :--------------------------------- | :---: |
| `FO4SAVE_PROPS_SAVE_SIGNATURE`     | 0     |
| `FO4SAVE_PROPS_ENGINE_VERSION`     | 1     |
| `FO4SAVE_PROPS_SAVE_NUMBER`        | 2     |
| `FO4SAVE_PROPS_PLAYER_NAME`        | 3     |
| `FO4SAVE_PROPS_PLAYER_LEVEL`       | 4     |
| `FO4SAVE_PROPS_PLAYER_LOCATION`    | 5     |
| `FO4SAVE_PROPS_PLAYER_PLAYTIME `   | 6     |
| `FO4SAVE_PROPS_PLAYER_RACE`        | 7     |
| `FO4SAVE_PROPS_PLAYER_SEX`         | 8     |
| `FO4SAVE_PROPS_PLAYER_CURRENT_XP`  | 9     |
| `FO4SAVE_PROPS_PLAYER_REQUIRED_XP` | 10    |
| `FO4SAVE_PROPS_SNAPSHOT_WIDTH`     | 11    |
| `FO4SAVE_PROPS_SNAPSHOT_HEIGHT`    | 12    |
| `FO4SAVE_PROPS_SNAPSHOT`           | 13    |



# Macros

| Macro                      | Value          |
| :------------------------- | :------------- |
| `FO4SAVE_GAME_NAME`        | "Fallout 4"    |
| `FO4SAVE_SIGNATURE`        | "FO4_SAVEGAME" |
| `FO4SAVE_SIGNATURE_LENGTH` | 12             |
| `FO4SAVE_PROPS_COUNT`      | 14             |
| `FO4SAVE_PROPS_SIZE`       | ?              |
| `FO4SAVE_SIZE`             | ?              |



# Classes

> [!IMPORTANT]
> Only for C++

## `FO4Save`

* `FO4Save()`
* `FO4Save(string saveName)`
* `~FO4Save()`
* `void readSave(string saveName)`
* `bool isOpen()`
* `void printSave()`
* `void printSaveSnapshot()`
* `string getSaveSignature()`
* `unsigned getEngineVersion()`
* `unsigned getSaveNumber()`
* `string getPlayerName()`
* `unsigned getPlayerLevel()`
* `string getPlayerLocation()`
* `string getPlayerPlaytime()`
* `string getPlayerRace()`
* `unsigned short getPlayerSex()`
* `float getPlayerCurrentXp()`
* `float getPlayerRequiredXp()`
* `unsigned getSnapshotWidth()`
* `unsigned getSnapshotHeight()`
* `unsigned char* getSnapshot()`
