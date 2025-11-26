/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : cfallsave.h
 *
 * Title       : CFALLSAVE API
 * Description : CFallSave API
 *               CFallSave library API interface!
 *               This is the easy gateway to using CFallSave!
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.3.0
 * License     : MIT
 */

#ifndef CFALLSAVE_API_H
#define CFALLSAVE_API_H

#include "version.h"

#include "fo1.h"    // Fallout 1 API
#include "fo2.h"    // Fallout 2 API
#include "fotbos.h" // Fallout Tactics: Brotherhood of Steel
#include "fo3.h"    // Fallout 3 API
#include "fonv.h"   // Fallout: New Vegas API
#include "fo4.h"    // Fallout 4 API

// #include "fox.h"    // Fallout X

#define CFALLSAVE_VERSION           230
#define CFALLSAVE_VERSION_MAJOR     2
#define CFALLSAVE_VERSION_MINOR     3
#define CFALLSAVE_VERSION_PATCH     0

#define CFALLSAVE_FRIENDLY_VERSION  "2.3.0"

/**
 * The minimum version represents the minimum interface
 * version required to use the existing code
 * without modifications.
 *
 * In other words...
 *
 * If the minimum version is 2.0.0, you can use any later
 * version of CFallSave within the same major branch
 * WITHOUT modifications!
 *
 * Crazy, right?
 */

#define CFALLSAVE_MIN_VERSION           200
#define CFALLSAVE_MIN_VERSION_MAJOR     2
#define CFALLSAVE_MIN_VERSION_MINOR     2
#define CFALLSAVE_MIN_VERSION_PATCH     0

#define CFALLSAVE_FRIENDLY_MIN_VERSION  "2.2.0"

#endif  // !CFALLSAVE_API_H
