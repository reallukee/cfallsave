/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : export.hpp
 *
 * Title       : EXPORT++
 * Description : Export++
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_EXPORT_HPP
#define CFALLSAVEPP_EXPORT_HPP

#define CFALLSAVEPP_LIBRARY

// #ifdef CFALLSAVE_LIBRARY
//     #undef CFALLSAVE_LIBRARY
// #endif // CFALLSAVE_LIBRARY

// #ifdef CFALLSAVE_API
//     #undef CFALLSAVE_API
// #endif // CFALLSAVE_API

#if defined(_WIN32) || defined(_WIN64)
    #ifdef CFALLSAVEPP_LIBRARY
        #define CFALLSAVEPP_API __declspec(dllexport)
    #else
        #define CFALLSAVEPP_API __declspec(dllimport)
    #endif // CFALLSAVEPP_LIBRARY
#else
    #define CFALLSAVEPP_API
#endif // _WIN32 || _WIN64

#endif // !CFALLSAVEPP_EXPORT_HPP
