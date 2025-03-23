<div align="center">

![Fallout Tactics: Brotherhood of Steel Logo 192x192](../assets/fotbos/fotbos_logo_192x192.png)

# *Fallout Tactics: Brotherhood of Steel* C++ API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout Tactics: Brotherhood of Steel* C API?<br />
> Click [here](./api_fotbos.md)!

> [!IMPORTANT]
> These APIs are a Wrapper of the *Fallout Tactics: Brotherhood of Steel* C APIs.<br />
> The C APIs are available [here](./api_fotbos.md).



# Summary

* [Code](#code)
* [Namespaces](#namespaces)
* [Enums](#enums)
* [Classes](#classes)



# Code

> Headers: [`fotbos.hpp`](../src/cplusplus/fotbos.hpp)

> Sources: [`fotbos.cpp`](../src/cplusplus/fotbos.cpp)



# Namespaces

* [`cfallsave`](./api_fotbos.md)
* `cfallsavepp`



# Enums

## `FOTBOSSaveProps`

| Field            | Value |
| :--------------- | :---: |
| `SaveSignature`  | `0`   |
| `SaveName`       | `1`   |
| `PlayerName`     | `2`   |
| `PlayerLocation` | `4`   |
| `GameDateTime`   | `3`   |



# Classes

## `FOTBOSSave`

- [`getFOTBOSSave`](#fotbossavegetfotbossave)
- [`setFOTBOSSave`](#fotbossavesetfotbossave)
- [`FOTBOSSave`](#fotbossavefotbossave)
- [`~FOTBOSSave`](#fotbossavefotbossave-1)
- [`readSave`](#fotbossavereadsave)
- [`writeSave`](#fotbossavewritesave)
- [`closeSave`](#fotbossaveclosesave)
- [`isSave` (*static*)](#fotbossaveissave-static)
- [`isOpen`](#fotbossaveisopen)
- [`printSave`](#fotbossaveprintsave)
- [`printSaveProps`](#fotbossaveprintsaveprops)
- [`printSavePropAddresses`](#fotbossaveprintsavepropaddresses)
- [`getGameName`](#fotbossavegetgamename)
- [`getSaveFileName`](#fotbossavegetsavefilename)
- [`getSaveSignature`](#fotbossavegetsavesignature)
- [`getSaveName`](#fotbossavegetsavename)
- [`getPlayerName`](#fotbossavegetplayername)
- [`getPlayerLocation`](#fotbossavegetplayerlocation)
- [`getGameDateTime`](#fotbossavegetgamedatetime)



## `FOTBOSSave::getFOTBOSSAVE`

**Params**

* `void`

**Returns**

[`FOTBOSSAVE*`](./api_fotbos.md#fotbossave) or `NULL`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

FOTBOSSAVE* save = savepp->getFOTBOSSAVE();
```



## `FOTBOSSave::setFOTBOSSAVE`

**Params**

[`FOTBOSSAVE*`](./api_fotbos.md#fotbossave) `save`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave();

FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

savepp->setFOTBOSSAVE(save);
```



## `FOTBOSSave::FOTBOSSave`

**Params**

* `void`

OR

* [`FOTBOSSAVE*`](./api_fotbos.md#fotbossave) `save`

OR

* `string` `saveName`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave();
```

```cpp
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

FOTBOSSave* savepp = new FOTBOSSave(save);
```

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");
```



## `FOTBOSSave::~FOTBOSSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

delete savepp;
```



## `FOTBOSSave::readSave`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave();

bool result = savepp->readSave("fotbos.sav");

if (result) {
    printf("FOTBOS Save File Read\n");
}
```



## `FOTBOSSave::writeSave`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

bool result = savepp->writeSave();

if (result) {
    printf("FOTBOS Save File Written\n");
}
```



## `FOTBOSSave::closeSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

savepp->closeSave();
```



## `FOTBOSSave::isSave` (*static*)

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
bool result = FOTBOSSave::isSave("fotbps.sav");

if (result) {
    printf("FOTBOS Save!\n");
}
```



## `FOTBOSSave::isOpen`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

bool result = savepp->isOpen();

if (result) {
    printf("FOTBOS Save is Open\n");
}
```



## `FOTBOSSave::printSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

savepp->printSave();
```



## `FOTBOSSave::printSaveProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

savepp->printSaveProps();
```



## `FOTBOSSave::printSavePropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

savepp->printSavePropAddresses();
```



## `FOTBOSSave::getGameName`

**Params**

* `void`

**Returns**

`string`



## `FOTBOSSave::getSaveFileName`

**Params**

* `void`

**Returns**

`string`



## `FOTBOSSave::getSaveSignature`

**Params**

* `void`

**Returns**

`string`



## `FOTBOSSave::getSaveName`

**Params**

* `void`

**Returns**

`string`



## `FOTBOSSave::getPlayerName`

**Params**

* `void`

**Returns**

`string`



## `FOTBOSSave::getPlayerLocation`

**Params**

* `void`

**Returns**

`string`



## `FOTBOSSave::getGameDateTime`

**Params**

* `void`

**Returns**

`string`
