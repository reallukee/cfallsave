/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : version.c
 *
 * Title       : VERSION SOURCE
 * Description : Version Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.1.0
 * License     : MIT
 */

#include "version.h"

int cfs_getVersion()
{
    return CFALLSAVE_VERSION;
}

int cfs_getVersionMajor()
{
    return CFALLSAVE_VERSION_MAJOR;
}

int cfs_getVersionMinor()
{
    return CFALLSAVE_VERSION_MINOR;
}

int cfs_getVersionPatch()
{
    return CFALLSAVE_VERSION_PATCH;
}



const char* cfs_getFriendlyVersion()
{
    return CFALLSAVE_FRIENDLY_VERSION;
}



int cfs_getMinVersion()
{
    return CFALLSAVE_MIN_VERSION;
}

int cfs_getMinVersionMajor()
{
    return CFALLSAVE_MIN_VERSION_MAJOR;
}

int cfs_getMinVersionMinor()
{
    return CFALLSAVE_MIN_VERSION_MINOR;
}

int cfs_getMinVersionPatch()
{
    return CFALLSAVE_MIN_VERSION_PATCH;
}



const char* cfs_getMinFriendlyVersion()
{
    return CFALLSAVE_FRIENDLY_MIN_VERSION;
}



bool cfs_isCompatible(
    int major,
    int minor,
    int patch
)
{
    if (major != CFALLSAVE_MIN_VERSION_MAJOR)
    {
        return false;
    }

    if (minor < CFALLSAVE_MIN_VERSION_MINOR)
    {
        return false;
    }

    printf("%s", CFALLSAVE_MIN_VERSION_S);

    if (minor == CFALLSAVE_MIN_VERSION_MINOR && patch < CFALLSAVE_MIN_VERSION_PATCH)
    {
        return false;
    }

    return true;
}
