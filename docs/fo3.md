# Fallout 3 API

> [Back to Documentation](../DOCS.md)

Source: [fo3.h](../src/fo3.h), [fo3.hpp](../src/cplusplus/fo3.hpp)



## Functions

* `FO3SAVE* readFO3Save(const char* saveName)`
* `bool isFO3Save(const char* saveName)`
* `void printFO3Save(FO3SAVE* save)`
* `void printFO3SaveSnapshot(FO3SAVE* save)`
* `void closeFO3Save(FO3SAVE* save)`



## Structures

### `FO3SAVE`

* `char saveSignature[FO3SAVE_SIGNATURE_LENGTH + 1]`
* `unsigned engineVersion`
* `unsigned saveNumber`
* `char* playerName`
* `unsigned playerLevel`
* `char* playerTitle`
* `char* playerLocation`
* `char* playerPlaytime`
* `unsigned snapshotWidth`
* `unsigned snapshotHeight`
* `unsigned char* snapshot`



## Macros

* `FO3SAVE_SIGNATURE`
* `FO3SAVE_SIGNATURE_LENGTH`
* `FO3SAVE_SIZE`



## Classes

> !IMPORTANT
> Only for C++

### `FO3Save`

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
