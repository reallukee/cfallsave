/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * Author  : Reallukee
 * Version : 1.0
 * License : MIT
 */

#include "fox.h"

FOXSAVE* readFOXSAVE(
    const char* saveName
)
{
    FOXSAVE* save = (FOXSAVE*)malloc(FOXSAVE_SIZE);

    if (isFO1Save(saveName))
    {
        save->save = readFO1Save(saveName);
        save->saveType = FOXSAVE_TYPE_FO1;

        return save;
    }

    if (isFO2Save(saveName))
    {
        save->save = readFO2Save(saveName);
        save->saveType = FOXSAVE_TYPE_FO2;

        return save;
    }

    if (isFO3Save(saveName))
    {
        save->save = readFO3Save(saveName);
        save->saveType = FOXSAVE_TYPE_FO3;

        return save;
    }

    if (isFONVSave(saveName))
    {
        save->save = readFONVSave(saveName);
        save->saveType = FOXSAVE_TYPE_FONV;

        return save;
    }

    if (isFO4Save(saveName))
    {
        save->save = readFO4Save(saveName);
        save->saveType = FOXSAVE_TYPE_FO4;

        return save;
    }

    free(save);

    return NULL;
}

void printFOXSAVE(
    FOXSAVE* save
)
{
    if (save->save != NULL)
    {
        switch (save->saveType)
        {
        case FOXSAVE_TYPE_FO1:
            printFO1Save((FO1SAVE*)save->save);
            break;

        case FOXSAVE_TYPE_FO2:
            printFO2Save((FO2SAVE*)save->save);
            break;

        case FOXSAVE_TYPE_FO3:
            printFO3Save((FO3SAVE*)save->save);
            break;

        case FOXSAVE_TYPE_FONV:
            printFONVSave((FONVSAVE*)save->save);
            break;

        case FOXSAVE_TYPE_FO4:
            printFO4Save((FO4SAVE*)save->save);
            break;

        default:
            break;
        }
    }
}

void closeFOXSAVE(
    FOXSAVE* save
)
{
    if (save->save != NULL)
    {
        switch (save->saveType)
        {
        case FOXSAVE_TYPE_FO1:
            closeFO1Save((FO1SAVE*)save->save);
            break;

        case FOXSAVE_TYPE_FO2:
            closeFO2Save((FO2SAVE*)save->save);
            break;

        case FOXSAVE_TYPE_FO3:
            closeFO3Save((FO3SAVE*)save->save);
            break;

        case FOXSAVE_TYPE_FONV:
            closeFONVSave((FONVSAVE*)save->save);
            break;

        case FOXSAVE_TYPE_FO4:
            closeFO4Save((FO4SAVE*)save->save);
            break;

        default:
            break;
        }
    }

    free(save);
}
