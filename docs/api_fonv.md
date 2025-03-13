<div align="center">

![Fallout: New Vegas Logo 192x192](../assets/fonv/fonv_logo_192x192.png)

# Fallout: New Vegas API

[Back to Documentation](../DOCS.md)

| Headers                               | Sources                               |
| :-----------------------------------: | :-----------------------------------: |
| [fonv.h](../src/fonv.h)               | [fonv.c](../src/fonv.c)               |
| [fonv.hpp](../src/cplusplus/fonv.hpp) | [fonv.cpp](../src/cplusplus/fonv.cpp) |

</div>



# Summary

* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)
* [Classes](#classes)



# Functions

* `FONVSAVE* readFONVSave(const char* saveName)`
* `bool writeFONVSave(FONVSAVE* save, char* saveName)`
* `bool isFONVSave(const char* saveName)`
* `void closeFONVSave(FONVSAVE* save)`
* `bool readFONVSaveProp(FONVSAVE* save, FONVSAVE_PROPS prop, void** value)`
* `bool writeFONVSaveProp(FONVSAVE* save, FONVSAVE_PROPS prop, void* value)`
* `bool printFONVSave(FONVSAVE* save)`
* `bool printFONVSaveProps(FONVSAVE* save)`
* `bool printFONVSavePropAddresses(FONVSAVE* save)`
* `bool printFONVSaveSnapshot(FONVSAVE* save)`



# Structures

## `FONVSAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FONVSAVE_SIGNATURE_LENGTH + 1]`
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
* `unsigned long propAddresses[FONVSAVE_PROPS_COUNT]`



# Enums

## `FONVSAVE_PROPS`

| Field                            | Value |
| :------------------------------- | :---: |
| `FONVSAVE_PROPS_SAVE_SIGNATURE`  | 0     |
| `FONVSAVE_PROPS_ENGINE_VERSION`  | 1     |
| `FONVSAVE_PROPS_SAVE_NUMBER`     | 2     |
| `FONVSAVE_PROPS_PLAYER_NAME`     | 3     |
| `FONVSAVE_PROPS_PLAYER_LEVEL`    | 4     |
| `FONVSAVE_PROPS_PLAYER_TITLE`    | 5     |
| `FONVSAVE_PROPS_PLAYER_LOCATION` | 6     |
| `FONVSAVE_PROPS_PLAYER_PLAYTIME` | 7     |
| `FONVSAVE_PROPS_SNAPSHOT_WIDTH`  | 8     |
| `FONVSAVE_PROPS_SNAPSHOT_HEIGHT` | 9     |
| `FONVSAVE_PROPS_SNAPHOST`        | 10    |



# Macros

| Macro                       | Value                |
| :-------------------------- | :------------------- |
| `FONVSAVE_GAME_NAME`        | "Fallout: New Vegas" |
| `FONVSAVE_SIGNATURE`        | "FO3SAVEGAME"        |
| `FONVSAVE_SIGNATURE_LENGTH` | 11                   |
| `FONVSAVE_PROPS_COUNT`      | 11                   |
| `FONVSAVE_PROPS_SIZE`       | ?                    |
| `FONVSAVE_SIZE`             | ?                    |



# Classes

> [!IMPORTANT]
> Only for C++

## `FONVSave`

* `FONVSave()`
* `FONVSave(string saveName)`
* `~FONVSave()`
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
