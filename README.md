# CFallSave

A C Library to Read and Write Fallout Save Files

# Documentation

* [Fallout 4 Save File Format](./fo4.md)
* [Fallout New Vegas Save File Format](./fonv.md)
* [Fallout 4 Save File Format](./fo3.md)

# Examples



## Read Fallout 4 Save

> [Example](./examples/read.c)

```c
#include "cfallsave.h"

int main(int argc, char* argv[])
{
    FO4SAVE* save = readFO4Save("fo4.fos");

    if (save == NULL)
    {
        return -1;
    }

    printFO4Save(save);

    closeFO4Save(save);

    return 0;
}
```



## Write Fallout 4 Save

> [Example](./examples/write.c)

```c
#include "cfallsave.h"

int main(int argc, char* argv[])
{
    FO4SAVE* save = readFO4Save("fo4.fos");

    if (save == NULL)
    {
        return -1;
    }

    printFO4Save(save);

    wroteFO4Save(save, "newfo4.fos");

    return 0;
}
```



# License

[MIT](./LICENSE) License.
