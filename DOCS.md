# Documentation

* [Fallout 1](#fallout-1)
* [Fallout 2](#fallout-2)
* [Fallout 3](#fallout-3)
* [Fallout: New Vegas](#fallout-new-vegas)
* [Fallout 4](#fallout-4)
* [Fallout X](#fallout-x)



## Fallout 1

Headers: [fo1.h](./src/fo1.h), [fo1.hpp](./src/cplusplus/fo1.hpp)

### Functions

* `FO1SAVE* readFO1Save(const char* saveName)`
* `bool isFO1Save(const char* saveName)`
* `void printFO1Save(FO1SAVE* save)`
* `void closeFO1Save(FO1SAVE* save)`

### Classes

> [!NOTE]
> Only if compiled as C++

* `FO1Save`
  * `FO1Save()`
  * `FO1Save(string saveName)`
  * `~FO1Save()`
  * `void readSave(string saveName)`
  * `void printSave()`
  * `string getSaveSignature()`
  * `string getSaveName()`
  * `string getPlayerName()`

### Structures

* `FO1SAVE`

### Constants

* `FO1SAVE_SIZE`



## Fallout 2

Headers: [fo2.h](./src/fo2.h), [fo2.hpp](./src/cplusplus/fo2.hpp)

### Functions

* `FO2SAVE* readFO2Save(const char* saveName)`
* `bool isFO2Save(const char* saveName)`
* `void printFO2Save(FO2SAVE* save)`
* `void closeFO2Save(FO2SAVE* save)`

### Classes

> [!NOTE]
> Only if compiled as C++

* `FO2Save`
  * `FO2Save()`
  * `FO2Save(string saveName)`
  * `~FO2Save()`
  * `void readSave(string saveName)`
  * `void printSave()`
  * `string getSaveSignature()`
  * `string getSaveName()`
  * `string getPlayerName()`

### Structures

* `FO2SAVE`

### Constants

* `FO2SAVE_SIZE`



## Fallout 3

Headers: [fo3.h](./src/fo3.h), [fo3.hpp](./src/cplusplus/fo3.hpp)

### Functions

* `FO3SAVE* readFO3Save(const char* saveName)`
* `bool isFO3Save(const char* saveName)`
* `void printFO3Save(FO3SAVE* save)`
* `void closeFO3Save(FO3SAVE* save)`

### Classes

> [!NOTE]
> Only if compiled as C++

* `FO3Save`
  * `FO3Save()`
  * `FO3Save(string saveName)`
  * `~FO3Save()`
  * `void readSave(string saveName)`
  * `void printSave()`
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

### Structures

* `FO3SAVE`

### Constants

* `FO3SAVE_SIZE`



## Fallout: New Vegas

Headers: [fonv.h](./src/fonv.h), [fonv.hpp](./src/cplusplus/fonv.hpp)

### Functions

* `FONVSAVE* readFONVSave(const char* saveName)`
* `bool isFONVSave(const char* saveName)`
* `void printFONVSave(FONVSAVE* save)`
* `void closeFONVSave(FONVSAVE* save)`

### Classes

> [!NOTE]
> Only if compiled as C++

* `FONVSave`
  * `FONVSave()`
  * `FONVSave(string saveName)`
  * `~FONVSave()`
  * `void readSave(string saveName)`
  * `void printSave()`
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

### Structures

* `FONVSAVE`

### Constants

* `FONVSAVE_SIZE`



## Fallout 4

Headers: [fo4.h](./src/fo4.h), [fo4.hpp](./src/cplusplus/fo4.hpp)

### Functions

* `FO4SAVE* readFO4Save(const char* saveName)`
* `bool isFO4Save(const char* saveName)`
* `void printFO4Save(FO4SAVE* save)`
* `void closeFO4Save(FO4SAVE* save)`

### Classes

> [!NOTE]
> Only if compiled as C++

* `FO4Save`
  * `FO4Save()`
  * `FO4Save(string saveName)`
  * `~FO4Save()`
  * `void readSave(string saveName)`
  * `void printSave()`
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

### Structures

* `FO4SAVE`

### Constants

* `FO4SAVE_SIZE`



## Fallout X

Headers: [fox.h](./src/fox.h)

### Functions

* 🧪 `FOXSAVE* readFOXSave(const char* saveName)`
* 🧪 `void printFOXSave(FOXSAVE* save)`
* 🧪 `void closeFOXSave(FOXSAVE* save)`

### Structures

* 🧪 `FOXSAVE`

### Enumerations

* 🧪 `FOXSAVE_TYPE`

### Constants

* 🧪 `FOXSAVE_SIZE`
