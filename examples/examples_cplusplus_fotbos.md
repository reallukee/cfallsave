<div align="center">

![Fallout Tactics: Brotherhood of Steel Logo 192x192](../assets/fotbos/fotbos_logo_192x192.png)

# *Fallout Tactics: Brotherhood of Steel*<br /> C++ Examples

[Back to Examples](../EXAMPLES.md)

</div>



# Summary

* [Read Save](#read-save)
* [Read Save (From `FOTBOSSAVE`)](#read-save-from-fotbossave)



# Read Save

## Source

```cpp
#include <iostream>
#include <cfallsave++.hpp>

using namespace std;
using namespace cfallsavepp;

int main(int argc, const char* argv[])
{
    string saveName = "fotbos.sav";

    if (!FOTBOSSave::isSave(saveName))
    {
        return 1;
    }

    FOTBOSSave* save = new FOTBOSSave(saveName);

    if (!save->isOpen())
    {
        return 1;
    }

    save->print();

    delete save;

    return 0;
}
```

## Documentation

* [`FOTBOSSave`](../docs/api_cplusplus_fotbos.md#fotbossave)
* [`FOTBOSSave::isSave`](../docs/api_cplusplus_fotbos.md#fotbossaveissave-static)
* [`FOTBOSSave::FOTBOSSave`](../docs/api_cplusplus_fotbos.md#fotbossavefotbossave)
* [`FOTBOSSave::isOpen`](../docs/api_cplusplus_fotbos.md#fotbossaveisopen)
* [`FOTBOSSave::printSave`](../docs/api_cplusplus_fotbos.md#fotbossaveprintsave)
* [`FOTBOSSave::~FOTBOSSave`](../docs/api_cplusplus_fotbos.md#fotbossavefotbossave-1)



# Read Save (From `FOTBOSSAVE`)

## Source

```cpp
#include <iostream>
#include <cfallsave++.hpp>

using namespace std;
using namespace cfallsavepp;

int main(int argc, const char* argv[])
{
    string saveName = "fotbos.sav";

    const char* c_saveName = saveName.c_str();

    if (!isFOTBOSSave(c_saveName))
    {
        return 1;
    }

    FOTBOSSAVE* save = readFOTBOSSave(c_saveName);

    if (!isFOTBOSSaveOpen(save))
    {
        return 1;
    }

    FOTBOSSave* savepp = new FOTBOSSave(save);

    savepp->print();

    delete savepp;

    return 0;
}
```

## Documentation

* [`FOTBOSSAVE`](../docs/api_fotbos.md#fotbossave)
* [`isFOTBOSSave`](../docs/api_fotbos.md#isfotbossave)
* [`readFOTBOSSave`](../docs/api_fotbos.md#readfotbossave)
* [`isFOTBOSSaveOpen`](../docs/api_fotbos.md#isfotbossaveopen)
* [`FOTBOSSave`](../docs/api_cplusplus_fotbos.md#fotbossave)
* [`FOTBOSSave::printSave`](../docs/api_cplusplus_fotbos.md#fotbossaveprintsave)
* [`FOTBOSSave::~FOTBOSSave`](../docs/api_cplusplus_fotbos.md#fotbossavefotbossave-1)
