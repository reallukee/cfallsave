<div align="center">

![Fallout 1 Logo 192x192](../assets/fo1/fo1_logo_192x192.png)

# *Fallout 1*<br /> C API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout 1* C++ API?<br />
> Click [here](./api_cplusplus_fo1.md)!



# Summary

* [Code](#code)
* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)



# Code

> Headers: [`fo1.h`](../src/fo1.h)

> Sources: [`fo1.c`](../src/fo1.c)



# Functions

* [`readFO1Save`](#readfo1save)
* [`writeFO1Save`](#writefo1save)
* [`isFO1Save`](#isfo1save)
* [`isFO1SaveOpen`](#isfo1saveopen)
* [`closeFO1Save`](#closefo1save)
* [`getFO1SaveProp`](#getfo1saveprop)
* [`setFO1SaveProp`](#setfo1saveprop)
* [`readFO1SaveProp`](#readfo1saveprop)
* [`writeFO1SaveProp`](#writefo1saveprop)
* [`printFO1Save`](#printfo1save)
* [`printFO1SaveProps`](#printfo1saveprops)
* [`printFO1SavePropAddresses`](#printfo1savepropaddresses)



## `readFO1Save`

**Params**

* `const char*` `saveName`

**Returns**

[`FO1SAVE*`](#fo1save) or `NULL`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");
```



## `writeFO1Save`

> [!CAUTION]
> Experimental function!

**Params**

* [`FO1SAVE*`](#fo1save) `save`

**Returns**

`bool`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");

bool result = writeFO1Save(save);
```



## `isFO1Save`

**Params**

* `const char*` `saveName`

**Returns**

`bool`

**Examples**

```c
bool result = isFO1Save("fo1.dat");

if (result)
{
    printf("FO1 Save\n");
}
```



## `isFO1SaveOpen`

**Params**

* [`FO1SAVE*`](#fo1save) `save`

**Returns**

`bool`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");

bool result = isFO1SaveOpen(save);

if (result)
{
    printf("FO1 Save is Open\n");
}
```



## `closeFO1Save`

**Params**

* [`FO1SAVE*`](#fo1save) `save`

**Returns**

`void`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");

closeFO1Save(save);
```



## `getFO1SaveProp`

**Params**

* [`FO1SAVE*`](#fo1save) `save`
* [`FO1SAVE_PROPS`](#fo1save_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");

char saveName[FO1SAVE_STRING_SIZE] = "Save 1";

bool result = getFO1SaveProp(save, FO1SAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result)
{
    printf("Property: %s\n", saveName);
}
```



## `setFO1SaveProp`

**Params**

* [`FO1SAVE*`](#fo1save) `save`
* [`FO1SAVE_PROPS`](#fo1save_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");

char saveName[FO1SAVE_STRING_SIZE] = "Save 1";

bool result = setFO1SaveProp(save, FO1SAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result)
{
    printf("Property: %s\n", saveName);
}
```



## `readFO1SaveProp`

**Params**

* [`FO1SAVE*`](#fo1save) `save`
* [`FO1SAVE_PROPS`](#fo1save_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");

char saveName[FO1SAVE_STRING_SIZE] = "Save 1";

bool result = readFO1SaveProp(save, FO1SAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result)
{
    printf("Property: %s\n", saveName);
}
```



## `writeFO1SaveProp`

> [!CAUTION]
> Experimental function!

**Params**

* [`FO1SAVE*`](#fo1save) `save`
* [`FO1SAVE_PROPS`](#fo1save_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");

char saveName[FO1SAVE_STRING_SIZE] = "Save 1";

bool result = writeFO1SaveProp(save, FO1SAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result)
{
    printf("Property: %s\n", saveName);
}
```



## `printFO1Save`

**Params**

* [`FO1SAVE*`](#fo1save) `save`

**Returns**

`bool`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");

printFO1Save(save);
```



## `printFO1SaveProps`

**Params**

* [`FO1SAVE*`](#fo1save) `save`

**Returns**

`bool`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");

printFO1SaveProps(save);
```



## `printFO1SavePropAddresses`

**Params**

* [`FO1SAVE*`](#fo1save) `save`

**Returns**

`bool`

**Examples**

```c
FO1SAVE* save = readFO1Save("fo1.dat");

printFO1SavePropAddresses(save);
```



# Structures

## `FO1SAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FO1SAVE_SIGNATURE_LENGTH + 1]`
* `char saveName[FO1SAVE_STRING_SIZE + 1]`
* `char playerName[FO1SAVE_STRING_SIZE + 1]`
* `long unsigned int propAddresses[FO1SAVE_PROPS_COUNT]`



# Enums

## `FO1SAVE_PROPS`

| Field                          | Value |
| :----------------------------- | :---: |
| `FO1SAVE_PROPS_SAVE_SIGNATURE` | `0`   |
| `FO1SAVE_PROPS_SAVE_NAME`      | `1`   |
| `FO1SAVE_PROPS_PLAYER_NAME`    | `2`   |



# Macros

| Macro                       | Value                   |
| :-------------------------- | :---------------------- |
| `FO1SAVE_GAME_NAME`         | `Fallout 1`             |
| `FO1SAVE_SIGNATURE`         | `FALLOUT SAVE FILE`     |
| `FO1SAVE_SIGNATURE_LENGTH`  | `17`                    |
| `FO1SAVE_PROPS_COUNT`       | `3`                     |
| `FO1SAVE_STANDARD_EXT`      | `.dat`                  |
| `FO1SAVE_STRING_SIZE`       | `32`                    |
| `FO1SAVE_PROPS_SIZE`        | `sizeof(FO1SAVE_PROPS)` |
| `FO1SAVE_SIZE`              | `sizeof(FO1SAVE)`       |
