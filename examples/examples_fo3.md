<div align="center">

![Fallout 3 Logo 192x192](../assets/fo3/fo3_logo_192x192.png)

# *Fallout 3*<br /> C Examples

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
    char* saveName = "fo3.fos";

    if (!isFO3Save(saveName))
    {
        return 1;
    }

    FO3SAVE* save = readFO3Save(saveName);

    if (!isFO3SaveOpen(save))
    {
        return 1;
    }

    printFO3Save(save);

    closeFO3Save(save);

    return 0;
}
```

## Documentation

* [`FO3SAVE`](../docs/api_fo3.md#fo3save)
* [`isFO3Save`](../docs/api_fo3.md#isfo3save)
* [`readFO3Save`](../docs/api_fo3.md#readfo3save)
* [`isFO3SaveOpen`](../docs/api_fo3.md#isfo3saveopen)
* [`printFO3Save`](../docs/api_fo3.md#printfo3save)
* [`closeFO3Save`](../docs/api_fo3.md#closefo3save)
