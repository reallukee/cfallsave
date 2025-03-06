/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo1.hpp
 *
 * Title       : FALLOUT 1 HEADER
 * Description : Fallout 1 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_FO1_HPP
#define CFALLSAVEPP_FO1_HPP

#include "header.hpp"

#include "../fo1.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVEPP_API FO1Save
    {

    private:

        FO1SAVE* save = nullptr;

    public:

        FO1Save();
        FO1Save(string saveName);
        ~FO1Save();

        void readSave(string saveName);
        bool isOpen();

        void printSave();

        string getSaveSignature();
        string getSaveName();

        string getPlayerName();

    };
}

#endif // !CFALLSAVEPP_FO1_HPP
