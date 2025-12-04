<div align="center">

![Fallout 4 Logo 192x192](../assets/fo4/fo4_logo_192x192.png)

# *Fallout 4*<br /> C++ API

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

### Constructors

- [`FO4Save`](#fo4savefo4save)

### Destructors

- [`~FO4Save`](#fo4savefo4save-1)

### Methods

- [`read`](#fo4saveread)
- [`write`](#fo4savewrite)
- [`close`](#fo4saveclose)
- [`isSave` (*static*)](#fo4saveissave-static)
- [`isOpen`](#fo4saveisopen)
- [`print`](#fo4saveprint)
- [`printProps`](#fo4saveprintprops)
- [`printPropAddresses`](#fo4saveprintpropaddresses)
- [`printSnapshot`](#fo4saveprintsnapshot)

### Properties

- [`getFO4Save`](#fo4savegetfo4save)
- [`setFO4Save`](#fo4savesetfo4save)
- [`getGameName`](#fo4savegetgamename)
- [`getSaveFileName`](#fo4savegetsavefilename)
- [`getSaveSignature`](#fo4savegetsavesignature)
- [`setSaveSignature`](#fo4savesetsavesignature)
- [`getEngineVersion`](#fo4savegetengineversion)
- [`setEngineVersion`](#fo4savesetengineversion)
- [`getSaveNumber`](#fo4savegetsavenumber)
- [`setSaveNumber`](#fo4savesetsavenumber)
- [`getPlayerName`](#fo4savegetplayername)
- [`setPlayerName`](#fo4savesetplayername)
- [`getPlayerLevel`](#fo4savegetplayerlevel)
- [`setPlayerLevel`](#fo4savesetplayerlevel)
- [`getPlayerLocation`](#fo4savegetplayerlocation)
- [`setPlayerLocation`](#fo4savesetplayerlocation)
- [`getPlayerPlaytime`](#fo4savegetplayerplaytime)
- [`setPlayerPlaytime`](#fo4savesetplayerplaytime)
- [`getPlayerRace`](#fo4savegetplayerrace)
- [`setPlayerRace`](#fo4savesetplayerrace)
- [`getPlayerSex`](#fo4savegetplayersex)
- [`setPlayerSex`](#fo4savesetplayersex)
- [`getPlayerCurrentXp`](#fo4savegetplayercurrentxp)
- [`setPlayerCurrentXp`](#fo4savesetplayercurrentxp)
- [`getPlayerRequiredXp`](#fo4savegetplayerrequiredxp)
- [`setPlayerRequiredXp`](#fo4savesetplayerrequiredxp)
- [`getSnapshotWidth`](#fo4savegetsnapshotwidth)
- [`setSnapshotWidth`](#fo4savesetsnapshotwidth)
- [`getSnapshotHeight`](#fo4savegetsnapshotheight)
- [`setSnapshotHeight`](#fo4savesetsnapshotheight)
- [`getSnapshotLength`](#fo4savegetsnapshotlength)
- [`getSnapshot`](#fo4savegetsnapshot)
- [`setSnapshot`](#fo4savesetsnapshot)



## `FO4Save::FO4Save`

**Params**

* `void`

    Or

* [`FO4SAVE*`](./api_fo4.md#fo4save) `save`

    Or

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



## `FO4Save::read`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FO4Save* savepp = new FO4Save();

bool result = savepp->read("fo4.fos");

if (result)
{
    printf("FO4 Save File Read\n");
}
```



## `FO4Save::write`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

bool result = savepp->write();

if (result)
{
    printf("FO4 Save File Written\n");
}
```



## `FO4Save::close`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

savepp->close();
```



## `FO4Save::isSave` (*static*)

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
bool result = FO4Save::isSave("fo4.fos");

if (result)
{
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

if (result)
{
    printf("FO4 Save is Open\n");
}
```



## `FO4Save::print`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

savepp->print();
```



## `FO4Save::printProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

savepp->printProps();
```



## `FO4Save::printPropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

savepp->printPropAddresses();
```



## `FO4Save::printSnapshot`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO4Save* savepp = new FO4Save("fo4.fos");

savepp->printSnapshot();
```



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

## `FO4Save::setSaveSignature`

**Params**

* `string`

**Returns**

`void`



## `FO4Save::getEngineVersion`

**Params**

* `void`

**Returns**

`unsigned int`

## `FO4Save::setEngineVersion`

**Params**

* `unsigned int`

**Returns**

`void`



## `FO4Save::getSaveNumber`

**Params**

* `void`

**Returns**

`unsigned int`

## `FO4Save::setSaveNumber`

**Params**

* `unsigned int`

**Returns**

`void`



## `FO4Save::getPlayerName`

**Params**

* `void`

**Returns**

`string`

## `FO4Save::setPlayerName`

**Params**

* `string`

**Returns**

`void`



## `FO4Save::getPlayerLevel`

**Params**

* `void`

**Returns**

`unsigned int`

## `FO4Save::setPlayerLevel`

**Params**

* `unsigned int`

**Returns**

`void`



## `FO4Save::getPlayerLocation`

**Params**

* `void`

**Returns**

`string`

## `FO4Save::setPlayerLocation`

**Params**

* `string`

**Returns**

`void`



## `FO4Save::getPlayerPlaytime`

**Params**

* `void`

**Returns**

`string`

## `FO4Save::setPlayerPlaytime`

**Params**

* `string`

**Returns**

`void`



## `FO4Save::getPlayerRace`

**Params**

* `void`

**Returns**

`string`

## `FO4Save::setPlayerRace`

**Params**

* `string`

**Returns**

`void`



## `FO4Save::getPlayerSex`

**Params**

* `void`

**Returns**

`short unsigned int`

## `FO4Save::setPlayerSex`

**Params**

* `short unsigned int`

**Returns**

`void`



## `FO4Save::getPlayerCurrentXp`

**Params**

* `void`

**Returns**

`float`

## `FO4Save::setPlayerCurrentXp`

**Params**

* `float`

**Returns**

`void`



## `FO4Save::getPlayerRequiredXp`

**Params**

* `void`

**Returns**

`float`

## `FO4Save::setPlayerRequiredXp`

**Params**

* `float`

**Returns**

`void`



## `FO4Save::getSnapshotWidth`

**Params**

* `void`

**Returns**

`unsigned int`

## `FO4Save::setSnapshotWidth`

**Params**

* `unsigned int`

**Returns**

`void`



## `FO4Save::getSnapshotHeight`

**Params**

* `void`

**Returns**

`unsigned int`

## `FO4Save::setSnapshotHeight`

**Params**

* `unsigned int`

**Returns**

`void`



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

## `FO4Save::setSnapshot`

**Params**

* `unsigned char*`

**Returns**

`void`
