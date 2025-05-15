<div align="center">

![Fallout Tactics: Brotherhood of Steel Logo 192x192](../assets/fotbos/fotbos_logo_192x192.png)

# *Fallout Tactics: Brotherhood of Steel*<br /> C Examples

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
    char* saveName = "fotbos.sav";

    if (!isFOTBOSSave(saveName))
    {
        return 1;
    }

    FOTBOSSAVE* save = readFOTBOSSave(saveName);

    if (!isFOTBOSSaveOpen(save))
    {
        return 1;
    }

    printFOTBOSSave(save);

    closeFOTBOSSave(save);

    return 0;
}
```

## Documentation

* [`FOTBOSSAVE`](../docs/api_fotbos.md#fotbossave)
* [`isFOTBOSSave`](../docs/api_fotbos.md#isfotbossave)
* [`readFOTBOSSave`](../docs/api_fotbos.md#readfotbossave)
* [`isFOTBOSSaveOpen`](../docs/api_fotbos.md#isfotbossaveopen)
* [`printFOTBOSSave`](../docs/api_fotbos.md#printfotbossave)
* [`closeFOTBOSSave`](../docs/api_fotbos.md#closefotbossave)
