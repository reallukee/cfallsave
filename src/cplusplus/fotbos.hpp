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

namespace cfallsavepp
{
    enum class CFALLSAVEPP_API FOTBOSSaveProps
    {
        SaveSignature   = 0,
        SaveName        = 1,
        PlayerName      = 2,
        PlayerLocation  = 3,
        GameDateTime    = 4
    };

    class CFALLSAVEPP_API FOTBOSSave
    {

    private:

        FOTBOSSAVE* save = nullptr;

    public:

        FOTBOSSAVE* getFOTBOSSAVE();
        void setFOTBOSSAVE(FOTBOSSAVE* save);



        FOTBOSSave();
        FOTBOSSave(FOTBOSSAVE* save);
        FOTBOSSave(string saveName);
        ~FOTBOSSave();

        bool readSave(string saveName);
        bool writeSave();
        void closeSave();
        static bool isSave(string saveName);
        bool isOpen();

        void printSave();
        void printSaveProps();
        void printSavePropAddresses();



        string getGameName();
        string getSaveFileName();

        string getSaveSignature();
        string getSaveName();

        string getPlayerName();
        string getPlayerLocation();
        string getGameDateTime();

    };
}

#endif // !CFALLSAVEPP_FOTBOS_HPP
