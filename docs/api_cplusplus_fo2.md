<div align="center">

![Fallout 2 Logo 192x192](../assets/fo2/fo2_logo_192x192.png)

# *Fallout 2* C++ API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout 2* C API?<br />
> Click [here](./api_fo2.md)!

> [!IMPORTANT]
> These APIs are a Wrapper of the *Fallout 2* C APIs.<br />
> The C APIs are available [here](./api_fo2.md).



# Summary

* [Code](#code)
* [Namespaces](#namespaces)
* [Enums](#enums)
* [Classes](#classes)



# Code

> Headers: [`fo2.hpp`](../src/cplusplus/fo2.hpp)

> Sources: [`fo2.cpp`](../src/cplusplus/fo2.cpp)



# Namespaces

* [`cfallsave`](./api_fo2.md)
* `cfallsavepp`



# Enums

## `FO2SaveProps`

| Field           | Value |
| :-------------- | :---: |
| `SaveSignature` | `0`   |
| `SaveName`      | `1`   |
| `PlayerName`    | `2`   |



# Classes

## `FO2Save`

- [`getFO2Save`](#fo2savegetfo2save)
- [`setFO2Save`](#fo2savesetfo2save)
- [`FO2Save`](#fo2savefo2save)
- [`~FO2Save`](#fo2savefo2save-1)
- [`readSave`](#fo2savereadsave)
- [`writeSave`](#fo2savewritesave)
- [`closeSave`](#fo2saveclosesave)
- [`isSave` (*static*)](#fo2saveissave-static)
- [`isOpen`](#fo2saveisopen)
- [`printSave`](#fo2saveprintsave)
- [`printSaveProps`](#fo2saveprintsaveprops)
- [`printSavePropAddresses`](#fo2saveprintsavepropaddresses)
- [`getGameName`](#fo2savegetgamename)
- [`getSaveFileName`](#fo2savegetsavefilename)
- [`getSaveSignature`](#fo2savegetsavesignature)
- [`getSaveName`](#fo2savegetsavename)
- [`getPlayerName`](#fo2savegetplayername)



## `FO2Save::getFO2SAVE`

**Params**

* `void`

**Returns**

[`FO2SAVE*`](./api_fo2.md#fo2save) or `NULL`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

FO2SAVE* save = savepp->getFO2SAVE();
```



## `FO2Save::setFO2SAVE`

**Params**

[`FO2SAVE*`](./api_fo2.md#fo2save) `save`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save();

FO2SAVE* save = readFO2Save("fo2.dat");

savepp->setFO2SAVE(save);
```



## `FO2Save::FO2Save`

**Params**

* `void`

    Or

* [`FO2SAVE*`](./api_fo2.md#fo2save) `save`

    Or

* `string` `saveName`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save();
```

```cpp
FO2SAVE* save = readFO2Save("fo2.dat");

FO2Save* savepp = new FO2Save(save);
```

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");
```



## `FO2Save::~FO2Save`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

delete savepp;
```



## `FO2Save::readSave`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FO2Save* savepp = new FO2Save();

bool result = savepp->readSave("fo2.dat");

if (result) {
    printf("FO2 Save File Read\n");
}
```



## `FO2Save::writeSave`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

bool result = savepp->writeSave();

if (result) {
    printf("FO2 Save File Written\n");
}
```



## `FO2Save::closeSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

savepp->closeSave();
```



## `FO2Save::isSave` (*static*)

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
bool result = FO2Save::isSave("fo2.dat");

if (result) {
    printf("FO2 Save!\n");
}
```



## `FO2Save::isOpen`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

bool result = savepp->isOpen();

if (result) {
    printf("FO2 Save is Open\n");
}
```



## `FO2Save::printSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

savepp->printSave();
```



## `FO2Save::printSaveProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

savepp->printSaveProps();
```



## `FO2Save::printSavePropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

savepp->printSavePropAddresses();
```



## `FO2Save::getGameName`

**Params**

* `void`

**Returns**

`string`



## `FO2Save::getSaveFileName`

**Params**

* `void`

**Returns**

`string`



## `FO2Save::getSaveSignature`

**Params**

* `void`

**Returns**

`string`



## `FO2Save::getSaveName`

**Params**

* `void`

**Returns**

`string`



## `FO2Save::getPlayerName`

**Params**

* `void`

**Returns**

`string`
