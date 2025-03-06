# Examples

* [Read Fallout 1 Save File](#read-fallout-1-save-file)
* [Read Fallout 2 Save File](#read-fallout-2-save-file)
* [Read Fallout Tactics: Brotherhood of Steel Save File](#read-fallout-tactics-brotherhood-of-steel-save-file)
* [Read Fallout 3 Save File](#read-fallout-3-save-file)
* [Read Fallout: New Vegas Save File](#read-fallout-new-vegas-save-file)
* [Read Fallout 4 Save File](#read-fallout-4-save-file)



## Read Fallout 1 Save File

> [Source code](./examples/readFO1Save.c)

```c
#include "cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fo1.dat";

    if (!isFO1Save(saveName))
    {
        return -1;
    }

    FO1SAVE* save = readFO1Save(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFO1Save(save);

    closeFO1Save(save);

    return 0;
}
```



## Read Fallout 2 Save File

> [Source code](./examples/readFO2Save.c)

```c
#include "cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fo2.dat";

    if (!isFO2Save(saveName))
    {
        return -1;
    }

    FO2SAVE* save = readFO2Save(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFO2Save(save);

    closeFO2Save(save);

    return 0;
}
```



## Read Fallout Tactics: Brotherhood of Steel Save File

> [Source code](./examples/readFOTBOSSave.c)

```c
#include "cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fotbos.sav";

    if (!isFOTBOSSave(saveName))
    {
        return -1;
    }

    FOTBOSSAVE* save = readFOTBOSSave(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFOTBOSSave(save);

    closeFOTBOSSave(save);

    return 0;
}
```



## Read Fallout 3 Save File

> [Source code](./examples/readFO3Save.c)

```c
#include "cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fo3.fos";

    if (!isFO3Save(saveName))
    {
        return -1;
    }

    FO3SAVE* save = readFO3Save(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFO3Save(save);

    closeFO3Save(save);

    return 0;
}
```



## Read Fallout: New Vegas Save File

> [Source code](./examples/readFONVSave.c)

```c
#include "cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fonv.fos";

    if (!isFONVSave(saveName))
    {
        return -1;
    }

    FONVSAVE* save = readFONVSave(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFONVSave(save);

    closeFONVSave(save);

    return 0;
}
```



## Read Fallout 4 Save File

> [Source code](./examples/readFO4Save.c)

```c
#include "cfallsave.h"

int main(int argc, char* argv[])
{
    char* saveName = "fo4.fos";

    if (!isFO4Save(saveName))
    {
        return -1;
    }

    FO4SAVE* save = readFO4Save(saveName);

    if (save == NULL)
    {
        return -1;
    }

    printFO4Save(save);

    closeFO4Save(save);

    return 0;
}
```
