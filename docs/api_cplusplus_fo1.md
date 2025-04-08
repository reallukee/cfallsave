<div align="center">

![Fallout 1 Logo 192x192](../assets/fo1/fo1_logo_192x192.png)

# *Fallout 1* C++ API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout 1* C API?<br />
> Click [here](./api_fo1.md)!

> [!IMPORTANT]
> These APIs are a Wrapper of the *Fallout 1* C APIs.<br />
> The C APIs are available [here](./api_fo1.md).



# Summary

* [Code](#code)
* [Namespaces](#namespaces)
* [Enums](#enums)
* [Classes](#classes)



# Code

> Headers: [`fo1.hpp`](../src/cplusplus/fo1.hpp)

> Sources: [`fo1.cpp`](../src/cplusplus/fo1.cpp)



# Namespaces

* [`cfallsave`](./api_fo1.md)
* `cfallsavepp`



# Enums

## `FO1SaveProps`

| Field           | Value |
| :-------------- | :---: |
| `SaveSignature` | `0`   |
| `SaveName`      | `1`   |
| `PlayerName`    | `2`   |



# Classes

## `FO1Save`

- [`getFO1Save`](#fo1savegetfo1save)
- [`setFO1Save`](#fo1savesetfo1save)
- [`FO1Save`](#fo1savefo1save)
- [`~FO1Save`](#fo1savefo1save-1)
- [`readSave`](#fo1savereadsave)
- [`writeSave`](#fo1savewritesave)
- [`closeSave`](#fo1saveclosesave)
- [`isSave` (*static*)](#fo1saveissave-static)
- [`isOpen`](#fo1saveisopen)
- [`printSave`](#fo1saveprintsave)
- [`printSaveProps`](#fo1saveprintsaveprops)
- [`printSavePropAddresses`](#fo1saveprintsavepropaddresses)
- [`getGameName`](#fo1savegetgamename)
- [`getSaveFileName`](#fo1savegetsavefilename)
- [`getSaveSignature`](#fo1savegetsavesignature)
- [`getSaveName`](#fo1savegetsavename)
- [`getPlayerName`](#fo1savegetplayername)



## `FO1Save::getFO1SAVE`

**Params**

* `void`

**Returns**

[`FO1SAVE*`](./api_fo1.md#fo1save) or `NULL`

**Examples**

```cpp
FO1Save* savepp = new FO1Save("fo1.dat");

FO1SAVE* save = savepp->getFO1SAVE();
```



## `FO1Save::setFO1SAVE`

**Params**

[`FO1SAVE*`](./api_fo1.md#fo1save) `save`

**Returns**

`void`

**Examples**

```cpp
FO1Save* savepp = new FO1Save();

FO1SAVE* save = readFO1Save("fo1.dat");

savepp->setFO1SAVE(save);
```



## `FO1Save::FO1Save`

**Params**

* `void`

    Or

* [`FO1SAVE*`](./api_fo1.md#fo1save) `save`

    Or

* `string` `saveName`

**Returns**

`void`

**Examples**

```cpp
FO1Save* savepp = new FO1Save();
```

```cpp
FO1SAVE* save = readFO1Save("fo1.dat");

FO1Save* savepp = new FO1Save(save);
```

```cpp
FO1Save* savepp = new FO1Save("fo1.dat");
```



## `FO1Save::~FO1Save`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO1Save* savepp = new FO1Save("fo1.dat");

delete savepp;
```



## `FO1Save::readSave`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FO1Save* savepp = new FO1Save();

bool result = savepp->readSave("fo1.dat");

if (result) {
    printf("FO1 Save File Read\n");
}
```



## `FO1Save::writeSave`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO1Save* savepp = new FO1Save("fo1.dat");

bool result = savepp->writeSave();

if (result) {
    printf("FO1 Save File Written\n");
}
```



## `FO1Save::closeSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO1Save* savepp = new FO1Save("fo1.dat");

savepp->closeSave();
```



## `FO1Save::isSave` (*static*)

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
bool result = FO1Save::isSave("fo1.dat");

if (result) {
    printf("FO1 Save!\n");
}
```



## `FO1Save::isOpen`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO1Save* savepp = new FO1Save("fo1.dat");

bool result = savepp->isOpen();

if (result) {
    printf("FO1 Save is Open\n");
}
```



## `FO1Save::printSave`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO1Save* savepp = new FO1Save("fo1.dat");

savepp->printSave();
```



## `FO1Save::printSaveProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO1Save* savepp = new FO1Save("fo1.dat");

savepp->printSaveProps();
```



## `FO1Save::printSavePropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO1Save* savepp = new FO1Save("fo1.dat");

savepp->printSavePropAddresses();
```



## `FO1Save::getGameName`

**Params**

* `void`

**Returns**

`string`



## `FO1Save::getSaveFileName`

**Params**

* `void`

**Returns**

`string`



## `FO1Save::getSaveSignature`

**Params**

* `void`

**Returns**

`string`



## `FO1Save::getSaveName`

**Params**

* `void`

**Returns**

`string`



## `FO1Save::getPlayerName`

**Params**

* `void`

**Returns**

`string`
