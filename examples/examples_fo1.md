<div align="center">

![Fallout 1 Logo 192x192](../assets/fo1/fo1_logo_192x192.png)

# *Fallout 1*<br /> C Examples

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
