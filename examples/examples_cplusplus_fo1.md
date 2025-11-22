<div align="center">

![Fallout 1 Logo 192x192](../assets/fo1/fo1_logo_192x192.png)

# *Fallout 1*<br /> C++ Examples

[Back to Examples](../EXAMPLES.md)

</div>



# Summary

* [Read Save](#read-save)
* [Read Save (From `FO1SAVE`)](#read-save-from-fo1save)



# Read Save

## Source

```cpp
#include <iostream>
#include <cfallsave++.hpp>

using namespace std;
using namespace cfallsavepp;

int main(int argc, const char* argv[])
{
    string saveName = "fo1.dat";

    if (!FO1Save::isSave(saveName))
    {
        return 1;
    }

    FO1Save* save = new FO1Save(saveName);

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

* [`FO1Save`](../docs/api_cplusplus_fo1.md#fo1save)
* [`FO1Save::isSave`](../docs/api_cplusplus_fo1.md#fo1saveissave-static)
* [`FO1Save::FO1Save`](../docs/api_cplusplus_fo1.md#fo1savefo1save)
* [`FO1Save::isOpen`](../docs/api_cplusplus_fo1.md#fo1saveisopen)
* [`FO1Save::printSave`](../docs/api_cplusplus_fo1.md#fo1saveprintsave)
* [`FO1Save::~FO1Save`](../docs/api_cplusplus_fo1.md#fo1savefo1save-1)



# Read Save (From `FO1SAVE`)

## Source

```cpp
#include <iostream>
#include <cfallsave++.hpp>

using namespace std;
using namespace cfallsavepp;

int main(int argc, const char* argv[])
{
    string saveName = "fo1.dat";

    const char* c_saveName = saveName.c_str();

    if (!isFO1Save(c_saveName))
    {
        return 1;
    }

    FO1SAVE* save = readFO1Save(c_saveName);

    if (!isFO1SaveOpen(save))
    {
        return 1;
    }

    FO1Save* savepp = new FO1Save(save);

    savepp->print();

    delete savepp;

    return 0;
}
```

## Documentation

* [`FO1SAVE`](../docs/api_fo1.md#fo1save)
* [`isFO1Save`](../docs/api_fo1.md#isfo1save)
* [`readFO1Save`](../docs/api_fo1.md#readfo1save)
* [`isFO1SaveOpen`](../docs/api_fo1.md#isfo1saveopen)
* [`FO1Save`](../docs/api_cplusplus_fo1.md#fo1save)
* [`FO1Save::printSave`](../docs/api_cplusplus_fo1.md#fo1saveprintsave)
* [`FO1Save::~FO1Save`](../docs/api_cplusplus_fo1.md#fo1savefo1save-1)
