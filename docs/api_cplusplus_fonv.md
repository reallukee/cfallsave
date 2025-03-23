<div align="center">

![Fallout: New Vegas Logo 192x192](../assets/fonv/fonv_logo_192x192.png)

# *Fallout: New Vegas* C++ API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout: New Vegas* C API?<br />
> Click [here](./api_fonv.md)!

> [!IMPORTANT]
> These APIs are a Wrapper of the *Fallout: New Vegas* C APIs.<br />
> The C APIs are available [here](./api_fonv.md).



# Summary

* [Code](#code)
* [Namespaces](#namespaces)
* [Enums](#enums)
* [Classes](#classes)



# Code

> Headers: [`fonv.hpp`](../src/cplusplus/fonv.hpp)

> Sources: [`fonv.cpp`](../src/cplusplus/fonv.cpp)



# Namespaces

* [`cfallsave`](./api_fonv.md)
* `cfallsavepp`



# Enums

## `FONVSaveProps`

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

## `FONVSave`

- [`getFONVSave`](#fonvsavegetfonvsave)
- [`setFONVSave`](#fonvsavesetfonvsave)
- [`FONVSave`](#fonvsavefonvsave)
- [`~FONVSave`](#fonvsavefonvsave-1)
- [`readSave`](#fonvsavereadsave)
- [`writeSave`](#fonvsavewritesave)
- [`closeSave`](#fonvsaveclosesave)
- [`isSave` (*static*)](#fonvsaveissave-static)
- [`isOpen`](#fonvsaveisopen)
- [`printSave`](#fonvsaveprintsave)
- [`printSaveProps`](#fonvsaveprintsaveprops)
- [`printSavePropAddresses`](#fonvsaveprintsavepropaddresses)
- [`printSaveSnapshot`](#fonvsaveprintsavesnapshot)
- [`getGameName`](#fonvsavegetgamename)
- [`getSaveFileName`](#fonvsavegetsavefilename)
- [`getSaveSignature`](#fonvsavegetsavesignature)
- [`getEngineVersion`](#fonvsavegetengineversion)
- [`getSaveNumber`](#fonvsavegetsavenumber)
- [`getPlayerName`](#fonvsavegetplayername)
- [`getPlayerLevel`](#fonvsavegetplayerlevel)
- [`getPlayerTitle`](#fonvsavegetplayertitle)
- [`getPlayerLocation`](#fonvsavegetplayerlocation)
- [`getPlayerPlaytime`](#fonvsavegetplayerplaytime)
- [`getSnapshotWidth`](#fonvsavegetsnapshotwidth)
- [`getSnapshotHeight`](#fonvsavegetsnapshotheight)
- [`getSnapshotLength`](#fonvsavegetsnapshotlength)
- [`getSnapshot`](#fonvsavegetsnapshot)



## `FONVSave::getFONVSAVE`

**Params**

* `void`

**Returns**

[`FONVSAVE*`](./api_fonv.md#fonvsave) or `NULL`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

FONVSAVE* save = savepp->getFONVSAVE();
```



## `FONVSave::setFONVSAVE`

**Params**

[`FONVSAVE*`](./api_fonv.md#fonvsave) `save`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave();

FONVSAVE* save = readFONVSave("fonv.fos");

savepp->setFONVSAVE(save);
```



## `FONVSave::FONVSave`

**Params**

* `void`

OR

* [`FONVSAVE*`](./api_fonv.md#fonvsave) `save`

OR

* `string` `saveName`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave();
```

```cpp
FONVSAVE* save = readFONVSave("fonv.fos");

FONVSave* savepp = new FONVSave(save);
```

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");
```



## `FONVSave::~FONVSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

delete savepp;
```



## `FONVSave::readSave`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FONVSave* savepp = new FONVSave();

bool result = savepp->readSave("fonv.fos");

if (result) {
    printf("FONV Save File Read\n");
}
```



## `FONVSave::writeSave`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

bool result = savepp->writeSave();

if (result) {
    printf("FONV Save File Written\n");
}
```



## `FONVSave::closeSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

savepp->closeSave();
```



## `FONVSave::isSave` (*static*)

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
bool result = FONVSave::isSave("fonv.fos");

if (result) {
    printf("FONV Save!\n");
}
```



## `FONVSave::isOpen`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

bool result = savepp->isOpen();

if (result) {
    printf("FONV Save is Open\n");
}
```



## `FONVSave::printSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

savepp->printSave();
```



## `FONVSave::printSaveProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

savepp->printSaveProps();
```



## `FONVSave::printSavePropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

savepp->printSavePropAddresses();
```



## `FONVSave::printSaveSnapshot`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

savepp->printSaveSnapshot();
```



## `FONVSave::getGameName`

**Params**

* `void`

**Returns**

`string`



## `FONVSave::getSaveFileName`

**Params**

* `void`

**Returns**

`string`



## `FONVSave::getSaveSignature`

**Params**

* `void`

**Returns**

`string`



## `FONVSave::getEngineVersion`

**Params**

* `void`

**Returns**

`unsigned int`



## `FONVSave::getSaveNumber`

**Params**

* `void`

**Returns**

`unsigned int`



## `FONVSave::getPlayerName`

**Params**

* `void`

**Returns**

`string`




## `FONVSave::getPlayerLevel`

**Params**

* `void`

**Returns**

`unsigned int`



## `FONVSave::getPlayerTitle`

**Params**

* `void`

**Returns**

`string`



## `FONVSave::getPlayerLocation`

**Params**

* `void`

**Returns**

`string`



## `FONVSave::getPlayerPlaytime`

**Params**

* `void`

**Returns**

`string`



## `FONVSave::getSnapshotWidth`

**Params**

* `void`

**Returns**

`unsigned int`



## `FONVSave::getSnapshotHeight`

**Params**

* `void`

**Returns**

`unsigned int`



## `FONVSave::getSnapshotLength`

**Params**

* `void`

**Returns**

`long unsigned int`



## `FONVSave::getSnapshot`

**Params**

* `void`

**Returns**

`unsigned char*`
