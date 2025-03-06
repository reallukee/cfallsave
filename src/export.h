/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : export.h
 *
 * Title       : EXPORT
 * Description : Export
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVE_EXPORT_H
#define CFALLSAVE_EXPORT_H

#define CFALLSAVE_LIBRARY

#if defined(_WIN32) || defined(_WIN64)
    #ifdef CFALLSAVE_LIBRARY
        #define CFALLSAVE_API __declspec(dllexport)
    #else
        #define CFALLSAVE_API __declspec(dllimport)
    #endif // CFALLSAVE_LIBRARY
#else
    #define CFALLSAVE_API
#endif // _WIN32 || _WIN64

#endif // !CFALLSAVE_EXPORT_H
