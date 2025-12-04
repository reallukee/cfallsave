<div align="center">

![Fallout 4 Logo 192x192](../assets/fo4/fo4_logo_192x192.png)

# *Fallout 4*<br /> C Examples

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
    char* saveName = "fo4.fos";

    if (!isFO4Save(saveName))
    {
        return 1;
    }

    FO4SAVE* save = readFO4Save(saveName);

    if (!isFO4SaveOpen(save))
    {
        return 1;
    }

    printFO4Save(save);

    closeFO4Save(save);

    return 0;
}
```

## Documentation

* [`FO4SAVE`](../docs/api_fo4.md#fo4save)
* [`isFO4Save`](../docs/api_fo4.md#isfo4save)
* [`readFO4Save`](../docs/api_fo4.md#readfo4save)
* [`isFO4SaveOpen`](../docs/api_fo4.md#isfo4saveopen)
* [`printFO4Save`](../docs/api_fo4.md#printfo4save)
* [`closeFO4Save`](../docs/api_fo4.md#closefo4save)



# Write Save

## Source

```c
#include <stdio.h>
#include <cfallsave.h>

int main(int argc, const char* argv[])
{
    char* saveName = "fo4.fos";

    if (!isFO4Save(saveName))
    {
        return 1;
    }

    FO4SAVE* save = readFO4Save(saveName);

    if (!isFO4SaveOpen(save))
    {
        return 1;
    }

    int engineVersionProp = 0;

    bool result = setFO4SaveProp(
        save,
        FO4SAVE_PROPS_ENGINE_VERSION,
        (void**)&engineVersionProp
    );

    if (result)
    {
        writeFO4Save(save);
    }

    closeFO4Save(save);

    return 0;
}
```

## Documentation

* [`FO4SAVE`](../docs/api_fo4.md#fo4save)
* [`isFO4Save`](../docs/api_fo4.md#isfo4save)
* [`readFO4Save`](../docs/api_fo4.md#readfo4save)
* [`isFO4SaveOpen`](../docs/api_fo4.md#isfo4saveopen)
* [`setFO4SaveProp`](../docs/api_fo4.md#setfo4saveprop)
* [`writeFO4Save`](../docs/api_fo4.md#writefo4save)
* [`closeFO4Save`](../docs/api_fo4.md#closefo4save)



# Read Save Property

## Source

```c
#include <stdio.h>
#include <cfallsave.h>

int main(int argc, const char* argv[])
{
    char* saveName = "fo4.fos";

    if (!isFO4Save(saveName))
    {
        return 1;
    }

    FO4SAVE* save = readFO4Save(saveName);

    if (!isFO4SaveOpen(save))
    {
        return 1;
    }

    int engineVersionProp;

    bool result = readFO4SaveProp(
        save,
        FO4SAVE_PROPS_ENGINE_VERSION,
        (void**)&engineVersionProp
    );

    if (result)
    {
        printf("Property: %u\n", engineVersionProp);
    }

    closeFO4Save(save);

    return 0;
}
```

## Documentation

* [`FO4SAVE`](../docs/api_fo4.md#fo4save)
* [`isFO4Save`](../docs/api_fo4.md#isfo4save)
* [`readFO4Save`](../docs/api_fo4.md#readfo4save)
* [`isFO4SaveOpen`](../docs/api_fo4.md#isfo4saveopen)
* [`readFO4SaveProp`](../docs/api_fo4.md#readfo4saveprop)
* [`closeFO4Save`](../docs/api_fo4.md#closefo4save)
