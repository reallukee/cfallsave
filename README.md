<div align="center">

![Logo 192x192](./assets/logo_192x192.gif)

# CFallSave

![CFallSave License](https://img.shields.io/github/license/reallukee/cfallsave?style=flat&label=License)

☢️ A C/C++ Library to Read and Write Fallout Save Files

</div>

<br />

> [!IMPORTANT]
> Currently in development!<br />
> Nothing is final and/or complete!



# Summary

* [Introduction](#introduction)
* [Organization](#organization)
* [Documentation](#documentation)
* [Examples](#examples)
* [Starting](#starting)
* [Author](#author)
* [License](#license)



# Introduction

```
*****************
* FO4SAVE PROPS *
*****************

Game Name          : Fallout 4
Save File Name     : fo4.fos

Save Signature     : FO4_SAVEGAME
Engine Version     : 15
Save Number        : 100
Player Name        : John Fallout
Player Level       : 150
Player Location    : Commonwealth
Player Playtime    : 7g.00h.00m.7 giorni.00 ore.00 minuti
Player Race        : HumanRace
Player Sex         : 0
Player Current Xp  : 7500.000000
Player Required Xp : 0.000000
Snapshot Width     : 640
Snapshot Height    : 384
Snapshot Length    : 983040

**************************
* FO4SAVE PROP ADDRESSES *
**************************

Game Name          : Fallout 4
Save File Name     : fo4.fos

Save Signature     : 0000000000000000 0000
Engine Version     : 0000000000000016 0010
Save Number        : 0000000000000020 0014
Player Name        : 0000000000000024 0018
Player Level       : 0000000000000038 0026
Player Location    : 0000000000000042 002A
Player Playtime    : 0000000000000056 0038
Player Race        : 0000000000000094 005E
Player Sex         : 0000000000000105 0069
Player Current Xp  : 0000000000000107 006B
Player Required Xp : 0000000000000111 006F
Snapshot Width     : 0000000000000123 007B
Snapshot Height    : 0000000000000127 007F
```



# Organization

* `.github` GitHub settings
* `.vscode` Visual Studio Code settings
* `assets` Project assets
* `docs` Documentation
* `examples` Examples
* `src` Source code
* `test` Test
* `windows` Visual Studio 2022 projects



# [Documentation](./DOCS.md)

* [APIs](./DOCS.md#apis)
  * [C APIs (CFallSave)](./DOCS.md#c-apis-cfallsave)
  * [C++ APIs (CFallSave++)](./DOCS.md#c-apis-cfallsave-1)
* [Save Formats](./DOCS.md#save-formats)



# [Examples](./EXAMPLES.md)

* [CFallSave](./EXAMPLES.md#cfallsave)
* [CFallSave++](./EXAMPLES.md#cfallsave-1)



# Starting

* [Requirements](#1-requirements)
* [Get the source](#2-get-the-source)
* [Building](#3-building)



## 1. Requirements

- [Linux Requirements](#linux-requirements)
- [Windows Requirements](#windows-requirements)



### Linux Requirements

* *git*
* *gcc*
* *g++*
* *make*



### Windows Requirements

* [*Visual Studio 2022*]()
    * *Desktop development with C++*
* [*Build Tools for Visual Studio 2022*]()
    * *Desktop development with C++*



## 2. Get the source

* Using [git](#using-git)
* Using [GitHub](#using-github)



### Using `git`

```git
git clone https://github.com/reallukee/cfallsave.git
```



### Using `GitHub`

> [Download](https://github.com/reallukee/cfallsave/archive/refs/heads/main.zip)



## 3. Building

* [Linux Building](#linux-building)
* [Windows Building](#windows-building)



### Linux Building

1. Enter repository

    ```bash
    cd cfallsave/
    ```

2. Build using *make*

    ```bash
    # CFallSave
    make -f cfallsave.makefile build

    # CFallSave++
    make -f cfallsave++.makefile build
    ```

3. View output

    ```bash
    ls bin/
    ```



### Windows Building

1. Setup environment

    ```cmd
    REM Visual Studio 2022
    CALL "%ProgramFiles%\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd"

    REM Build Tools for Visual Studio 2022
    CALL "%ProgramFiles% (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\vsdevcmd"
    ```

2. Enter repository

    ```cmd
    CD cfallsave\windows
    ```

3. Build using `msbuild`

    ```cmd
    REM CFallSave
    msbuild ./cfallsave -p:Configuration=Release -p:Platform=x86
    msbuild ./cfallsave -p:Configuration=Release -p:Platform=x64

    REM CFallSave++
    msbuild ./cfallsave++ -p:Configuration=Release -p:Platform=x86
    msbuild ./cfallsave++ -p:Configuration=Release -p:Platform=x64
    ```

4. View output

    ```cmd
    DIR bin
    ```



# Author

* [Luca Pollicino](https://github.com/reallukee)



# License

[MIT](./LICENSE) License
