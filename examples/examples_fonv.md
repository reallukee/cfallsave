<div align="center">

![Fallout: New Vegas Logo 192x192](../assets/fonv/fonv_logo_192x192.png)

# *Fallout: New Vegas*<br /> C Examples

[Back to Examples](../EXAMPLES.md)

</div>



# Summary

* [Read Save](#read-save)



# Read Save

## Source

```c
#include <stdio.h>
#include <cfallsave.h>

int main(int argc, char* argv[])
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
