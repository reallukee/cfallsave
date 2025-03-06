# Fallout: New Vegas API

> [Back to Documentation](../DOCS.md)

Source: [fonv.h](../src/fonv.h), [fonv.hpp](../src/cplusplus/fonv.hpp)



## Functions

* `FONVSAVE* readFONVSave(const char* saveName)`
* `bool isFONVSave(const char* saveName)`
* `void printFONVSave(FONVSAVE* save)`
* `void printFONVSaveSnapshot(FONVSAVE* save)`
* `void closeFONVSave(FONVSAVE* save)`



## Structures

### `FONVSAVE`

* `char saveSignature[FONVSAVE_SIGNATURE_LENGTH + 1]`
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

* `FONVSAVE_SIGNATURE`
* `FONVSAVE_SIGNATURE_LENGTH`
* `FONVSAVE_SIZE`



## Classes

> !IMPORTANT
> Only for C++

### `FONVSave`

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
