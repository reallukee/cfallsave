<div align="center">

![Fallout 3 Logo 192x192](../assets/fo3/fo3_logo_192x192.png)

# *Fallout 3*<br /> C++ Examples

[Back to Examples](../EXAMPLES.md)

</div>



# Summary

* [Read Save](#read-save)
* [Read Save (From `FO3SAVE`)](#read-save-from-fo3save)



# Read Save

## Source

```cpp
#include <iostream>
#include <cfallsave++.hpp>

using namespace std;
using namespace cfallsavepp;

int main(int argc, const char* argv[])
{
    string saveName = "fo3.fos";

    if (!FO3Save::isSave(saveName))
    {
        return 1;
    }

    FO3Save* save = new FO3Save(saveName);

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

* [`FO3Save`](../docs/api_cplusplus_fo3.md#fo3save)
* [`FO3Save::isSave`](../docs/api_cplusplus_fo3.md#fo3saveissave-static)
* [`FO3Save::FO3Save`](../docs/api_cplusplus_fo3.md#fo3savefo3save)
* [`FO3Save::isOpen`](../docs/api_cplusplus_fo3.md#fo3saveisopen)
* [`FO3Save::printSave`](../docs/api_cplusplus_fo3.md#fo3saveprintsave)
* [`FO3Save::~FO3Save`](../docs/api_cplusplus_fo3.md#fo3savefo3save-1)



# Read Save (From `FO3SAVE`)

## Source

```cpp
#include <iostream>
#include <cfallsave++.hpp>

using namespace std;
using namespace cfallsavepp;

int main(int argc, const char* argv[])
{
    string saveName = "fo3.fos";

    const char* c_saveName = saveName.c_str();

    if (!isFO3Save(c_saveName))
    {
        return 1;
    }

    FO3SAVE* save = readFO3Save(c_saveName);

    if (!isFO3SaveOpen(save))
    {
        return 1;
    }

    FO3Save* savepp = new FO3Save(save);

    savepp->print();

    delete savepp;

    return 0;
}
```

## Documentation

* [`FO3SAVE`](../docs/api_fo3.md#fo3save)
* [`isFO3Save`](../docs/api_fo3.md#isfo3save)
* [`readFO3Save`](../docs/api_fo3.md#readfo3save)
* [`isFO3SaveOpen`](../docs/api_fo3.md#isfo3saveopen)
* [`FO3Save`](../docs/api_cplusplus_fo3.md#fo3save)
* [`FO3Save::printSave`](../docs/api_cplusplus_fo3.md#fo3saveprintsave)
* [`FO3Save::~FO3Save`](../docs/api_cplusplus_fo3.md#fo3savefo3save-1)
