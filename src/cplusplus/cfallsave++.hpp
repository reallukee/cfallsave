/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : cfallsave++.hpp
 *
 * Title       : CFALLSAVE++ API
 * Description : CFallSave++ API
 *               CFallSave++ library API interface!
 *               This is the easy gateway to using CFallSave++!
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.2.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_API_HPP
#define CFALLSAVEPP_API_HPP

#include "version.hpp"

#include "fo1.hpp"      // Fallout 1 API
#include "fo2.hpp"      // Fallout 2 API
#include "fotbos.hpp"   // Fallout Tactics: Brotherhood of Steel
#include "fo3.hpp"      // Fallout 3 API
#include "fonv.hpp"     // Fallout: New Vegas API
#include "fo4.hpp"      // Fallout 4 API

// #include "fox.hpp"      // Fallout X

#define CFALLSAVEPP_VERSION             220
#define CFALLSAVEPP_VERSION_MAJOR       2
#define CFALLSAVEPP_VERSION_MINOR       2
#define CFALLSAVEPP_VERSION_PATCH       0

#define CFALLSAVEPP_FRIENDLY_VERSION    "2.2.0"

/**
 * The minimum version represents the minimum interface
 * version required to use the existing code
 * without modifications.
 *
 * In other words...
 *
 * If the minimum version is 2.0.0, you can use any later
 * version of CFallSave++ within the same major branch
 * WITHOUT modifications!
 *
 * Crazy, right?
 */

#define CFALLSAVEPP_MIN_VERSION             200
#define CFALLSAVEPP_MIN_VERSION_MAJOR       2
#define CFALLSAVEPP_MIN_VERSION_MINOR       2
#define CFALLSAVEPP_MIN_VERSION_PATCH       0

#define CFALLSAVEPP_FRIENDLY_MIN_VERSION    "2.2.0"

#endif // !CFALLSAVEPP_API_HPP
