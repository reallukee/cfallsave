<div align="center">

![Fallout 2 Logo 192x192](../assets/fo2/fo2_logo_192x192.png)

# *Fallout 2*<br /> C Examples

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
