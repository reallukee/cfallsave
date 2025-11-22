<div align="center">

![Fallout: New Vegas Logo 192x192](../assets/fonv/fonv_logo_192x192.png)

# *Fallout: New Vegas*<br /> C Examples

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
    char* saveName = "fonv.fos";

    if (!isFONVSave(saveName))
    {
        return 1;
    }

    FONVSAVE* save = readFONVSave(saveName);

    if (!isFONVSaveOpen(save))
    {
        return 1;
    }

    printFONVSave(save);

    closeFONVSave(save);

    return 0;
}
```

## Documentation

* [`FONVSAVE`](../docs/api_fonv.md#fonvsave)
* [`isFONVSave`](../docs/api_fonv.md#isfonvsave)
* [`readFONVSave`](../docs/api_fonv.md#readfonvsave)
* [`isFONVSaveOpen`](../docs/api_fonv.md#isfonvsaveopen)
* [`printFONVSave`](../docs/api_fonv.md#printfonvsave)
* [`closeFONVSave`](../docs/api_fonv.md#closefonvsave)



# Write Save

## Source

```c
#include <stdio.h>
#include <cfallsave.h>

int main(int argc, const char* argv[])
{
    char* saveName = "fonv.fos";

    if (!isFONVSave(saveName))
    {
        return 1;
    }

    FONVSAVE* save = readFONVSave(saveName);

    if (!isFONVSaveOpen(save))
    {
        return 1;
    }

    int engineVersionProp = 0;

    bool result = setFONVSaveProp(
        save,
        FONVSAVE_PROPS_ENGINE_VERSION,
        (void**)&engineVersionProp
    );

    if (result)
    {
        writeFONVSave(save);
    }

    closeFONVSave(save);

    return 0;
}
```

## Documentation

* [`FONVSAVE`](../docs/api_fonv.md#fonvsave)
* [`isFONVSave`](../docs/api_fonv.md#isfonvsave)
* [`readFONVSave`](../docs/api_fonv.md#readfonvsave)
* [`isFONVSaveOpen`](../docs/api_fonv.md#isfonvsaveopen)
* [`setFONVSaveProp`](../docs/api_fonv.md#setfonvsaveprop)
* [`writeFONVSave`](../docs/api_fonv.md#writefonvsave)
* [`closeFONVSave`](../docs/api_fonv.md#closefonvsave)



# Read Save Property

## Source

```c
#include <stdio.h>
#include <cfallsave.h>

int main(int argc, const char* argv[])
{
    char* saveName = "fonv.fos";

    if (!isFONVSave(saveName))
    {
        return 1;
    }

    FONVSAVE* save = readFONVSave(saveName);

    if (!isFONVSaveOpen(save))
    {
        return 1;
    }

    int engineVersionProp;

    bool result = readFONVSaveProp(
        save,
        FONVSAVE_PROPS_ENGINE_VERSION,
        (void**)&engineVersionProp
    );

    if (result) {
        printf("Property: %u\n", engineVersionProp);
    }

    closeFONVSave(save);

    return 0;
}
```

## Documentation

* [`FONVSAVE`](../docs/api_fonv.md#fonvsave)
* [`isFONVSave`](../docs/api_fonv.md#isfonvsave)
* [`readFONVSave`](../docs/api_fonv.md#readfonvsave)
* [`isFONVSaveOpen`](../docs/api_fonv.md#isfonvsaveopen)
* [`readFONVSaveProp`](../docs/api_fonv.md#readfonvsaveprop)
* [`closeFONVSave`](../docs/api_fonv.md#closefonvsave)
