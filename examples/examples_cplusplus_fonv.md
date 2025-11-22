<div align="center">

![Fallout: New Vegas Logo 192x192](../assets/fonv/fonv_logo_192x192.png)

# *Fallout: New Vegas*<br /> C++ Examples

[Back to Examples](../EXAMPLES.md)

</div>



# Summary

* [Read Save](#read-save)
* [Read Save (From `FONVSAVE`)](#read-save-from-fonvsave)



# Read Save

## Source

```cpp
#include <iostream>
#include <cfallsave++.hpp>

using namespace std;
using namespace cfallsavepp;

int main(int argc, const char* argv[])
{
    string saveName = "fonv.fos";

    if (!FONVSave::isSave(saveName))
    {
        return 1;
    }

    FONVSave* save = new FONVSave(saveName);

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

* [`FONVSave`](../docs/api_cplusplus_fonv.md#fonvsave)
* [`FONVSave::isSave`](../docs/api_cplusplus_fonv.md#fonvsaveissave-static)
* [`FONVSave::FONVSave`](../docs/api_cplusplus_fonv.md#fonvsavefonvsave)
* [`FONVSave::isOpen`](../docs/api_cplusplus_fonv.md#fonvsaveisopen)
* [`FONVSave::printSave`](../docs/api_cplusplus_fonv.md#fonvsaveprintsave)
* [`FONVSave::~FONVSave`](../docs/api_cplusplus_fonv.md#fonvsavefonvsave-1)



# Read Save (From `FONVSAVE`)

## Source

```cpp
#include <iostream>
#include <cfallsave++.hpp>

using namespace std;
using namespace cfallsavepp;

int main(int argc, const char* argv[])
{
    string saveName = "fonv.fos";

    const char* c_saveName = saveName.c_str();

    if (!isFONVSave(c_saveName))
    {
        return 1;
    }

    FONVSAVE* save = readFONVSave(c_saveName);

    if (!isFONVSaveOpen(save))
    {
        return 1;
    }

    FONVSave* savepp = new FONVSave(save);

    savepp->print();

    delete savepp;

    return 0;
}
```

## Documentation

* [`FONVSAVE`](../docs/api_fonv.md#fonvsave)
* [`isFONVSave`](../docs/api_fonv.md#isfonvsave)
* [`readFONVSave`](../docs/api_fonv.md#readfonvsave)
* [`isFONVSaveOpen`](../docs/api_fonv.md#isfonvsaveopen)
* [`FONVSave`](../docs/api_cplusplus_fonv.md#fonvsave)
* [`FONVSave::printSave`](../docs/api_cplusplus_fonv.md#fonvsaveprintsave)
* [`FONVSave::~FONVSave`](../docs/api_cplusplus_fonv.md#fonvsavefonvsave-1)
