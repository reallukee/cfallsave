<div align="center">

![Fallout 3 Logo 192x192](../assets/fo3/fo3_logo_192x192.png)

# *Fallout 3*<br /> C API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout 3* C++ API?<br />
> Click [here](./api_cplusplus_fo3.md)!



# Summary

* [Code](#code)
* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)



# Code

> Headers: [`fo3.h`](../src/fo3.h)

> Sources: [`fo3.c`](../src/fo3.c)



# Functions

* [`readFO3Save`](#readfo3save)
* [`writeFO3Save`](#writefo3save)
* [`isFO3Save`](#isfo3save)
* [`isFO3SaveOpen`](#isfo3saveopen)
* [`closeFO3Save`](#closefo3save)
* [`getFO3SaveProp`](#getfo3saveprop)
* [`setFO3SaveProp`](#setfo3saveprop)
* [`readFO3SaveProp`](#readfo3saveprop)
* [`writeFO3SaveProp`](#writefo3saveprop)
* [`printFO3Save`](#printfo3save)
* [`printFO3SaveProps`](#printfo3saveprops)
* [`printFO3SavePropAddresses`](#printfo3savepropaddresses)
* [`printFO3SaveSnapshot`](#printfo3savesnapshot)
* [`createFO3SampleSave`](#createfo3samplesave)



## `readFO3Save`

**Params**

* `const char*` `saveName`

**Returns**

[`FO3SAVE*`](#fo3save) or `NULL`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");
```



## `writeFO3Save`

> [!CAUTION]
> Experimental function!

**Params**

* [`FO3SAVE*`](#fo3save) `save`

**Returns**

`bool`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

bool result = writeFO3Save(save);
```



## `isFO3Save`

**Params**

* `const char*` `saveName`

**Returns**

`bool`

**Examples**

```c
bool result = isFO3Save("fo3.fos");

if (result) {
    printf("FO3 Save\n");
}
```



## `isFO3SaveOpen`

**Params**

* [`FO3SAVE*`](#fo3save) `save`

**Returns**

`bool`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

bool result = isFO3SaveOpen(save);

if (result) {
    printf("FO3 Save is Open\n");
}
```



## `closeFO3Save`

**Params**

* [`FO3SAVE*`](#fo3save) `save`

**Returns**

`void`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

closeFO3Save(save);
```



## `getFO3SaveProp`

**Params**

* [`FO3SAVE*`](#fo3save) `save`
* [`FO3SAVE_PROPS`](#fo3save_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

int engineVersion = 0;

bool result = getFO3SaveProp(save, FO3SAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result) {
    printf("Property: %u\n", engineVersion);
}
```



## `setFO3SaveProp`

**Params**

* [`FO3SAVE*`](#fo3save) `save`
* [`FO3SAVE_PROPS`](#fo3save_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

int engineVersion = 0;

bool result = setFO3SaveProp(save, FO3SAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result) {
    printf("Property: %u\n", engineVersion);
}
```



## `readFO3SaveProp`

**Params**

* [`FO3SAVE*`](#fo3save) `save`
* [`FO3SAVE_PROPS`](#fo3save_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

int engineVersion = 0;

bool result = readFO3SaveProp(save, FO3SAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result) {
    printf("Property: %u\n", engineVersion);
}
```



## `writeFO3SaveProp`

> [!CAUTION]
> Experimental function!

**Params**

* [`FO3SAVE*`](#fo3save) `save`
* [`FO3SAVE_PROPS`](#fo3save_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

int engineVersion = 0;

bool result = writeFO3SaveProp(save, FO3SAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result) {
    printf("Property: %u\n", engineVersion);
}
```



## `printFO3Save`

**Params**

* [`FO3SAVE*`](#fo3save) `save`

**Returns**

`bool`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

printFO3Save(save);
```



## `printFO3SaveProps`

**Params**

* [`FO3SAVE*`](#fo3save) `save`

**Returns**

`bool`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

printFO3SaveProps(save);
```



## `printFO3SavePropAddresses`

**Params**

* [`FO3SAVE*`](#fo3save) `save`

**Returns**

`bool`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

printFO3SavePropAddresses(save);
```



## `printFO3SaveSnapshot`

**Params**

* [`FO3SAVE*`](#fo3save) `save`

**Returns**

`bool`

**Examples**

```c
FO3SAVE* save = readFO3Save("fo3.fos");

printFO3SaveSnapshot(save);
```



## `createFO3SampleSave`

`void`

**Returns**

`bool`



# Structures

## `FO3SAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FO3SAVE_SIGNATURE_LENGTH + 1]`
* `unsigned int engineVersion`
* `unsigned int saveNumber`
* `char* playerName`
* `unsigned int playerLevel`
* `char* playerTitle`
* `char* playerLocation`
* `char* playerPlaytime`
* `unsigned int snapshotWidth`
* `unsigned int snapshotHeight`
* `long unsigned int snapshotLength`
* `unsigned char* snapshot`
* `long unsigned int propAddresses[FO3SAVE_PROPS_COUNT]`



# Enums

## `FO3SAVE_PROPS`

| Field                           | Value |
| :------------------------------ | :---: |
| `FO3SAVE_PROPS_SAVE_SIGNATURE`  | `0`   |
| `FO3SAVE_PROPS_ENGINE_VERSION`  | `1`   |
| `FO3SAVE_PROPS_SAVE_NUMBER`     | `2`   |
| `FO3SAVE_PROPS_PLAYER_NAME`     | `3`   |
| `FO3SAVE_PROPS_PLAYER_LEVEL`    | `4`   |
| `FO3SAVE_PROPS_PLAYER_TITLE`    | `5`   |
| `FO3SAVE_PROPS_PLAYER_LOCATION` | `6`   |
| `FO3SAVE_PROPS_PLAYER_PLAYTIME` | `7`   |
| `FO3SAVE_PROPS_SNAPSHOT_WIDTH`  | `8`   |
| `FO3SAVE_PROPS_SNAPSHOT_HEIGHT` | `9`   |
| `FO3SAVE_PROPS_SNAPSHOT`        | `10`  |



# Macros

| Macro                          | Value                   |
| :----------------------------- | :---------------------- |
| `FO3SAVE_GAME_NAME`            | `Fallout 3`             |
| `FO3SAVE_SIGNATURE`            | `FO3SAVEGAME`           |
| `FO3SAVE_SIGNATURE_LENGTH`     | `11`                    |
| `FO3SAVE_PROPS_COUNT`          | `11`                    |
| `FO3SAVE_STANDARD_EXT`         | `.fos`                  |
| `FO3SAVE_MAX_SNAPSHOT_WIDTH`   | `512`                   |
| `FO3SAVE_MAX_SNAPSHOT_HEIGHT`  | `288`                   |
| `FO3SAVE_MAX_SNAPSHOT_LENGTH`  | `442368`                |
| `FO3SAVE_SNAPSHOT_COLOR_BYTES` | `3`                     |
| `FO3SAVE_SNAPSHOT_FORMAT`      | `RGB`                   |
| `FO3SAVE_PLAYER_SEX_MALE`      | `0`                     |
| `FO3SAVE_PLAYER_SEX_FEMALE`    | `1`                     |
| `FO3SAVE_PROPS_SIZE`           | `sizeof(FO3SAVE_PROPS)` |
| `FO3SAVE_SIZE`                 | `sizeof(FO3SAVE)`       |
