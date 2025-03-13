<div align="center">

![Fallout 3 Logo 192x192](../assets/fo3/fo3_logo_192x192.png)

# Fallout 3 API

[Back to Documentation](../DOCS.md)

| Headers                             | Sources                             |
| :---------------------------------: | :---------------------------------: |
| [fo3.h](../src/fo3.h)               | [fo3.c](../src/fo3.c)               |
| [fo3.hpp](../src/cplusplus/fo3.hpp) | [fo3.cpp](../src/cplusplus/fo3.cpp) |

</div>



# Summary

* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)
* [Classes](#classes)



# Functions

* `FO3SAVE* readFO3Save(const char* saveName)`
* `bool writeFO3Save(FO3SAVE* save, char* saveName)`
* `bool isFO3Save(const char* saveName)`
* `void closeFO3Save(FO3SAVE* save)`
* `bool readFO3SaveProp(FO3SAVE* save, FO3SAVE_PROPS prop, void** value)`
* `bool writeFO3SaveProp(FO3SAVE* save, FO3SAVE_PROPS prop, void* value)`
* `bool printFO3Save(FO3SAVE* save)`
* `bool printFO3SaveProps(FO3SAVE* save)`
* `bool printFO3SavePropAddresses(FO3SAVE* save)`
* `bool printFO3SaveSnapshot(FO3SAVE* save)`



# Structures

## `FO3SAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FO3SAVE_SIGNATURE_LENGTH + 1]`
* `unsigned int engineVersion`
* `unsigned int saveNumber`
* `char* playerName`
* `unsigned int playerLevel`
* `char* playerTitle`
* `char* playerLocation`
* `char* playerPlaytime`
* `unsigned int snapshotWidth`
* `unsigned int snapshotHeight`
* `unsigned long snapshotLength`
* `unsigned char* snapshot`
* `unsigned long propAddresses[FO3SAVE_PROPS_COUNT]`



# Enums

## `FO3SAVE_PROPS`

| Field                           | Value |
| :------------------------------ | :---: |
| `FO3SAVE_PROPS_SAVE_SIGNATURE`  | 0     |
| `FO3SAVE_PROPS_ENGINE_VERSION`  | 1     |
| `FO3SAVE_PROPS_SAVE_NUMBER`     | 2     |
| `FO3SAVE_PROPS_PLAYER_NAME`     | 3     |
| `FO3SAVE_PROPS_PLAYER_LEVEL`    | 4     |
| `FO3SAVE_PROPS_PLAYER_TITLE`    | 5     |
| `FO3SAVE_PROPS_PLAYER_LOCATION` | 6     |
| `FO3SAVE_PROPS_PLAYER_PLAYTIME` | 7     |
| `FO3SAVE_PROPS_SNAPSHOT_WIDTH`  | 8     |
| `FO3SAVE_PROPS_SNAPSHOT_HEIGHT` | 9     |
| `FO3SAVE_PROPS_SNAPHOST`        | 10    |



# Macros

| Macro                      | Value         |
| :------------------------- | :------------ |
| `FO3SAVE_GAME_NAME`        | "Fallout 3"   |
| `FO3SAVE_SIGNATURE`        | "FO3SAVEGAME" |
| `FO3SAVE_SIGNATURE_LENGTH` | 11            |
| `FO3SAVE_PROPS_COUNT`      | 11            |
| `FO3SAVE_PROPS_SIZE`       | ?             |
| `FO3SAVE_SIZE`             | ?             |



# Classes

> [!IMPORTANT]
> Only for C++

## `FO3Save`

* `FO3Save()`
* `FO3Save(string saveName)`
* `~FO3Save()`
* `void readSave(string saveName)`
* `bool isOpen()`
* `void printSave()`
* `void printSaveSnapshot()`
* `string getSaveSignature()`
* `unsigned getEngineVersion()`
* `unsigned getSaveNumber()`
* `string getPlayerName()`
* `unsigned getPlayerLevel()`
* `string getPlayerTitle()`
* `string getPlayerLocation()`
* `string getPlayerPlaytime()`
* `unsigned getSnapshotWidth()`
* `unsigned getSnapshotHeight()`
* `unsigned char* getSnapshot()`
