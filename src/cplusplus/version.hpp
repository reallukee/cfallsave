/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : version.hpp
 *
 * Title       : VERSION++ HEADER
 * Description : Version++ Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.1.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_VERSION_HPP
#define CFALLSAVEPP_VERSION_HPP

#include "header.hpp"

#include "cfallsave++.hpp"

namespace cfallsavepp
{
    CFALLSAVEPP_API int cfspp_getVersion();
    CFALLSAVEPP_API int cfspp_getVersionMajor();
    CFALLSAVEPP_API int cfspp_getVersionMinor();
    CFALLSAVEPP_API int cfspp_getVersionPatch();

    CFALLSAVEPP_API const char* cfspp_getFriendlyVersion();

    CFALLSAVEPP_API int cfspp_getMinVersion();
    CFALLSAVEPP_API int cfspp_getMinVersionMajor();
    CFALLSAVEPP_API int cfspp_getMinVersionMinor();
    CFALLSAVEPP_API int cfspp_getMinVersionPatch();

    CFALLSAVEPP_API const char* cfspp_getMinFriendlyVersion();

    CFALLSAVEPP_API bool cfspp_isCompatible(
        int major,
        int minor,
        int patch
    );
}

#endif // !CFALLSAVEPP_VERSION_HPP
