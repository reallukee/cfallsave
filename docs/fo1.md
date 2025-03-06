# Fallout 1 API

> [Back to Documentation](../DOCS.md)

Source: [fo1.h](../src/fo1.h), [fo1.hpp](../src/cplusplus/fo1.hpp)



## Functions

* `FO1SAVE* readFO1Save(const char* saveName)`
* `bool isFO1Save(const char* saveName)`
* `void printFO1Save(FO1SAVE* save)`
* `void closeFO1Save(FO1SAVE* save)`



## Structures

### `FO1SAVE`

* `char saveSignature[FO1SAVE_SIGNATURE_LENGTH + 1]`
* `char saveName[32]`
* `char playerName[32]`



## Macros

* `FO1SAVE_SIGNATURE`
* `FO1SAVE_SIGNATURE_LENGTH`
* `FO1SAVE_SIZE`



## Classes

> !IMPORTANT
> Only for C++

### `FO1Save`

* `FO1Save()`
* `FO1Save(string saveName)`
* `~FO1Save()`
* `void readSave(string saveName)`
* `bool isOpen()`
* `void printSave()`
* `string getSaveSignature()`
* `string getSaveName()`
* `string getPlayerName()`
