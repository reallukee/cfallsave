<div align="center">

![Fallout: New Vegas Logo 192x192](../assets/fonv/fonv_logo_192x192.png)

# *Fallout: New Vegas*<br /> C++ API

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

### Constructors

- [`FONVSave`](#fonvsavefonvsave)

### Destructors

- [`~FONVSave`](#fonvsavefonvsave-1)

### Methods

- [`read`](#fonvsaveread)
- [`write`](#fonvsavewrite)
- [`close`](#fonvsaveclose)
- [`isSave` (*static*)](#fonvsaveissave-static)
- [`isOpen`](#fonvsaveisopen)
- [`print`](#fonvsaveprint)
- [`printProps`](#fonvsaveprintprops)
- [`printPropAddresses`](#fonvsaveprintpropaddresses)
- [`printSnapshot`](#fonvsaveprintsnapshot)

### Properties

- [`getFONVSave`](#fonvsavegetfonvsave)
- [`setFONVSave`](#fonvsavesetfonvsave)
- [`getGameName`](#fonvsavegetgamename)
- [`getSaveFileName`](#fonvsavegetsavefilename)
- [`getSaveSignature`](#fonvsavegetsavesignature)
- [`setSaveSignature`](#fonvsavesetsavesignature)
- [`getEngineVersion`](#fonvsavegetengineversion)
- [`setEngineVersion`](#fonvsavesetengineversion)
- [`getSaveNumber`](#fonvsavegetsavenumber)
- [`setSaveNumber`](#fonvsavesetsavenumber)
- [`getPlayerName`](#fonvsavegetplayername)
- [`setPlayerName`](#fonvsavesetplayername)
- [`getPlayerLevel`](#fonvsavegetplayerlevel)
- [`setPlayerLevel`](#fonvsavesetplayerlevel)
- [`getPlayerTitle`](#fonvsavegetplayertitle)
- [`setPlayerTitle`](#fonvsavesetplayertitle)
- [`getPlayerLocation`](#fonvsavegetplayerlocation)
- [`setPlayerLocation`](#fonvsavesetplayerlocation)
- [`getPlayerPlaytime`](#fonvsavegetplayerplaytime)
- [`setPlayerPlaytime`](#fonvsavesetplayerplaytime)
- [`getSnapshotWidth`](#fonvsavegetsnapshotwidth)
- [`setSnapshotWidth`](#fonvsavesetsnapshotwidth)
- [`getSnapshotHeight`](#fonvsavegetsnapshotheight)
- [`setSnapshotHeight`](#fonvsavesetsnapshotheight)
- [`getSnapshotLength`](#fonvsavegetsnapshotlength)
- [`getSnapshot`](#fonvsavegetsnapshot)
- [`setSnapshot`](#fonvsavesetsnapshot)



## `FONVSave::FONVSave`

**Params**

* `void`

    Or

* [`FONVSAVE*`](./api_fonv.md#fonvsave) `save`

    Or

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



## `FONVSave::read`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FONVSave* savepp = new FONVSave();

bool result = savepp->read("fonv.fos");

if (result)
{
    printf("FONV Save File Read\n");
}
```



## `FONVSave::write`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

bool result = savepp->write();

if (result)
{
    printf("FONV Save File Written\n");
}
```



## `FONVSave::close`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

savepp->close();
```



## `FONVSave::isSave` (*static*)

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
bool result = FONVSave::isSave("fonv.fos");

if (result)
{
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

if (result)
{
    printf("FONV Save is Open\n");
}
```



## `FONVSave::print`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

savepp->print();
```



## `FONVSave::printProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

savepp->printProps();
```



## `FONVSave::printPropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

savepp->printPropAddresses();
```



## `FONVSave::printSnapshot`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FONVSave* savepp = new FONVSave("fonv.fos");

savepp->printSnapshot();
```



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

## `FONVSave::setSaveSignature`

**Params**

* `string`

**Returns**

`void`



## `FONVSave::getEngineVersion`

**Params**

* `void`

**Returns**

`unsigned int`

## `FONVSave::setEngineVersion`

**Params**

* `unsigned int`

**Returns**

`void`



## `FONVSave::getSaveNumber`

**Params**

* `void`

**Returns**

`unsigned int`

## `FONVSave::setSaveNumber`

**Params**

* `unsigned int`

**Returns**

`void`



## `FONVSave::getPlayerName`

**Params**

* `void`

**Returns**

`string`

## `FONVSave::setPlayerName`

**Params**

* `string`

**Returns**

`void`



## `FONVSave::getPlayerLevel`

**Params**

* `void`

**Returns**

`unsigned int`

## `FONVSave::setPlayerLevel`

**Params**

* `unsigned int`

**Returns**

`void`



## `FONVSave::getPlayerTitle`

**Params**

* `void`

**Returns**

`string`

## `FONVSave::setPlayerTitle`

**Params**

* `string`

**Returns**

`void`



## `FONVSave::getPlayerLocation`

**Params**

* `void`

**Returns**

`string`

## `FONVSave::setPlayerLocation`

**Params**

* `string`

**Returns**

`void`



## `FONVSave::getPlayerPlaytime`

**Params**

* `void`

**Returns**

`string`

## `FONVSave::setPlayerPlaytime`

**Params**

* `string`

**Returns**

`void`



## `FONVSave::getSnapshotWidth`

**Params**

* `void`

**Returns**

`unsigned int`

## `FONVSave::setSnapshotWidth`

**Params**

* `unsigned int`

**Returns**

`void`



## `FONVSave::getSnapshotHeight`

**Params**

* `void`

**Returns**

`unsigned int`

## `FONVSave::setSnapshotHeight`

**Params**

* `unsigned int`

**Returns**

`void`



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

## `FONVSave::setSnapshot`

**Params**

* `unsigned char*`

**Returns**

`void`
