<div align="center">

![Fallout Tactics: Brotherhood of Steel Logo 192x192](../assets/fotbos/fotbos_logo_192x192.png)

# *Fallout Tactics: Brotherhood of Steel*<br /> C++ API

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
| `PlayerLocation` | `3`   |
| `GameDateTime`   | `4`   |



# Classes

## `FOTBOSSave`

### Constructors

- [`FOTBOSSave`](#fotbossavefotbossave)

### Destructors

- [`~FOTBOSSave`](#fotbossavefotbossave-1)

### Methods

- [`read`](#fotbossaveread)
- [`write`](#fotbossavewrite)
- [`close`](#fotbossaveclose)
- [`isSave` (*static*)](#fotbossaveissave-static)
- [`isOpen`](#fotbossaveisopen)
- [`print`](#fotbossaveprint)
- [`printProps`](#fotbossaveprintprops)
- [`printPropAddresses`](#fotbossaveprintpropaddresses)

### Properties

- [`getFOTBOSSave`](#fotbossavegetfotbossave)
- [`setFOTBOSSave`](#fotbossavesetfotbossave)
- [`getGameName`](#fotbossavegetgamename)
- [`getSaveFileName`](#fotbossavegetsavefilename)
- [`getSaveSignature`](#fotbossavegetsavesignature)
- [`setSaveSignature`](#fotbossavesetsavesignature)
- [`getSaveName`](#fotbossavegetsavename)
- [`setSaveName`](#fotbossavesetsavename)
- [`getPlayerName`](#fotbossavegetplayername)
- [`setPlayerName`](#fotbossavesetplayername)
- [`getPlayerLocation`](#fotbossavegetplayerlocation)
- [`setPlayerLocation`](#fotbossavesetplayerlocation)
- [`getGameDateTime`](#fotbossavegetgamedatetime)
- [`setGameDateTime`](#fotbossavesetgamedatetime)



## `FOTBOSSave::FOTBOSSave`

**Params**

* `void`

    Or

* [`FOTBOSSAVE*`](./api_fotbos.md#fotbossave) `save`

    Or

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



## `FOTBOSSave::read`

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave();

bool result = savepp->read("fotbos.sav");

if (result)
{
    printf("FOTBOS Save File Read\n");
}
```



## `FOTBOSSave::write`

**Params**

* `void`

**Returns**

`bool`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

bool result = savepp->write();

if (result)
{
    printf("FOTBOS Save File Written\n");
}
```



## `FOTBOSSave::close`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

savepp->close();
```



## `FOTBOSSave::isSave` (*static*)

**Params**

* `string` `saveName`

**Returns**

`bool`

**Examples**

```cpp
bool result = FOTBOSSave::isSave("fotbps.sav");

if (result)
{
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

if (result)
{
    printf("FOTBOS Save is Open\n");
}
```



## `FOTBOSSave::print`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

savepp->print();
```



## `FOTBOSSave::printProps`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

savepp->printProps();
```



## `FOTBOSSave::printPropAddresses`

**Params**

* `void`

**Returns**

`void`

**Examples**

```cpp
FOTBOSSave* savepp = new FOTBOSSave("fotbos.sav");

savepp->printPropAddresses();
```



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

## `FOTBOSSave::setSaveSignature`

**Params**

* `string`

**Returns**

`void`



## `FOTBOSSave::getSaveName`

**Params**

* `void`

**Returns**

`string`

## `FOTBOSSave::setSaveName`

**Params**

* `string`

**Returns**

`void`



## `FOTBOSSave::getPlayerName`

**Params**

* `void`

**Returns**

`string`

## `FOTBOSSave::setPlayerName`

**Params**

* `string`

**Returns**

`void`



## `FOTBOSSave::getPlayerLocation`

**Params**

* `void`

**Returns**

`string`

## `FOTBOSSave::setPlayerLocation`

**Params**

* `string`

**Returns**

`void`



## `FOTBOSSave::getGameDateTime`

**Params**

* `void`

**Returns**

`string`

## `FOTBOSSave::setGameDateTime`

**Params**

* `string`

**Returns**

`void`
