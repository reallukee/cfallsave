<div align="center">

![Fallout 2 Logo 192x192](../assets/fo2/fo2_logo_192x192.png)

# Fallout 2 API

[Back to Documentation](../DOCS.md)

| Headers                             | Sources                             |
| :---------------------------------: | :---------------------------------: |
| [fo2.h](../src/fo2.h)               | [fo2.c](../src/fo2.c)               |
| [fo2.hpp](../src/cplusplus/fo2.hpp) | [fo2.cpp](../src/cplusplus/fo2.cpp) |

</div>



# Summary

* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)
* [Classes](#classes)



# Functions

* `FO2SAVE* readFO2Save(const char* saveName)`
* `bool writeFO2Save(FO2SAVE* save, char* saveName)`
* `bool isFO2Save(const char* saveName)`
* `void closeFO2Save(FO2SAVE* save)`
* `bool readFO2SaveProp(FO2SAVE* save, FO2SAVE_PROPS prop, void** value)`
* `bool writeFO2SaveProp(FO2SAVE* save, FO2SAVE_PROPS prop, void* value)`
* `bool printFO2Save(FO2SAVE* save)`
* `bool printFO2SaveProps(FO2SAVE* save)`
* `bool printFO2SavePropAddresses(FO2SAVE* save)`



# Structures

## `FO2SAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FO2SAVE_SIGNATURE_LENGTH + 1]`
* `char saveName[32]`
* `char playerName[32]`
* `unsigned long propAddresses[FO2SAVE_PROPS_COUNT]`



# Enums

## `FO2SAVE_PROPS`

| Field                          | Value |
| :----------------------------- | :---: |
| `FO2SAVE_PROPS_SAVE_SIGNATURE` | 0     |
| `FO2SAVE_PROPS_SAVE_NAME`      | 1     |
| `FO2SAVE_PROPS_PLAYER_NAME`    | 2     |



# Macros

| Macro                      | Value               |
| :------------------------- | :------------------ |
| `FO2SAVE_GAME_NAME`        | "Fallout 2"         |
| `FO2SAVE_SIGNATURE`        | "FALLOUT SAVE FILE" |
| `FO2SAVE_SIGNATURE_LENGTH` | 17                  |
| `FO2SAVE_PROPS_COUNT`      | 3                   |
| `FO2SAVE_PROPS_SIZE`       | ?                   |
| `FO2SAVE_SIZE`             | ?                   |




# Classes

> [!IMPORTANT]
> Only for C++

## `FO2Save`

* `FO2Save()`
* `FO2Save(string saveName)`
* `~FO2Save()`
* `void readSave(string saveName)`
* `bool isOpen()`
* `void printSave()`
* `string getSaveSignature()`
* `string getSaveName()`
* `string getPlayerName()`
