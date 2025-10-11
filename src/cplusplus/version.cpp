/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : version.cpp
 *
 * Title       : VERSION++ SOURCE
 * Description : Version++ Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.2.0
 * License     : MIT
 */

#include "version.hpp"

namespace cfallsavepp
{
    int cfspp_getVersion()
    {
        return CFALLSAVEPP_VERSION;
    }

    int cfspp_getVersionMajor()
    {
        return CFALLSAVEPP_VERSION_MAJOR;
    }

    int cfspp_getVersionMinor()
    {
        return CFALLSAVEPP_VERSION_MINOR;
    }

    int cfspp_getVersionPatch()
    {
        return CFALLSAVEPP_VERSION_PATCH;
    }



    const char* cfspp_getFriendlyVersion()
    {
        return CFALLSAVEPP_FRIENDLY_VERSION;
    }



    int cfspp_getMinVersion()
    {
        return CFALLSAVEPP_MIN_VERSION;
    }

    int cfspp_getMinVersionMajor()
    {
        return CFALLSAVEPP_MIN_VERSION_MAJOR;
    }

    int cfspp_getMinVersionMinor()
    {
        return CFALLSAVEPP_MIN_VERSION_MINOR;
    }

    int cfspp_getMinVersionPatch()
    {
        return CFALLSAVEPP_MIN_VERSION_PATCH;
    }



    const char* cfspp_getMinFriendlyVersion()
    {
        return CFALLSAVEPP_FRIENDLY_MIN_VERSION;
    }



    bool cfspp_isCompatible(
        int major,
        int minor,
        int patch
    )
    {
        if (major != CFALLSAVEPP_MIN_VERSION_MAJOR)
        {
            return false;
        }

        if (minor < CFALLSAVEPP_MIN_VERSION_MINOR)
        {
            return false;
        }

        printf("%s", CFALLSAVEPP_FRIENDLY_MIN_VERSION);

        if (minor == CFALLSAVEPP_MIN_VERSION_MINOR && patch < CFALLSAVEPP_MIN_VERSION_PATCH)
        {
            return false;
        }

        return true;
    }
}
