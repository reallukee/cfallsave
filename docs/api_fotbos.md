<div align="center">

![Fallout Tactics: Brotherhood of Steel Logo 192x192](../assets/fotbos/fotbos_logo_192x192.png)

# *Fallout Tactics: Brotherhood of Steel*<br /> C API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout Tactics: Brotherhood of Steel* C++ API?<br />
> Click [here](./api_cplusplus_fotbos.md)!



# Summary

* [Code](#code)
* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)



# Code

> Headers: [`fotbos.h`](../src/fotbos.h)

> Sources: [`fotbos.c`](../src/fotbos.c)



# Functions

* [`readFOTBOSSave`](#readfotbossave)
* [`writeFOTBOSSave`](#writefotbossave)
* [`isFOTBOSSave`](#isfotbossave)
* [`isFOTBOSSaveOpen`](#isfotbossaveopen)
* [`closeFOTBOSSave`](#closefotbossave)
* [`getFOTBOSSaveProp`](#getfotbossaveprop)
* [`setFOTBOSSaveProp`](#setfotbossaveprop)
* [`readFOTBOSSaveProp`](#readfotbossaveprop)
* [`writeFOTBOSSaveProp`](#writefotbossaveprop)
* [`printFOTBOSSave`](#printfotbossave)
* [`printFOTBOSSaveProps`](#printfotbossaveprops)
* [`printFOTBOSSavePropAddresses`](#printfotbossavepropaddresses)
* [`createFOTBOSSampleSave`](#createfotbossamplesave)



## `readFOTBOSSave`

**Params**

* `const char*` `saveName`

**Returns**

[`FOTBOSSAVE*`](#fotbossave) or `NULL`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");
```



## `writeFOTBOSSave`

> [!CAUTION]
> Experimental function!

**Params**

* [`FOTBOSSAVE*`](#fotbossave) `save`

**Returns**

`bool`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

bool result = writeFOTBOSSave(save);
```



## `isFOTBOSSave`

**Params**

* `const char*` `saveName`

**Returns**

`bool`

**Examples**

```c
bool result = isFOTBOSSave("fotbos.sav");

if (result) {
    printf("FOTBOS Save\n");
}
```



## `isFOTBOSSaveOpen`

**Params**

* [`FOTBOSSAVE*`](#fotbossave) `save`

**Returns**

`bool`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

bool result = isFOTBOSSaveOpen(save);

if (result) {
    printf("FOTBOS Save is Open\n");
}
```



## `closeFOTBOSSave`

**Params**

* [`FOTBOSSAVE*`](#fotbossave) `save`

**Returns**

`void`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

closeFOTBOSSave(save);
```



## `getFOTBOSSaveProp`

**Params**

* [`FOTBOSSAVE*`](#fotbossave) `save`
* [`FOTBOSSAVE_PROPS`](#fotbossave_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

char* saveName;

bool result = getFOTBOSSaveProp(save, FOTBOSSAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result) {
    printf("Property: %s\n", saveName);
}
```



## `setFOTBOSSaveProp`

**Params**

* [`FOTBOSSAVE*`](#fotbossave) `save`
* [`FOTBOSSAVE_PROPS`](#fotbossave_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

char* saveName;

bool result = setFOTBOSSaveProp(save, FOTBOSSAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result) {
    printf("Property: %s\n", saveName);
}
```



## `readFOTBOSSaveProp`

**Params**

* [`FOTBOSSAVE*`](#fotbossave) `save`
* [`FOTBOSSAVE_PROPS`](#fotbossave_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

char* saveName;

bool result = readFOTBOSSaveProp(save, FOTBOSSAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result) {
    printf("Property: %s\n", saveName);
}
```



## `writeFOTBOSSaveProp`

> [!CAUTION]
> Experimental function!

**Params**

* [`FOTBOSSAVE*`](#fotbossave) `save`
* [`FOTBOSSAVE_PROPS`](#fotbossave_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

char* saveName;

bool result = writeFOTBOSSaveProp(save, FOTBOSSAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result) {
    printf("Property: %s\n", saveName);
}
```



## `printFOTBOSSave`

**Params**

* [`FOTBOSSAVE*`](#fotbossave) `save`

**Returns**

`bool`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

printFOTBOSSave(save);
```



## `printFOTBOSSaveProps`

**Params**

* [`FOTBOSSAVE*`](#fotbossave) `save`

**Returns**

`bool`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

printFOTBOSSaveProps(save);
```



## `printFOTBOSSavePropAddresses`

**Params**

* [`FOTBOSSAVE*`](#fotbossave) `save`

**Returns**

`bool`

**Examples**

```c
FOTBOSSAVE* save = readFOTBOSSave("fotbos.sav");

printFOTBOSSavePropAddresses(save);
```



## `createFOTBOSSampleSave`

`void`

**Returns**

`bool`



# Structures

## `FOTBOSSAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FOTBOSSAVE_SIGNATURE_LENGTH + 1]`
* `char* saveName`
* `char* playerName`
* `char* playerLocation`
* `char* gameDateTime`
* `long unsigned int propAddresses[FOTBOSSAVE_PROPS_COUNT]`



# Enums

## `FOTBOSSAVE_PROPS`

| Field                              | Value |
| :--------------------------------- | :---: |
| `FOTBOSSAVE_PROPS_SAVE_SIGNATURE`  | `0`   |
| `FOTBOSSAVE_PROPS_SAVE_NAME`       | `1`   |
| `FOTBOSSAVE_PROPS_PLAYER_NAME`     | `2`   |
| `FOTBOSSAVE_PROPS_PLAYER_LOCATION` | `3`   |
| `FOTBOSSAVE_PROPS_GAME_DATE_TIME`  | `4`   |



# Macros

| Macro                          | Value                                   |
| :----------------------------- | :-------------------------------------- |
| `FOTBOSSAVE_GAME_NAME`         | `Fallout Tactics: Brotherhood of Steel` |
| `FOTBOSSAVE_SIGNATURE`         | `<saveh>`                               |
| `FOTBOSSAVE_SIGNATURE_LENGTH`  | `7`                                     |
| `FOTBOSSAVE_PROPS_COUNT`       | `5`                                     |
| `FOTBOSSAVE_STANDARD_EXT`      | `.sav`                                  |
| `FOTBOSSAVE_PROPS_SIZE`        | `sizeof(FOTBOSSAVE_PROPS)`              |
| `FOTBOSSAVE_SIZE`              | `sizeof(FOTBOSSAVE)`                    |
