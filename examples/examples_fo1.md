<div align="center">

![Fallout 1 Logo 192x192](../assets/fo1/fo1_logo_192x192.png)

# *Fallout 1*<br /> C Examples

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
    char* saveName = "fo1.dat";

    if (!isFO1Save(saveName))
    {
        return 1;
    }

    FO1SAVE* save = readFO1Save(saveName);

    if (!isFO1SaveOpen(save))
    {
        return 1;
    }

    printFO1Save(save);

    closeFO1Save(save);

    return 0;
}
```

## Documentation

* [`FO1SAVE`](../docs/api_fo1.md#fo1save)
* [`isFO1Save`](../docs/api_fo1.md#isfo1save)
* [`readFO1Save`](../docs/api_fo1.md#readfo1save)
* [`isFO1SaveOpen`](../docs/api_fo1.md#isfo1saveopen)
* [`printFO1Save`](../docs/api_fo1.md#printfo1save)
* [`closeFO1Save`](../docs/api_fo1.md#closefo1save)



# Write Save

## Source

```c
#include <stdio.h>
#include <cfallsave.h>

int main(int argc, const char* argv[])
{
    char* saveName = "fo1.dat";

    if (!isFO1Save(saveName))
    {
        return 1;
    }

    FO1SAVE* save = readFO1Save(saveName);

    if (!isFO1SaveOpen(save))
    {
        return 1;
    }

    char saveNameProp[FO1SAVE_STRING_SIZE] = "Save 1";

    bool result = setFO1SaveProp(
        save,
        FO1SAVE_PROPS_SAVE_NAME,
        (void**)&saveNameProp
    );

    if (result)
    {
        writeFO1Save(save);
    }

    closeFO1Save(save);

    return 0;
}
```

## Documentation

* [`FO1SAVE`](../docs/api_fo1.md#fo1save)
* [`isFO1Save`](../docs/api_fo1.md#isfo1save)
* [`readFO1Save`](../docs/api_fo1.md#readfo1save)
* [`isFO1SaveOpen`](../docs/api_fo1.md#isfo1saveopen)
* [`setFO1SaveProp`](../docs/api_fo1.md#setfo1saveprop)
* [`writeFO1Save`](../docs/api_fo1.md#writefo1save)
* [`closeFO1Save`](../docs/api_fo1.md#closefo1save)



# Read Save Property

## Source

```c
#include <stdio.h>
#include <cfallsave.h>

int main(int argc, const char* argv[])
{
    char* saveName = "fo1.dat";

    if (!isFO1Save(saveName))
    {
        return 1;
    }

    FO1SAVE* save = readFO1Save(saveName);

    if (!isFO1SaveOpen(save))
    {
        return 1;
    }

    char saveNameProp[FO1SAVE_STRING_SIZE];

    bool result = readFO1SaveProp(
        save,
        FO1SAVE_PROPS_SAVE_NAME,
        (void**)&saveNameProp
    );

    if (result)
    {
        printf("Property: %s\n", saveNameProp);
    }

    closeFO1Save(save);

    return 0;
}
```

## Documentation

* [`FO1SAVE`](../docs/api_fo1.md#fo1save)
* [`isFO1Save`](../docs/api_fo1.md#isfo1save)
* [`readFO1Save`](../docs/api_fo1.md#readfo1save)
* [`isFO1SaveOpen`](../docs/api_fo1.md#isfo1saveopen)
* [`readFO1SaveProp`](../docs/api_fo1.md#readfo1saveprop)
* [`closeFO1Save`](../docs/api_fo1.md#closefo1save)
