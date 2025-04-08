<div align="center">

![Fallout 3 Logo 192x192](../assets/fo3/fo3_logo_192x192.png)

# *Fallout 3* C++ API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout 3* C API?<br />
> Click [here](./api_fo3.md)!

> [!IMPORTANT]
> These APIs are a Wrapper of the *Fallout 3* C APIs.<br />
> The C APIs are available [here](./api_fo3.md).



# Summary

* [Code](#code)
* [Namespaces](#namespaces)
* [Enums](#enums)
* [Classes](#classes)



# Code

> Headers: [`fo3.hpp`](../src/cplusplus/fo3.hpp)

> Sources: [`fo3.cpp`](../src/cplusplus/fo3.cpp)



# Namespaces

* [`cfallsave`](./api_fo3.md)
* `cfallsavepp`



# Enums

## `FO3SaveProps`

| Field            | Value |
| :--------------- | :---: |
| `SaveSignature`  | `0`   |
| `EngineVersion`  | `1`   |
| `SaveNumber`     | `2`   |
| `PlayerName`     | `3`   |
| `PlayerLevel`    | `4`   |
| `PlayerTitle`    | `5`   |
| `PlayerLocation` | `6`   |
| `PlayerPlaytime` | `7`   |
| `SnapshotWidth`  | `8`   |
| `SnapshotHeight` | `9`   |
| `Snapshot`       | `10`  |



# Classes

## `FO3Save`

- [`getFO3Save`](#fo3savegetfo3save)
- [`setFO3Save`](#fo3savesetfo3save)
- [`FO3Save`](#fo3savefo3save)
- [`~FO3Save`](#fo3savefo3save-1)
- [`readSave`](#fo3savereadsave)
- [`writeSave`](#fo3savewritesave)
- [`closeSave`](#fo3saveclosesave)
- [`isSave` (*static*)](#fo3saveissave-static)
- [`isOpen`](#fo3saveisopen)
- [`printSave`](#fo3saveprintsave)
- [`printSaveProps`](#fo3saveprintsaveprops)
- [`printSavePropAddresses`](#fo3saveprintsavepropaddresses)
- [`printSaveSnapshot`](#fo3saveprintsavesnapshot)
- [`getGameName`](#fo3savegetgamename)
- [`getSaveFileName`](#fo3savegetsavefilename)
- [`getSaveSignature`](#fo3savegetsavesignature)
- [`getEngineVersion`](#fo3savegetengineversion)
- [`getSaveNumber`](#fo3savegetsavenumber)
- [`getPlayerName`](#fo3savegetplayername)
- [`getPlayerLevel`](#fo3savegetplayerlevel)
- [`getPlayerTitle`](#fo3savegetplayertitle)
- [`getPlayerLocation`](#fo3savegetplayerlocation)
- [`getPlayerPlaytime`](#fo3savegetplayerplaytime)
- [`getSnapshotWidth`](#fo3savegetsnapshotwidth)
- [`getSnapshotHeight`](#fo3savegetsnapshotheight)
- [`getSnapshotLength`](#fo3savegetsnapshotlength)
- [`getSnapshot`](#fo3savegetsnapshot)



## `FO3Save::getFO3SAVE`

**Params**

* `void`

**Returns**

[`FO3SAVE*`](./api_fo3.md#fo3save) or `NULL`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

FO3SAVE* save = savepp->getFO3SAVE();
```



## `FO3Save::setFO3SAVE`

**Params**

[`FO3SAVE*`](./api_fo3.md#fo3save) `save`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save();

FO3SAVE* save = readFO3Save("fo3.fos");

savepp->setFO3SAVE(save);
```



## `FO3Save::FO3Save`

**Params**

* `void`

    Or

* [`FO3SAVE*`](./api_fo3.md#fo3save) `save`

    Or

* `string` `saveName`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save();
```

```cpp
FO3SAVE* save = readFO3Save("fo3.fos");

FO3Save* savepp = new FO3Save(save);
```

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");
```



## `FO3Save::~FO3Save`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

delete savepp;
```



## `FO3Save::readSave`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FO3Save* savepp = new FO3Save();

bool result = savepp->readSave("fo3.fos");

if (result) {
    printf("FO3 Save File Read\n");
}
```



## `FO3Save::writeSave`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

bool result = savepp->writeSave();

if (result) {
    printf("FO3 Save File Written\n");
}
```



## `FO3Save::closeSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

savepp->closeSave();
```



## `FO3Save::isSave` (*static*)

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
bool result = FO3Save::isSave("fo3.fos");

if (result) {
    printf("FO3 Save!\n");
}
```



## `FO3Save::isOpen`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

bool result = savepp->isOpen();

if (result) {
    printf("FO3 Save is Open\n");
}
```



## `FO3Save::printSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

savepp->printSave();
```



## `FO3Save::printSaveProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

savepp->printSaveProps();
```



## `FO3Save::printSavePropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

savepp->printSavePropAddresses();
```



## `FO3Save::printSaveSnapshot`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

savepp->printSaveSnapshot();
```



## `FO3Save::getGameName`

**Params**

* `void`

**Returns**

`string`



## `FO3Save::getSaveFileName`

**Params**

* `void`

**Returns**

`string`



## `FO3Save::getSaveSignature`

**Params**

* `void`

**Returns**

`string`



## `FO3Save::getEngineVersion`

**Params**

* `void`

**Returns**

`unsigned int`



## `FO3Save::getSaveNumber`

**Params**

* `void`

**Returns**

`unsigned int`



## `FO3Save::getPlayerName`

**Params**

* `void`

**Returns**

`string`




## `FO3Save::getPlayerLevel`

**Params**

* `void`

**Returns**

`unsigned int`



## `FO3Save::getPlayerTitle`

**Params**

* `void`

**Returns**

`string`



## `FO3Save::getPlayerLocation`

**Params**

* `void`

**Returns**

`string`



## `FO3Save::getPlayerPlaytime`

**Params**

* `void`

**Returns**

`string`



## `FO3Save::getSnapshotWidth`

**Params**

* `void`

**Returns**

`unsigned int`



## `FO3Save::getSnapshotHeight`

**Params**

* `void`

**Returns**

`unsigned int`



## `FO3Save::getSnapshotLength`

**Params**

* `void`

**Returns**

`long unsigned int`



## `FO3Save::getSnapshot`

**Params**

* `void`

**Returns**

`unsigned char*`
