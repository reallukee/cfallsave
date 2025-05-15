<div align="center">

![Fallout 2 Logo 192x192](../assets/fo2/fo2_logo_192x192.png)

# *Fallout 2*<br /> C++ Examples

[Back to Examples](../EXAMPLES.md)

</div>



# Summary

* [Read Save](#read-save)
* [Read Save (From `FO2SAVE`)](#read-save-from-fo2save)



# Read Save

## Source

```cpp
#include <iostream>
#include <cfallsave++.hpp>

using namespace std;
using namespace cfallsavepp;

int main(int argc, char* argv[])
{
    string saveName = "fo2.dat";

    if (!FO2Save::isSave(saveName))
    {
        return 1;
    }

    FO2Save* save = new FO2Save(saveName);

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

* [`FO2Save`](../docs/api_cplusplus_fo2.md#fo2save)
* [`FO2Save::isSave`](../docs/api_cplusplus_fo2.md#fo2saveissave-static)
* [`FO2Save::FO2Save`](../docs/api_cplusplus_fo2.md#fo2savefo2save)
* [`FO2Save::isOpen`](../docs/api_cplusplus_fo2.md#fo2saveisopen)
* [`FO2Save::printSave`](../docs/api_cplusplus_fo2.md#fo2saveprintsave)
* [`FO2Save::~FO2Save`](../docs/api_cplusplus_fo2.md#fo2savefo2save-1)



# Read Save (From `FO2SAVE`)

## Source

```cpp
#include <iostream>
#include <cfallsave++.hpp>

using namespace std;
using namespace cfallsavepp;

int main(int argc, char* argv[])
{
    string saveName = "fo2.dat";

    const char* c_saveName = saveName.c_str();

    if (!isFO2Save(c_saveName))
    {
        return 1;
    }

    FO2SAVE* save = readFO2Save(c_saveName);

    if (!isFO2SaveOpen(save))
    {
        return 1;
    }

    FO2Save* savepp = new FO2Save(save);

    savepp->print();

    delete savepp;

    return 0;
}
```

## Documentation

* [`FO2SAVE`](../docs/api_fo2.md#fo2save)
* [`isFO2Save`](../docs/api_fo2.md#isfo2save)
* [`readFO2Save`](../docs/api_fo2.md#readfo2save)
* [`isFO2SaveOpen`](../docs/api_fo2.md#isfo2saveopen)
* [`FO2Save`](../docs/api_cplusplus_fo2.md#fo2save)
* [`FO2Save::printSave`](../docs/api_cplusplus_fo2.md#fo2saveprintsave)
* [`FO2Save::~FO2Save`](../docs/api_cplusplus_fo2.md#fo2savefo2save-1)
