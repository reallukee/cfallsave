<div align="center">

![Fallout: New Vegas Logo 192x192](../assets/fonv/fonv_logo_192x192.png)

# *Fallout: New Vegas* C API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout: New Vegas* C++ API?<br />
> Click [here](./api_cplusplus_fonv.md)!



# Summary

* [Code](#code)
* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)



# Code

> Headers: [`fonv.h`](../src/fonv.h)

> Sources: [`fonv.c`](../src/fonv.c)



# Functions

> ![NOTE]
> This section is not yet complete

* [`readFONVSave`](#readfonvsave)
* [`writeFONVSave`](#writefonvsave)
* [`isFONVSave`](#isfonvsave)
* [`isFONVSaveOpen`](#isfonvsaveopen)
* [`closeFONVSave`](#closefonvsave)
* [`getFONVSaveProp`](#getfonvsaveprop)
* [`setFONVSaveProp`](#setfonvsaveprop)
* [`readFONVSaveProp`](#readfonvsaveprop)
* [`writeFONVSaveProp`](#writefonvsaveprop)
* [`printFONVSave`](#printfonvsave)
* [`printFONVSaveProps`](#printfonvsaveprops)
* [`printFONVSavePropAddresses`](#printfonvsavepropaddresses)
* [`printFONVSaveSnapshot`](#printfonvsavesnapshot)



## `readFONVSave`

**Params**

* `const char*` `saveName`

**Returns**

[`FONVSAVE*`](#fonvsave) or `NULL`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");
```



## `writeFONVSave`

> [!WARNING]
> This function is not yet implemented!

**Params**

* [`FONVSAVE*`](#fonvsave) `save`

**Returns**

`bool`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

bool result = writeFONVSave(save);
```



## `isFONVSave`

**Params**

* `const char*` `saveName`

**Returns**

`bool`

**Examples**

```c
bool result = isFONVSave("fonv.fos");

if (result) {
    printf("FONV Save\n");
}
```



## `isFONVSaveOpen`

**Params**

* [`FONVSAVE*`](#fonvsave) `save`

**Returns**

`bool`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

bool result = isFONVSaveOpen(save);

if (result) {
    printf("FONV Save is Open\n");
}
```



## `closeFONVSave`

**Params**

* [`FONVSAVE*`](#fonvsave) `save`

**Returns**

`void`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

closeFONVSave(save);
```



## `getFONVSaveProp`

**Params**

* [`FONVSAVE*`](#fonvsave) `save`
* [`FONVSAVE_PROPS`](#fonvsave_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

int engineVersion = 0;

bool result = getFONVSaveProp(save, FONVSAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result) {
    printf("Property: %u\n", engineVersion);
}
```



## `setFONVSaveProp`

**Params**

* [`FONVSAVE*`](#fonvsave) `save`
* [`FONVSAVE_PROPS`](#fonvsave_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

int engineVersion = 0;

bool result = setFONVSaveProp(save, FONVSAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result) {
    printf("Property: %u\n", engineVersion);
}
```



## `readFONVSaveProp`

**Params**

* [`FONVSAVE*`](#fonvsave) `save`
* [`FONVSAVE_PROPS`](#fonvsave_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

int engineVersion = 0;

bool result = readFONVSaveProp(save, FONVSAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result) {
    printf("Property: %u\n", engineVersion);
}
```



## `writeFONVSaveProp`

> [!CAUTION]
> Experimental function!

**Params**

* [`FONVSAVE*`](#fonvsave) `save`
* [`FONVSAVE_PROPS`](#fonvsave_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

int engineVersion = 0;

bool result = writeFONVSaveProp(save, FONVSAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result) {
    printf("Property: %u\n", engineVersion);
}
```



## `printFONVSave`

**Params**

* [`FONVSAVE*`](#fonvsave) `save`

**Returns**

`bool`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

printFONVSave(save);
```



## `printFONVSaveProps`

**Params**

* [`FONVSAVE*`](#fonvsave) `save`

**Returns**

`bool`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

printFONVSaveProps(save);
```



## `printFONVSavePropAddresses`

**Params**

* [`FONVSAVE*`](#fonvsave) `save`

**Returns**

`bool`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

printFONVSavePropAddresses(save);
```



## `printFONVSaveSnapshot`

**Params**

* [`FONVSAVE*`](#fonvsave) `save`

**Returns**

`bool`

**Examples**

```c
FONVSAVE* save = readFONVSave("fonv.fos");

printFONVSaveSnapshot(save);
```



# Structures

## `FONVSAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FONVSAVE_SIGNATURE_LENGTH + 1]`
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
* `long unsigned int propAddresses[FONVSAVE_PROPS_COUNT]`



# Enums

## `FONVSAVE_PROPS`

| Field                            | Value |
| :------------------------------- | :---: |
| `FONVSAVE_PROPS_SAVE_SIGNATURE`  | `0`   |
| `FONVSAVE_PROPS_ENGINE_VERSION`  | `1`   |
| `FONVSAVE_PROPS_SAVE_NUMBER`     | `2`   |
| `FONVSAVE_PROPS_PLAYER_NAME`     | `3`   |
| `FONVSAVE_PROPS_PLAYER_LEVEL`    | `4`   |
| `FONVSAVE_PROPS_PLAYER_TITLE`    | `5`   |
| `FONVSAVE_PROPS_PLAYER_LOCATION` | `6`   |
| `FONVSAVE_PROPS_PLAYER_PLAYTIME` | `7`   |
| `FONVSAVE_PROPS_SNAPSHOT_WIDTH`  | `8`   |
| `FONVSAVE_PROPS_SNAPSHOT_HEIGHT` | `9`   |
| `FONVSAVE_PROPS_SNAPSHOT`        | `10`  |



# Macros

| Macro                           | Value                    |
| :------------------------------ | :----------------------- |
| `FONVSAVE_GAME_NAME`            | `Fallout: New Vegas`     |
| `FONVSAVE_SIGNATURE`            | `FO3SAVEGAME`            |
| `FONVSAVE_SIGNATURE_LENGTH`     | `11`                     |
| `FONVSAVE_PROPS_COUNT`          | `11`                     |
| `FONVSAVE_SAVE_STANDARD_EXT`    | `.fos`                   |
| `FONVSAVE_MAX_SNAPSHOT_WIDTH`   | `512`                    |
| `FONVSAVE_MAX_SNAPSHOT_HEIGHT`  | `288`                    |
| `FONVSAVE_MAX_SNAPSHOT_LENGTH`  | `442368`                 |
| `FONVSAVE_SNAPSHOT_COLOR_BYTES` | `3`                      |
| `FONVSAVE_PLAYER_SEX_MALE`      | `0`                      |
| `FONVSAVE_PLAYER_SEX_FEMALE`    | `1`                      |
| `FONVSAVE_PROPS_SIZE`           | `sizeof(FONVSAVE_PROPS)` |
| `FONVSAVE_SIZE`                 | `sizeof(FONVSAVE)`       |
