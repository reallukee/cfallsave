/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * Author  : Reallukee
 * Version : 1.0
 * License : MIT
 */

#ifndef CFALLSAVE_EXPORT_HPP
#define CFALLSAVE_EXPORT_HPP

#define CFALLSAVE_CPP_LIBRARY

#if defined(_WIN32) || defined(_WIN64)
    #ifdef CFALLSAVE_CPP_LIBRARY
        #define CFALLSAVE_CPP_API __declspec(dllexport)
    #else
        #define CFALLSAVE_CPP_API __declspec(dllimport)
    #endif // CFALLSAVE_CPP_API
#else
    #define CFALLSAVE_CPP_API
#endif // _WIN32 || _WIN64

#endif // !CFALLSAVE_EXPORT_HPP
