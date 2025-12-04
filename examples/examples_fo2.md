<div align="center">

![Fallout 2 Logo 192x192](../assets/fo2/fo2_logo_192x192.png)

# *Fallout 2*<br /> C Examples

[Back to Examples](../EXAMPLES.md)

</div>



# Summary

* [Read Save](#read-save)
* [Write Save](#write-save)
* [Read Save Property](#read-save-property)



# Read Save

## Source

```c
#include <stdio.h>
#include <cfallsave.h>

int main(int argc, const char* argv[])
{
    char* saveName = "fo2.dat";

    if (!isFO2Save(saveName))
    {
        return 1;
    }

    FO2SAVE* save = readFO2Save(saveName);

    if (!isFO2SaveOpen(save))
    {
        return 1;
    }

    printFO2Save(save);

    closeFO2Save(save);

    return 0;
}
```

## Documentation

* [`FO2SAVE`](../docs/api_fo2.md#fo2save)
* [`isFO2Save`](../docs/api_fo2.md#isfo2save)
* [`readFO2Save`](../docs/api_fo2.md#readfo2save)
* [`isFO2SaveOpen`](../docs/api_fo2.md#isfo2saveopen)
* [`printFO2Save`](../docs/api_fo2.md#printfo2save)
* [`closeFO2Save`](../docs/api_fo2.md#closefo2save)



# Write Save

## Source

```c
#include <stdio.h>
#include <cfallsave.h>

int main(int argc, const char* argv[])
{
    char* saveName = "fo2.dat";

    if (!isFO2Save(saveName))
    {
        return 1;
    }

    FO2SAVE* save = readFO2Save(saveName);

    if (!isFO2SaveOpen(save))
    {
        return 1;
    }

    char saveNameProp[FO2SAVE_STRING_SIZE] = "Save 1";

    bool result = setFO2SaveProp(
        save,
        FO2SAVE_PROPS_SAVE_NAME,
        (void**)&saveNameProp
    );

    if (result)
    {
        writeFO2Save(save);
    }

    closeFO2Save(save);

    return 0;
}
```

## Documentation

* [`FO2SAVE`](../docs/api_fo2.md#fo2save)
* [`isFO2Save`](../docs/api_fo2.md#isfo2save)
* [`readFO2Save`](../docs/api_fo2.md#readfo2save)
* [`isFO2SaveOpen`](../docs/api_fo2.md#isfo2saveopen)
* [`setFO2SaveProp`](../docs/api_fo2.md#setfo2saveprop)
* [`writeFO2Save`](../docs/api_fo2.md#writefo2save)
* [`closeFO2Save`](../docs/api_fo2.md#closefo2save)



# Read Save Property

## Source

```c
#include <stdio.h>
#include <cfallsave.h>

int main(int argc, const char* argv[])
{
    char* saveName = "fo2.dat";

    if (!isFO2Save(saveName))
    {
        return 1;
    }

    FO2SAVE* save = readFO2Save(saveName);

    if (!isFO2SaveOpen(save))
    {
        return 1;
    }

    char saveNameProp[FO2SAVE_STRING_SIZE];

    bool result = readFO2SaveProp(
        save,
        FO2SAVE_PROPS_SAVE_NAME,
        (void**)&saveNameProp
    );

    if (result)
    {
        printf("Property: %s\n", saveNameProp);
    }

    closeFO2Save(save);

    return 0;
}
```

## Documentation

* [`FO2SAVE`](../docs/api_fo2.md#fo2save)
* [`isFO2Save`](../docs/api_fo2.md#isfo2save)
* [`readFO2Save`](../docs/api_fo2.md#readfo2save)
* [`isFO2SaveOpen`](../docs/api_fo2.md#isfo2saveopen)
* [`readFO2SaveProp`](../docs/api_fo2.md#readfo2saveprop)
* [`closeFO2Save`](../docs/api_fo2.md#closefo2save)
