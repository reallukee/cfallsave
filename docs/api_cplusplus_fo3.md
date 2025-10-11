<div align="center">

![Fallout 3 Logo 192x192](../assets/fo3/fo3_logo_192x192.png)

# *Fallout 3*<br /> C++ API

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

### Constructors

- [`FO3Save`](#fo3savefo3save)

### Destructors

- [`~FO3Save`](#fo3savefo3save-1)

### Methods

- [`read`](#fo3saveread)
- [`write`](#fo3savewrite)
- [`close`](#fo3saveclose)
- [`isSave` (*static*)](#fo3saveissave-static)
- [`isOpen`](#fo3saveisopen)
- [`print`](#fo3saveprint)
- [`printProps`](#fo3saveprintprops)
- [`printPropAddresses`](#fo3saveprintpropaddresses)
- [`printSnapshot`](#fo3saveprintsnapshot)

### Properties

- [`getFO3Save`](#fo3savegetfo3save)
- [`setFO3Save`](#fo3savesetfo3save)
- [`getGameName`](#fo3savegetgamename)
- [`getSaveFileName`](#fo3savegetsavefilename)
- [`getSaveSignature`](#fo3savegetsavesignature)
- [`setSaveSignature`](#fo3savesetsavesignature)
- [`getEngineVersion`](#fo3savegetengineversion)
- [`setEngineVersion`](#fo3savesetengineversion)
- [`getSaveNumber`](#fo3savegetsavenumber)
- [`setSaveNumber`](#fo3savesetsavenumber)
- [`getPlayerName`](#fo3savegetplayername)
- [`setPlayerName`](#fo3savesetplayername)
- [`getPlayerLevel`](#fo3savegetplayerlevel)
- [`setPlayerLevel`](#fo3savesetplayerlevel)
- [`getPlayerTitle`](#fo3savegetplayertitle)
- [`setPlayerTitle`](#fo3savesetplayertitle)
- [`getPlayerLocation`](#fo3savegetplayerlocation)
- [`setPlayerLocation`](#fo3savesetplayerlocation)
- [`getPlayerPlaytime`](#fo3savegetplayerplaytime)
- [`setPlayerPlaytime`](#fo3savesetplayerplaytime)
- [`getSnapshotWidth`](#fo3savegetsnapshotwidth)
- [`setSnapshotWidth`](#fo3savesetsnapshotwidth)
- [`getSnapshotHeight`](#fo3savegetsnapshotheight)
- [`setSnapshotHeight`](#fo3savesetsnapshotheight)
- [`getSnapshotLength`](#fo3savegetsnapshotlength)
- [`getSnapshot`](#fo3savegetsnapshot)
- [`setSnapshot`](#fo3savesetsnapshot)



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



## `FO3Save::read`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FO3Save* savepp = new FO3Save();

bool result = savepp->read("fo3.fos");

if (result) {
    printf("FO3 Save File Read\n");
}
```



## `FO3Save::write`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

bool result = savepp->write();

if (result) {
    printf("FO3 Save File Written\n");
}
```



## `FO3Save::close`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

savepp->close();
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



## `FO3Save::print`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

savepp->print();
```



## `FO3Save::printProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

savepp->printProps();
```



## `FO3Save::printPropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

savepp->printPropAddresses();
```



## `FO3Save::printSnapshot`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO3Save* savepp = new FO3Save("fo3.fos");

savepp->printSnapshot();
```



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

## `FO3Save::setSaveSignature`

**Params**

* `string`

**Returns**

`void`



## `FO3Save::getEngineVersion`

**Params**

* `void`

**Returns**

`unsigned int`

## `FO3Save::setEngineVersion`

**Params**

* `unsigned int`

**Returns**

`void`



## `FO3Save::getSaveNumber`

**Params**

* `void`

**Returns**

`unsigned int`

## `FO3Save::setSaveNumber`

**Params**

* `unsigned int`

**Returns**

`void`



## `FO3Save::getPlayerName`

**Params**

* `void`

**Returns**

`string`

## `FO3Save::setPlayerName`

**Params**

* `string`

**Returns**

`void`



## `FO3Save::getPlayerLevel`

**Params**

* `void`

**Returns**

`unsigned int`

## `FO3Save::setPlayerLevel`

**Params**

* `unsigned int`

**Returns**

`void`



## `FO3Save::getPlayerTitle`

**Params**

* `void`

**Returns**

`string`

## `FO3Save::setPlayerTitle`

**Params**

* `string`

**Returns**

`void`



## `FO3Save::getPlayerLocation`

**Params**

* `void`

**Returns**

`string`

## `FO3Save::setPlayerLocation`

**Params**

* `string`

**Returns**

`void`



## `FO3Save::getPlayerPlaytime`

**Params**

* `void`

**Returns**

`string`

## `FO3Save::setPlayerPlaytime`

**Params**

* `string`

**Returns**

`void`



## `FO3Save::getSnapshotWidth`

**Params**

* `void`

**Returns**

`unsigned int`

## `FO3Save::setSnapshotWidth`

**Params**

* `unsigned int`

**Returns**

`void`



## `FO3Save::getSnapshotHeight`

**Params**

* `void`

**Returns**

`unsigned int`

## `FO3Save::setSnapshotHeight`

**Params**

* `unsigned int`

**Returns**

`void`



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

## `FO3Save::setSnapshot`

**Params**

* `unsigned char*`

**Returns**

`void`
