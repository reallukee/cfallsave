<div align="center">

![Fallout 4 Logo 192x192](../assets/fo4/fo4_logo_192x192.png)

# *Fallout 4*<br /> C API

[Back to Documentation](../DOCS.md)

</div>



<br />

> [!TIP]
> Looking for *Fallout 4* C++ API?<br />
> Click [here](./api_cplusplus_fo4.md)!



# Summary

* [Code](#code)
* [Functions](#functions)
* [Structures](#structures)
* [Enums](#enums)
* [Macros](#macros)



# Code

> Headers: [`fo4.h`](../src/fo4.h)

> Sources: [`fo4.c`](../src/fo4.c)



# Functions

* [`readFO4Save`](#readfo4save)
* [`writeFO4Save`](#writefo4save)
* [`isFO4Save`](#isfo4save)
* [`isFO4SaveOpen`](#isfo4saveopen)
* [`closeFO4Save`](#closefo4save)
* [`getFO4SaveProp`](#getfo4saveprop)
* [`setFO4SaveProp`](#setfo4saveprop)
* [`readFO4SaveProp`](#readfo4saveprop)
* [`writeFO4SaveProp`](#writefo4saveprop)
* [`printFO4Save`](#printfo4save)
* [`printFO4SaveProps`](#printfo4saveprops)
* [`printFO4SavePropAddresses`](#printfo4savepropaddresses)
* [`printFO4SaveSnapshot`](#printfo4savesnapshot)



## `readFO4Save`

**Params**

* `const char*` `saveName`

**Returns**

[`FO4SAVE*`](#fo4save) or `NULL`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");
```



## `writeFO4Save`

> [!CAUTION]
> Experimental function!

**Params**

* [`FO4SAVE*`](#fo4save) `save`

**Returns**

`bool`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

bool result = writeFO4Save(save);
```



## `isFO4Save`

**Params**

* `const char*` `saveName`

**Returns**

`bool`

**Examples**

```c
bool result = isFO4Save("fo4.fos");

if (result)
{
    printf("FO4 Save\n");
}
```



## `isFO4SaveOpen`

**Params**

* [`FO4SAVE*`](#fo4save) `save`

**Returns**

`bool`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

bool result = isFO4SaveOpen(save);

if (result)
{
    printf("FO4 Save is Open\n");
}
```



## `closeFO4Save`

**Params**

* [`FO4SAVE*`](#fo4save) `save`

**Returns**

`void`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

closeFO4Save(save);
```



## `getFO4SaveProp`

**Params**

* [`FO4SAVE*`](#fo4save) `save`
* [`FO4SAVE_PROPS`](#fo4save_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

int engineVersion = 0;

bool result = getFO4SaveProp(save, FO4SAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result)
{
    printf("Property: %u\n", engineVersion);
}
```



## `setFO4SaveProp`

**Params**

* [`FO4SAVE*`](#fo4save) `save`
* [`FO4SAVE_PROPS`](#fo4save_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

int engineVersion = 0;

bool result = setFO4SaveProp(save, FO4SAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result)
{
    printf("Property: %u\n", engineVersion);
}
```



## `readFO4SaveProp`

**Params**

* [`FO4SAVE*`](#fo4save) `save`
* [`FO4SAVE_PROPS`](#fo4save_props) `prop`
* `void**` `destination`

**Returns**

`bool`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

int engineVersion = 0;

bool result = readFO4SaveProp(save, FO4SAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result)
{
    printf("Property: %u\n", engineVersion);
}
```



## `writeFO4SaveProp`

> [!CAUTION]
> Experimental function!

**Params**

* [`FO4SAVE*`](#fo4save) `save`
* [`FO4SAVE_PROPS`](#fo4save_props) `prop`
* `void**` `value`

**Returns**

`bool`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

int engineVersion = 0;

bool result = writeFO4SaveProp(save, FO4SAVE_PROPS_ENGINE_VERSION, (void**)&engineVersion);

if (result)
{
    printf("Property: %u\n", engineVersion);
}
```



## `printFO4Save`

**Params**

* [`FO4SAVE*`](#fo4save) `save`

**Returns**

`bool`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

printFO4Save(save);
```



## `printFO4SaveProps`

**Params**

* [`FO4SAVE*`](#fo4save) `save`

**Returns**

`bool`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

printFO4SaveProps(save);
```



## `printFO4SavePropAddresses`

**Params**

* [`FO4SAVE*`](#fo4save) `save`

**Returns**

`bool`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

printFO4SavePropAddresses(save);
```



## `printFO4SaveSnapshot`

**Params**

* [`FO4SAVE*`](#fo4save) `save`

**Returns**

`bool`

**Examples**

```c
FO4SAVE* save = readFO4Save("fo4.fos");

printFO4SaveSnapshot(save);
```



# Structures

## `FO4SAVE`

* `FILE* save`
* `char* saveFileName`
* `char saveSignature[FO4SAVE_SIGNATURE_LENGTH + 1]`
* `unsigned engineVersion`
* `unsigned saveNumber`
* `char* playerName`
* `unsigned playerLevel`
* `char* playerLocation`
* `char* playerPlaytime`
* `char* playerRace`
* `short unsigned int playerSex`
* `float playerCurrentXp`
* `float playerRequiredXp`
* `unsigned snapshotWidth`
* `unsigned snapshotHeight`
* `long unsigned int snapshotLength`
* `unsigned char* snapshot`
* `long unsigned int propAddresses[FO4SAVE_PROPS_COUNT]`



# Enums

## `FO4SAVE_PROPS`

| Field                              | Value |
| :--------------------------------- | :---: |
| `FO4SAVE_PROPS_SAVE_SIGNATURE`     | `0`   |
| `FO4SAVE_PROPS_ENGINE_VERSION`     | `1`   |
| `FO4SAVE_PROPS_SAVE_NUMBER`        | `2`   |
| `FO4SAVE_PROPS_PLAYER_NAME`        | `3`   |
| `FO4SAVE_PROPS_PLAYER_LEVEL`       | `4`   |
| `FO4SAVE_PROPS_PLAYER_LOCATION`    | `5`   |
| `FO4SAVE_PROPS_PLAYER_PLAYTIME `   | `6`   |
| `FO4SAVE_PROPS_PLAYER_RACE`        | `7`   |
| `FO4SAVE_PROPS_PLAYER_SEX`         | `8`   |
| `FO4SAVE_PROPS_PLAYER_CURRENT_XP`  | `9`   |
| `FO4SAVE_PROPS_PLAYER_REQUIRED_XP` | `10`  |
| `FO4SAVE_PROPS_SNAPSHOT_WIDTH`     | `11`  |
| `FO4SAVE_PROPS_SNAPSHOT_HEIGHT`    | `12`  |
| `FO4SAVE_PROPS_SNAPSHOT`           | `13`  |



# Macros

| Macro                          | Value                   |
| :----------------------------- | :---------------------- |
| `FO4SAVE_GAME_NAME`            | `Fallout 4`             |
| `FO4SAVE_SIGNATURE`            | `FO4_SAVEGAME`          |
| `FO4SAVE_SIGNATURE_LENGTH`     | `12`                    |
| `FO4SAVE_PROPS_COUNT`          | `14`                    |
| `FO4SAVE_STANDARD_EXT`         | `.fos`                  |
| `FO4SAVE_MAX_SNAPSHOT_WIDTH`   | `640`                   |
| `FO4SAVE_MAX_SNAPSHOT_HEIGHT`  | `384`                   |
| `FO4SAVE_MAX_SNAPSHOT_LENGTH`  | `983040`                |
| `FO4SAVE_SNAPSHOT_COLOR_BYTES` | `4`                     |
| `FO4SAVE_SNAPSHOT_FORMAT`      | `RGBA`                  |
| `FO4SAVE_PLAYER_SEX_MALE`      | `0`                     |
| `FO4SAVE_PLAYER_SEX_FEMALE`    | `1`                     |
| `FO4SAVE_PROPS_SIZE`           | `sizeof(FO4SAVE_PROPS)` |
| `FO4SAVE_SIZE`                 | `sizeof(FO4SAVE)`       |
