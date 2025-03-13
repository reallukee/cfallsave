<div align="center">

![Fallout Tactics: Brotherhood of Steel Logo 192x192](../assets/fotbos/fotbos_logo_192x192.png)

# Fallout Tactics: Brotherhood of Steel API

[Back to Documentation](../DOCS.md)

| Headers                                   | Sources                                   |
| :---------------------------------------: | :---------------------------------------: |
| [fotbos.h](../src/fotbos.h)               | [fotbos.c](../src/fotbos.c)               |
| [fotbos.hpp](../src/cplusplus/fotbos.hpp) | [fotbos.cpp](../src/cplusplus/fotbos.cpp) |

</div>



# Summary

* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)
* [Classes](#classes)



# Functions

* `FOTBOSSAVE* readFOTBOSSave(const char* saveName)`
* `bool writeFOTBOSSave(FOTBOSSAVE* save, char* saveName)`
* `bool isFOTBOSSave(const char* saveName)`
* `void closeFOTBOSSave(FOTBOSSAVE* save)`
* `bool readFOTBOSSaveProp(FOTBOSSAVE* save, FOTBOSSAVE_PROPS prop, void** value)`
* `bool writeFOTBOSSaveProp(FOTBOSSAVE* save, FOTBOSSAVE_PROPS prop, void* value)`
* `bool printFOTBOSSave(FOTBOSSAVE* save)`
* `bool printFOTBOSSaveProps(FOTBOSSAVE* save)`
* `bool printFOTBOSSavePropAddresses(FOTBOSSAVE* save)`



# Structures

## `FOTBOSSAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FOTBOSSAVE_SIGNATURE_LENGTH + 1]`
* `char* saveName`
* `char* playerName`
* `char* playerLocation`
* `char* gameDateTime`
* `unsigned long propAddresses[FOTBOSSAVE_PROPS_COUNT]`



# Enums

## `FOTBOSSAVE_PROPS`

| Field                              | Value |
| :--------------------------------- | :---: |
| `FOTBOSSAVE_PROPS_SAVE_SIGNATURE`  | 0     |
| `FOTBOSSAVE_PROPS_SAVE_NAME`       | 1     |
| `FOTBOSSAVE_PROPS_PLAYER_NAME`     | 2     |
| `FOTBOSSAVE_PROPS_PLAYER_LOCATION` | 3     |
| `FOTBOSSAVE_PROPS_GAME_DATE_TIME`  | 4     |



# Macros

| Macro                         | Value                                   |
| :---------------------------- | :-------------------------------------- |
| `FOTBOSSAVE_GAME_NAME`        | "Fallout Tactics: Brotherhood of Steel" |
| `FOTBOSSAVE_SIGNATURE`        | "\<saveh\>"                             |
| `FOTBOSSAVE_SIGNATURE_LENGTH` | 7                                       |
| `FOTBOSSAVE_PROPS_COUNT`      | 5                                       |
| `FOTBOSSAVE_PROPS_SIZE`       | ?                                       |
| `FOTBOSSAVE_SIZE`             | ?                                       |



# Classes

> [!IMPORTANT]
> Only for C++

## `FOTBOSSave`

* `FOTBOSSave()`
* `FOTBOSSave(string saveName)`
* `~FOTBOSSave()`
* `void readSave(string saveName)`
* `bool isOpen()`
* `void printSave()`
* `string getSaveSignature()`
* `string getSaveName()`
* `string getPlayerName()`
* `string getPlayerLocation()`
* `string getGameDateTime()`
