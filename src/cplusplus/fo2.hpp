/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
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

namespace cfallsavepp
{
    enum class CFALLSAVEPP_API FO2SaveProps
    {
        SaveSignature   = 0,
        SaveName        = 1,
        PlayerName      = 2
    };

    class CFALLSAVEPP_API FO2Save
    {

    private:

        FO2SAVE* save = nullptr;

    public:

        FO2SAVE* getFO2SAVE();
        void setFO2SAVE(FO2SAVE* save);



        FO2Save();
        FO2Save(FO2SAVE* save);
        FO2Save(string saveName);
        ~FO2Save();

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

    };
}

#endif // !CFALLSAVEPP_FO2_HPP
