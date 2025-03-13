<div align="center">

![Fallout 1 Logo 192x192](../assets/fo1/fo1_logo_192x192.png)

# Fallout 1 API

[Back to Documentation](../DOCS.md)

| Headers                             | Sources                             |
| :---------------------------------: | :---------------------------------: |
| [fo1.h](../src/fo1.h)               | [fo1.c](../src/fo1.c)               |
| [fo1.hpp](../src/cplusplus/fo1.hpp) | [fo1.cpp](../src/cplusplus/fo1.cpp) |

</div>



# Summary

* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)
* [Classes](#classes)



# Functions

* `FO1SAVE* readFO1Save(const char* saveName)`
* `bool writeFO1Save(FO1SAVE* save, char* saveName)`
* `bool isFO1Save(const char* saveName)`
* `void closeFO1Save(FO1SAVE* save)`
* `bool readFO1SaveProp(FO1SAVE* save, FO1SAVE_PROPS prop, void** value)`
* `bool writeFO1SaveProp(FO1SAVE* save, FO1SAVE_PROPS prop, void* value)`
* `bool printFO1Save(FO1SAVE* save)`
* `bool printFO1SaveProps(FO1SAVE* save)`
* `bool printFO1SavePropAddresses(FO1SAVE* save)`



# Structures

## `FO1SAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FO1SAVE_SIGNATURE_LENGTH + 1]`
* `char saveName[32]`
* `char playerName[32]`
* `unsigned long propAddresses[FO1SAVE_PROPS_COUNT]`



# Enums

## `FO1SAVE_PROPS`

| Field                          | Value |
| :----------------------------- | :---: |
| `FO1SAVE_PROPS_SAVE_SIGNATURE` | 0     |
| `FO1SAVE_PROPS_SAVE_NAME`      | 1     |
| `FO1SAVE_PROPS_PLAYER_NAME`    | 2     |



# Macros

| Macro                      | Value               |
| :------------------------- | :------------------ |
| `FO1SAVE_GAME_NAME`        | "Fallout 1"         |
| `FO1SAVE_SIGNATURE`        | "FALLOUT SAVE FILE" |
| `FO1SAVE_SIGNATURE_LENGTH` | 17                  |
| `FO1SAVE_PROPS_COUNT`      | 3                   |
| `FO1SAVE_PROPS_SIZE`       | ?                   |
| `FO1SAVE_SIZE`             | ?                   |




# Classes

> [!IMPORTANT]
> Only for C++

## `FO1Save`

* `FO1Save()`
* `FO1Save(string saveName)`
* `~FO1Save()`
* `void readSave(string saveName)`
* `bool isOpen()`
* `void printSave()`
* `string getSaveSignature()`
* `string getSaveName()`
* `string getPlayerName()`
