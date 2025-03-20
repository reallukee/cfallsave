<div align="center">

![Logo 192x192](./assets/logo_192x192.gif)

# CFallSave

![CFallSave License](https://img.shields.io/github/license/reallukee/cfallsave?style=flat&label=License)

☢️ A C/C++ Library to Read Fallout Save Files

</div>



# Introduction

```c
#include "cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fo4.fos";

    if (!isFO4Save(saveName))
    {
        return -1;
    }

    FO4SAVE* save = readFO4Save(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFO4Save(save);

    closeFO4Save(save);

    return 0;
}
```

```cpp
#include <iostream>
#include "cfallsave.hpp"

using namespace std;
using namespace cfallsavepp;

int main(int argc, char* argv[])
{
    FO4Save* save = new FO4Save("fo4.fos");

    save->printSave();

    delete save;

    return 0;
}
```



# Documentation

> View the [Documentation](./DOCS.md)

* [APIs](./DOCS.md#apis)
* [Save Formats](./DOCS.md#save-formats)



# Examples

> View the [Examples](./EXAMPLES.md)

* [CFallSave](./EXAMPLES.md#cfallsave)
* [CFallSave++](./EXAMPLES.md#cfallsave-1)



# Building

* [Requirements](#1-requirements)
* [Get the source](#2-get-the-source)
* [Building](#3-building)



## 1. Requirements

- [Linux Requirements](#linux-requirements)
- [Windows Requirements](#windows-requirements)



### Linux Requirements

* gcc
* g++
* make

### Windows Requirements

* [Visual Studio 2022]()
    * Desktop development with C++

OR

* [Build Tools for Visual Studio 2022]()
    * Desktop development with C++



## 2. Get the source

* Using [`git`](#using-git)
* Using [`GitHub`](#using-github)

### Using `git`

```git
git clone https://github.com/reallukee/cfallsave.git
```

### Using `GitHub`

> [Download](https://github.com/reallukee/cfallsave/archive/refs/heads/main.zip)



## 3. Building

* [Linux](#linux)
* [Windows](#windows)



### Linux

```bash
cd cfallsave/
```

```bash
# CFallSave
make -f cfallsave.makefile

# CFallSave++
make -f cfallsave++.makefile
```

### Windows

```batch
:: Visual Studio 2022
call "%ProgramFiles%\Microsoft Visual Studio\2022\Community\Common7\Tools\vsdevcmd"

:: Build Tools for Visual Studio 2022
call "%ProgramFiles% (x86)\Microsoft Visual Studio\2022\BuildTools\Common7\Tools\vsdevcmd"
```

```batch
cd cfallsave\windows
```

```batch
:: CFallSave
msbuild ./cfallsave -p:Configuration=Release -p:Platform=x64

:: CFallSave++
msbuild ./cfallsave++ -p:Configuration=Release -p:Platform=x64
```



# Author

* [Luca Pollicino](https://github.com/reallukee)



# License

[MIT](./LICENSE) License
