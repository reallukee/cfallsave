/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : fox.c
 *
 * Title       : FALLOUT X SOURCE
 * Description : Fallout X Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fox.h"

FOXSAVE* readFOXSave(
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

    if (isFOTBOSSave(saveName))
    {
        save->save = readFOTBOSSave(saveName);
        save->saveType = FOXSAVE_TYPE_FOTBOS;

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

bool writeFOXSave(
    FOXSAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    switch (save->saveType)
    {
    case FOXSAVE_TYPE_FO1:
        return writeFO1Save((FO1SAVE*)save->save);

    case FOXSAVE_TYPE_FO2:
        return writeFO2Save((FO2SAVE*)save->save);

    case FOXSAVE_TYPE_FOTBOS:
        return writeFOTBOSSave((FOTBOSSAVE*)save->save);

    case FOXSAVE_TYPE_FO3:
        return writeFO3Save((FO3SAVE*)save->save);

    case FOXSAVE_TYPE_FONV:
        return writeFONVSave((FONVSAVE*)save->save);

    case FOXSAVE_TYPE_FO4:
        return writeFO4Save((FO4SAVE*)save->save);

    default:
        return false;
    }
}

bool isFOXSaveOpen(
    FOXSAVE* save
)
{
    if (save == NULL)
    {
        return false;
    }

    switch (save->saveType)
    {
    case FOXSAVE_TYPE_FO1:
        return isFO1SaveOpen((FO1SAVE*)save->save);

    case FOXSAVE_TYPE_FO2:
        return isFO2SaveOpen((FO2SAVE*)save->save);

    case FOXSAVE_TYPE_FOTBOS:
        return isFOTBOSSaveOpen((FOTBOSSAVE*)save->save);

    case FOXSAVE_TYPE_FO3:
        return isFO3SaveOpen((FO3SAVE*)save->save);

    case FOXSAVE_TYPE_FONV:
        return isFONVSaveOpen((FONVSAVE*)save->save);

    case FOXSAVE_TYPE_FO4:
        return isFO4SaveOpen((FO4SAVE*)save->save);

    default:
        return false;
    }
}

void closeFOXSave(
    FOXSAVE* save
)
{
    if (save->save == NULL)
    {
        return;
    }

    switch (save->saveType)
    {
    case FOXSAVE_TYPE_FO1:
        closeFO1Save((FO1SAVE*)save->save);
        break;

    case FOXSAVE_TYPE_FO2:
        closeFO2Save((FO2SAVE*)save->save);
        break;

    case FOXSAVE_TYPE_FOTBOS:
        closeFOTBOSSave((FOTBOSSAVE*)save->save);
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

    free(save);
}



bool printFOXSave(
    FOXSAVE* save
)
{
    if (save->save == NULL)
    {
        return false;
    }

    switch (save->saveType)
    {
    case FOXSAVE_TYPE_FO1:
        return printFO1Save((FO1SAVE*)save->save);

    case FOXSAVE_TYPE_FO2:
        return printFO2Save((FO2SAVE*)save->save);

    case FOXSAVE_TYPE_FOTBOS:
        return printFOTBOSSave((FOTBOSSAVE*)save->save);

    case FOXSAVE_TYPE_FO3:
        return printFO3Save((FO3SAVE*)save->save);

    case FOXSAVE_TYPE_FONV:
        return printFONVSave((FONVSAVE*)save->save);

    case FOXSAVE_TYPE_FO4:
        return printFO4Save((FO4SAVE*)save->save);

    default:
        return false;
    }
}

bool printFOXSaveProps(
    FOXSAVE* save
)
{
    if (save->save == NULL)
    {
        return false;
    }

    switch (save->saveType)
    {
    case FOXSAVE_TYPE_FO1:
        return printFO1SaveProps((FO1SAVE*)save->save);

    case FOXSAVE_TYPE_FO2:
        return printFO2SaveProps((FO2SAVE*)save->save);

    case FOXSAVE_TYPE_FOTBOS:
        return printFOTBOSSaveProps((FOTBOSSAVE*)save->save);

    case FOXSAVE_TYPE_FO3:
        return printFO3SaveProps((FO3SAVE*)save->save);

    case FOXSAVE_TYPE_FONV:
        return printFONVSaveProps((FONVSAVE*)save->save);

    case FOXSAVE_TYPE_FO4:
        return printFO4SaveProps((FO4SAVE*)save->save);

    default:
        return false;
    }
}

bool printFOXSavePropAddresses(
    FOXSAVE* save
)
{
    if (save->save == NULL)
    {
        return false;
    }

    switch (save->saveType)
    {
    case FOXSAVE_TYPE_FO1:
        return printFO1SavePropAddresses((FO1SAVE*)save->save);

    case FOXSAVE_TYPE_FO2:
        return printFO2SavePropAddresses((FO2SAVE*)save->save);

    case FOXSAVE_TYPE_FOTBOS:
        return printFOTBOSSavePropAddresses((FOTBOSSAVE*)save->save);

    case FOXSAVE_TYPE_FO3:
        return printFO3SavePropAddresses((FO3SAVE*)save->save);

    case FOXSAVE_TYPE_FONV:
        return printFONVSavePropAddresses((FONVSAVE*)save->save);

    case FOXSAVE_TYPE_FO4:
        return printFO4SavePropAddresses((FO4SAVE*)save->save);

    default:
        return false;
    }
}

bool printFOXSaveSnapshot(
    FOXSAVE* save
)
{
    if (save->save == NULL)
    {
        return false;
    }

    switch (save->saveType)
    {
    case FOXSAVE_TYPE_FO3:
        return printFO3SaveSnapshot((FO3SAVE*)save->save);

    case FOXSAVE_TYPE_FONV:
        return printFONVSaveSnapshot((FONVSAVE*)save->save);

    case FOXSAVE_TYPE_FO4:
        return printFO4SaveSnapshot((FO4SAVE*)save->save);

    default:
        return false;
    }
}
