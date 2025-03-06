# Fallout 2 API

> [Back to Documentation](../DOCS.md)

Source: [fo2.h](../src/fo2.h), [fo2.hpp](../src/cplusplus/fo2.hpp)



## Functions

* `FO2SAVE* readFO2Save(const char* saveName)`
* `bool isFO2Save(const char* saveName)`
* `void printFO2Save(FO2SAVE* save)`
* `void closeFO2Save(FO2SAVE* save)`



## Structures

### `FO2SAVE`

* `char saveSignature[FO2SAVE_SIGNATURE_LENGTH + 1]`
* `char saveName[32]`
* `char playerName[32]`



## Macros

* `FO2SAVE_SIGNATURE`
* `FO2SAVE_SIGNATURE_LENGTH`
* `FO2SAVE_SIZE`



## Classes

> !IMPORTANT
> Only for C++

### `FO2Save`

* `FO2Save()`
* `FO2Save(string saveName)`
* `~FO2Save()`
* `void readSave(string saveName)`
* `bool isOpen()`
* `void printSave()`
* `string getSaveSignature()`
* `string getSaveName()`
* `string getPlayerName()`
