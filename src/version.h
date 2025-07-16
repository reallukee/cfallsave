/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : version.h
 *
 * Title       : VERSION HEADER
 * Description : Version Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.1.0
 * License     : MIT
 */

#ifndef CFALLSAVE_VERSION_H
#define CFALLSAVE_VERSION_H

#include "header.h"

#include "cfallsave.h"

CFALLSAVE_API int cfs_getVersion();
CFALLSAVE_API int cfs_getVersionMajor();
CFALLSAVE_API int cfs_getVersionMinor();
CFALLSAVE_API int cfs_getVersionPatch();

CFALLSAVE_API const char* cfs_getFriendlyVersion();

CFALLSAVE_API int cfs_getMinVersion();
CFALLSAVE_API int cfs_getMinVersionMajor();
CFALLSAVE_API int cfs_getMinVersionMinor();
CFALLSAVE_API int cfs_getMinVersionPatch();

CFALLSAVE_API const char* cfs_getMinFriendlyVersion();

CFALLSAVE_API bool cfs_isCompatible(
    int major,
    int minor,
    int patch
);

#endif // !CFALLSAVE_VERSION_H
