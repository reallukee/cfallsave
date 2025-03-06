/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo2.hpp
 *
 * Title       : FALLOUT 2 HEADER
 * Description : Fallout 2 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_FO2_HPP
#define CFALLSAVEPP_FO2_HPP

#include "header.hpp"

#include "../fo2.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVEPP_API FO2Save
    {

    private:

        FO2SAVE* save = nullptr;

    public:

        FO2Save();
        FO2Save(string saveName);
        ~FO2Save();

        void readSave(string saveName);
        bool isOpen();

        void printSave();

        string getSaveSignature();
        string getSaveName();

        string getPlayerName();

    };
}

#endif // !CFALLSAVEPP_FO2_HPP
