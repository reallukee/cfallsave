/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fotbos.hpp
 *
 * Title       : FALLOUT TACTICS: BROTHERHOOD OF STEEL HEADER
 * Description : Fallout Tactics: Brotherhood of Steel Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_FOTBOS_HPP
#define CFALLSAVEPP_FOTBOS_HPP

#include "header.hpp"

#include "../fotbos.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVEPP_API FOTBOSSave
    {

    private:

        FOTBOSSAVE* save = nullptr;

    public:

        FOTBOSSave();
        FOTBOSSave(string saveName);
        ~FOTBOSSave();

        void readSave(string saveName);
        bool isOpen();

        void printSave();

        string getSaveSignature();
        string getSaveName();

        string getPlayerName();
        string getPlayerLocation();
        string getGameDateTime();

    };
}

#endif // !CFALLSAVEPP_FOTBOS_HPP
