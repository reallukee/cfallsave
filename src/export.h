/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
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
        #ifdef __cplusplus
            #define CFALLSAVE_API extern "C" __declspec(dllexport)
        #else
            #define CFALLSAVE_API __declspec(dllexport)
        #endif // __cplusplus
    #else
        #ifdef __cplusplus
            #define CFALLSAVE_API extern "C" __declspec(dllimport)
        #else
            #define CFALLSAVE_API __declspec(dllimport)
        #endif // __cplusplus
    #endif // CFALLSAVE_LIBRARY
#else
    #ifdef __cplusplus
        #define CFALLSAVE_API extern "C"
    #else
        #define CFALLSAVE_API
    #endif // __cplusplus
#endif // _WIN32 || _WIN64

#endif // !CFALLSAVE_EXPORT_H
