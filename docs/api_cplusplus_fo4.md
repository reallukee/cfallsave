<div align="center">

![Fallout 4 Logo 192x192](../assets/fo4/fo4_logo_192x192.png)

# *Fallout 4* C++ API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout 4* C API?<br />
> Click [here](./api_fo4.md)!

> [!IMPORTANT]
> These APIs are a Wrapper of the *Fallout 4* C APIs.<br />
> The C APIs are available [here](./api_fo4.md).



# Summary

* [Code](#code)
* [Namespaces](#namespaces)
* [Enums](#enums)
* [Classes](#classes)



# Code

> Headers: [`fo4.hpp`](../src/cplusplus/fo4.hpp)

> Sources: [`fo4.cpp`](../src/cplusplus/fo4.cpp)



# Namespaces

* [`cfallsave`](./api_fo4.md)
* `cfallsavepp`



# Enums

## `FO4SaveProps`

| Field              | Value |
| :----------------- | :---: |
| `SaveSignature`    | `0`   |
| `EngineVersion`    | `1`   |
| `SaveNumber`       | `2`   |
| `PlayerName`       | `3`   |
| `PlayerLevel`      | `4`   |
| `PlayerLocation`   | `5`   |
| `PlayerPlaytime`   | `6`   |
| `PlayerRace`       | `7`   |
| `PlayerSex`        | `8`   |
| `PlayerCurrentXP`  | `9`   |
| `PlayerRequiredXP` | `10`  |
| `SnapshotWidth`    | `11`  |
| `SnapshotHeight`   | `12`  |
| `Snapshot`         | `13`  |



# Classes

## `FO4Save`

- [`getFO4Save`](#fo4savegetfo4save)
- [`setFO4Save`](#fo4savesetfo4save)
- [`FO4Save`](#fo4savefo4save)
- [`~FO4Save`](#fo4savefo4save-1)
- [`readSave`](#fo4savereadsave)
- [`writeSave`](#fo4savewritesave)
- [`closeSave`](#fo4saveclosesave)
- [`isSave` (*static*)](#fo4saveissave-static)
- [`isOpen`](#fo4saveisopen)
- [`printSave`](#fo4saveprintsave)
- [`printSaveProps`](#fo4saveprintsaveprops)
- [`printSavePropAddresses`](#fo4saveprintsavepropaddresses)
- [`printSaveSnapshot`](#fo4saveprintsavesnapshot)
- [`getGameName`](#fo4savegetgamename)
- [`getSaveFileName`](#fo4savegetsavefilename)
- [`getSaveSignature`](#fo4savegetsavesignature)
- [`getEngineVersion`](#fo4savegetengineversion)
- [`getSaveNumber`](#fo4savegetsavenumber)
- [`getPlayerName`](#fo4savegetplayername)
- [`getPlayerLevel`](#fo4savegetplayerlevel)
- [`getPlayerLocation`](#fo4savegetplayerlocation)
- [`getPlayerPlaytime`](#fo4savegetplayerplaytime)
- [`getPlayerRace`](#fo4savegetplayerrace)
- [`getPlayerSex`](#fo4savegetplayersex)
- [`getPlayerCurrentXp`](#fo4savegetplayercurrentxp)
- [`getPlayerRequiredXp`](#fo4savegetplayerrequiredxp)
- [`getSnapshotWidth`](#fo4savegetsnapshotwidth)
- [`getSnapshotHeight`](#fo4savegetsnapshotheight)
- [`getSnapshotLength`](#fo4savegetsnapshotlength)
- [`getSnapshot`](#fo4savegetsnapshot)



## `FO4Save::getFO4SAVE`

**Params**

* `void`

**Returns**

[`FO4SAVE*`](./api_fo4.md#fo4save) or `NULL`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

FO4SAVE* save = savepp->getFO4SAVE();
```



## `FO4Save::setFO4SAVE`

**Params**

[`FO4SAVE*`](./api_fo4.md#fo4save) `save`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save();

FO4SAVE* save = readFO4Save("fo4.fos");

savepp->setFO4SAVE(save);
```



## `FO4Save::FO4Save`

**Params**

* `void`

OR

* [`FO4SAVE*`](./api_fo4.md#fo4save) `save`

OR

* `string` `saveName`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save();
```

```cpp
FO4SAVE* save = readFO4Save("fo4.fos");

FO4Save* savepp = new FO4Save(save);
```

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");
```



## `FO4Save::~FO4Save`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

delete savepp;
```



## `FO4Save::readSave`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FO4Save* savepp = new FO4Save();

bool result = savepp->readSave("fo4.fos");

if (result) {
    printf("FO4 Save File Read\n");
}
```



## `FO4Save::writeSave`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

bool result = savepp->writeSave();

if (result) {
    printf("FO4 Save File Written\n");
}
```



## `FO4Save::closeSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

savepp->closeSave();
```



## `FO4Save::isSave` (*static*)

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
bool result = FO4Save::isSave("fo4.fos");

if (result) {
    printf("FO4 Save!\n");
}
```



## `FO4Save::isOpen`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

bool result = savepp->isOpen();

if (result) {
    printf("FO4 Save is Open\n");
}
```



## `FO4Save::printSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

savepp->printSave();
```



## `FO4Save::printSaveProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

savepp->printSaveProps();
```



## `FO4Save::printSavePropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

savepp->printSavePropAddresses();
```



## `FO4Save::printSaveSnapshot`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

savepp->printSaveSnapshot();
```



## `FO4Save::getGameName`

**Params**

* `void`

**Returns**

`string`



## `FO4Save::getSaveFileName`

**Params**

* `void`

**Returns**

`string`



## `FO4Save::getSaveSignature`

**Params**

* `void`

**Returns**

`string`



## `FO4Save::getEngineVersion`

**Params**

* `void`

**Returns**

`unsigned int`



## `FO4Save::getSaveNumber`

**Params**

* `void`

**Returns**

`unsigned int`



## `FO4Save::getPlayerName`

**Params**

* `void`

**Returns**

`string`




## `FO4Save::getPlayerLevel`

**Params**

* `void`

**Returns**

`unsigned int`



## `FO4Save::getPlayerLocation`

**Params**

* `void`

**Returns**

`string`



## `FO4Save::getPlayerPlaytime`

**Params**

* `void`

**Returns**

`string`



## `FO4Save::getPlayerRace`

**Params**

* `void`

**Returns**

`string`



## `FO4Save::getPlayerSex`

**Params**

* `void`

**Returns**

`short unsigned int`



## `FO4Save::getPlayerCurrentXp`

**Params**

* `void`

**Returns**

`float`



## `FO4Save::getPlayerRequiredXp`

**Params**

* `void`

**Returns**

`float`



## `FO4Save::getSnapshotWidth`

**Params**

* `void`

**Returns**

`unsigned int`



## `FO4Save::getSnapshotHeight`

**Params**

* `void`

**Returns**

`unsigned int`



## `FO4Save::getSnapshotLength`

**Params**

* `void`

**Returns**

`long unsigned int`



## `FO4Save::getSnapshot`

**Params**

* `void`

**Returns**

`unsigned char*`
