# Fallout 4 API

> [Back to Documentation](../DOCS.md)

Source: [fo4.h](../src/fo4.h), [fo4.hpp](../src/cplusplus/fo4.hpp)



## Functions

* `FO4SAVE* readFO4Save(const char* saveName)`
* `bool isFO4Save(const char* saveName)`
* `void printFO4Save(FO4SAVE* save)`
* `void printFO4SaveSnapshot(FO4SAVE* save)`
* `void closeFO4Save(FO4SAVE* save)`



## Structures

### `FO4SAVE`

* `char saveSignature[FO4SAVE_SIGNATURE_LENGTH + 1]`
* `unsigned engineVersion`
* `unsigned saveNumber`
* `char* playerName`
* `unsigned playerLevel`
* `char* playerLocation`
* `char* playerPlaytime`
* `char* playerRace`
* `unsigned short playerSex`
* `float playerCurrentXp`
* `float playerRequiredXp`
* `unsigned snapshotWidth`
* `unsigned snapshotHeight`
* `unsigned char* snapshot`



## Macros

* `FO4SAVE_SIGNATURE`
* `FO4SAVE_SIGNATURE_LENGTH`
* `FO4SAVE_SIZE`



## Classes

> !IMPORTANT
> Only for C++

### `FO4Save`

* `FO4Save()`
* `FO4Save(string saveName)`
* `~FO4Save()`
* `void readSave(string saveName)`
* `bool isOpen()`
* `void printSave()`
* `void printSaveSnapshot()`
* `string getSaveSignature()`
* `unsigned getEngineVersion()`
* `unsigned getSaveNumber()`
* `string getPlayerName()`
* `unsigned getPlayerLevel()`
* `string getPlayerLocation()`
* `string getPlayerPlaytime()`
* `string getPlayerRace()`
* `unsigned short getPlayerSex()`
* `float getPlayerCurrentXp()`
* `float getPlayerRequiredXp()`
* `unsigned getSnapshotWidth()`
* `unsigned getSnapshotHeight()`
* `unsigned char* getSnapshot()`
