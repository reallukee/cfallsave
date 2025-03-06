# Fallout Tactics: Brotherhood of Steel API

> [Back to Documentation](../DOCS.md)

Source: [fotbos.h](../src/fotbos.h), [fotbos.hpp](../src/cplusplus/fotbos.hpp)



## Functions

* `FOTBOSSAVE* readFOTBOSSave(const char* saveName)`
* `bool isFOTBOSSave(const char* saveName)`
* `void printFOTBOSSave(FOTBOSSAVE* save)`
* `void closeFOTBOSSave(FOTBOSSAVE* save)`



## Structures

### `FOTBOSSAVE`

* `char saveSignature[FOTBOS_SAVE_SIGNATURE_LENGTH + 1]`
* `char* saveName`
* `char* playerName`
* `char* playerLocation`
* `char* gameDateTime`



## Macros

* `FOTBOSSAVE_SIGNATURE`
* `FOTBOSSAVE_SIGNATURE_LENGTH`
* `FOTBOSSAVE_SIZE`



## Classes

> !IMPORTANT
> Only for C++

### `FOTBOSSave`

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
