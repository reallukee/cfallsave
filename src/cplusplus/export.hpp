/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : export.hpp
 *
 * Title       : EXPORT++
 * Description : Export++
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.1.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_EXPORT_HPP
#define CFALLSAVEPP_EXPORT_HPP

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
