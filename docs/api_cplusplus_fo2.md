<div align="center">

![Fallout 2 Logo 192x192](../assets/fo2/fo2_logo_192x192.png)

# *Fallout 2*<br /> C++ API

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

### Constructors

- [`FO2Save`](#fo2savefo2save)

### Destructors

- [`~FO2Save`](#fo2savefo2save-1)

### Methods

- [`read`](#fo2saveread)
- [`write`](#fo2savewrite)
- [`close`](#fo2saveclose)
- [`isSave` (*static*)](#fo2saveissave-static)
- [`isOpen`](#fo2saveisopen)
- [`print`](#fo2saveprint)
- [`printProps`](#fo2saveprintprops)
- [`printPropAddresses`](#fo2saveprintpropaddresses)

### Properties

- [`getFO2Save`](#fo2savegetfo2save)
- [`setFO2Save`](#fo2savesetfo2save)
- [`getGameName`](#fo2savegetgamename)
- [`getSaveFileName`](#fo2savegetsavefilename)
- [`getSaveSignature`](#fo2savegetsavesignature)
- [`setSaveSignature`](#fo2savesetsavesignature)
- [`getSaveName`](#fo2savegetsavename)
- [`setSaveName`](#fo2savesetsavename)
- [`getPlayerName`](#fo2savegetplayername)
- [`setPlayerName`](#fo2savesetplayername)



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



## `FO2Save::read`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FO2Save* savepp = new FO2Save();

bool result = savepp->read("fo2.dat");

if (result) {
    printf("FO2 Save File Read\n");
}
```



## `FO2Save::write`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

bool result = savepp->write();

if (result) {
    printf("FO2 Save File Written\n");
}
```



## `FO2Save::close`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

savepp->close();
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



## `FO2Save::print`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

savepp->print();
```



## `FO2Save::printProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

savepp->printProps();
```



## `FO2Save::printPropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FO2Save* savepp = new FO2Save("fo2.dat");

savepp->printPropAddresses();
```



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

## `FO2Save::setSaveSignature`

**Params**

* `string`

**Returns**

`void`



## `FO2Save::getSaveName`

**Params**

* `void`

**Returns**

`string`

## `FO2Save::setSaveName`

**Params**

* `string`

**Returns**

`void`



## `FO2Save::getPlayerName`

**Params**

* `void`

**Returns**

`string`

## `FO2Save::setPlayerName`

**Params**

* `string`

**Returns**

`void`
