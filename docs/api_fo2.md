<div align="center">

![Fallout 2 Logo 192x192](../assets/fo2/fo2_logo_192x192.png)

# *Fallout 2*<br /> C API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout 2* C++ API?<br />
> Click [here](./api_cplusplus_fo2.md)!



# Summary

* [Code](#code)
* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)



# Code

> Headers: [`fo2.h`](../src/fo2.h)

> Sources: [`fo2.c`](../src/fo2.c)



# Functions

* [`readFO2Save`](#readfo2save)
* [`writeFO2Save`](#writefo2save)
* [`isFO2Save`](#isfo2save)
* [`isFO2SaveOpen`](#isfo2saveopen)
* [`closeFO2Save`](#closefo2save)
* [`getFO2SaveProp`](#getfo2saveprop)
* [`setFO2SaveProp`](#setfo2saveprop)
* [`readFO2SaveProp`](#readfo2saveprop)
* [`writeFO2SaveProp`](#writefo2saveprop)
* [`printFO2Save`](#printfo2save)
* [`printFO2SaveProps`](#printfo2saveprops)
* [`printFO2SavePropAddresses`](#printfo2savepropaddresses)
* [`createFO2SampleSave`](#createfo2samplesave)



## `readFO2Save`

**Params**

* `const char*` `saveName`

**Returns**

[`FO2SAVE*`](#fo2save) or `NULL`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");
```



## `writeFO2Save`

> [!CAUTION]
> Experimental function!

**Params**

* [`FO2SAVE*`](#fo2save) `save`

**Returns**

`bool`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");

bool result = writeFO2Save(save);
```



## `isFO2Save`

**Params**

* `const char*` `saveName`

**Returns**

`bool`

**Examples**

```c
bool result = isFO2Save("fo2.dat");

if (result) {
    printf("FO2 Save\n");
}
```



## `isFO2SaveOpen`

**Params**

* [`FO2SAVE*`](#fo2save) `save`

**Returns**

`bool`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");

bool result = isFO2SaveOpen(save);

if (result) {
    printf("FO2 Save is Open\n");
}
```



## `closeFO2Save`

**Params**

* [`FO2SAVE*`](#fo2save) `save`

**Returns**

`void`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");

closeFO2Save(save);
```



## `getFO2SaveProp`

**Params**

* [`FO2SAVE*`](#fo2save) `save`
* [`FO2SAVE_PROPS`](#fo2save_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");

char saveName[FO2SAVE_STRING_SIZE] = "Save 2";

bool result = getFO2SaveProp(save, FO2SAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result) {
    printf("Property: %s\n", saveName);
}
```



## `setFO2SaveProp`

**Params**

* [`FO2SAVE*`](#fo2save) `save`
* [`FO2SAVE_PROPS`](#fo2save_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");

char saveName[FO2SAVE_STRING_SIZE] = "Save 2";

bool result = setFO2SaveProp(save, FO2SAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result) {
    printf("Property: %s\n", saveName);
}
```



## `readFO2SaveProp`

**Params**

* [`FO2SAVE*`](#fo2save) `save`
* [`FO2SAVE_PROPS`](#fo2save_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");

char saveName[FO2SAVE_STRING_SIZE] = "Save 2";

bool result = readFO2SaveProp(save, FO2SAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result) {
    printf("Property: %s\n", saveName);
}
```



## `writeFO2SaveProp`

> [!CAUTION]
> Experimental function!

**Params**

* [`FO2SAVE*`](#fo2save) `save`
* [`FO2SAVE_PROPS`](#fo2save_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");

char saveName[FO2SAVE_STRING_SIZE] = "Save 2";

bool result = writeFO2SaveProp(save, FO2SAVE_PROPS_SAVE_NAME, (void**)&saveName);

if (result) {
    printf("Property: %s\n", saveName);
}
```



## `printFO2Save`

**Params**

* [`FO2SAVE*`](#fo2save) `save`

**Returns**

`bool`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");

printFO2Save(save);
```



## `printFO2SaveProps`

**Params**

* [`FO2SAVE*`](#fo2save) `save`

**Returns**

`bool`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");

printFO2SaveProps(save);
```



## `printFO2SavePropAddresses`

**Params**

* [`FO2SAVE*`](#fo2save) `save`

**Returns**

`bool`

**Examples**

```c
FO2SAVE* save = readFO2Save("fo2.dat");

printFO2SavePropAddresses(save);
```



## `createFO2SampleSave`

`void`

**Returns**

`bool`



# Structures

## `FO2SAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FO2SAVE_SIGNATURE_LENGTH + 1]`
* `char saveName[FO2SAVE_STRING_SIZE + 1]`
* `char playerName[FO2SAVE_STRING_SIZE + 1]`
* `long unsigned int propAddresses[FO2SAVE_PROPS_COUNT]`



# Enums

## `FO2SAVE_PROPS`

| Field                          | Value |
| :----------------------------- | :---: |
| `FO2SAVE_PROPS_SAVE_SIGNATURE` | `0`   |
| `FO2SAVE_PROPS_SAVE_NAME`      | `1`   |
| `FO2SAVE_PROPS_PLAYER_NAME`    | `2`   |



# Macros

| Macro                       | Value                   |
| :-------------------------- | :---------------------- |
| `FO2SAVE_GAME_NAME`         | `Fallout 2`             |
| `FO2SAVE_SIGNATURE`         | `FALLOUT SAVE FILE`     |
| `FO2SAVE_SIGNATURE_LENGTH`  | `17`                    |
| `FO2SAVE_PROPS_COUNT`       | `3`                     |
| `FO2SAVE_STANDARD_EXT`      | `.dat`                  |
| `FO2SAVE_STRING_SIZE`       | `32`                    |
| `FO2SAVE_PROPS_SIZE`        | `sizeof(FO2SAVE_PROPS)` |
| `FO2SAVE_SIZE`              | `sizeof(FO2SAVE)`       |
