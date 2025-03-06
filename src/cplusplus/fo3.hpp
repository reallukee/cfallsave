/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo3.hpp
 *
 * Title       : FALLOUT 3 HEADER
 * Description : Fallout 3 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_FO3_HPP
#define CFALLSAVEPP_FO3_HPP

#include "header.hpp"

#include "../fo3.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVEPP_API FO3Save
    {

    private:

        FO3SAVE* save = nullptr;

    public:

        FO3Save();
        FO3Save(string saveName);
        ~FO3Save();

        void readSave(string saveName);
        bool isOpen();

        void printSave();
        void printSaveSnapshot();

        string getSaveSignature();
        unsigned getEngineVersion();
        unsigned getSaveNumber();

        string getPlayerName();
        unsigned getPlayerLevel();
        string getPlayerTitle();
        string getPlayerLocation();
        string getPlayerPlaytime();

        unsigned getSnapshotWidth();
        unsigned getSnapshotHeight();
        unsigned char* getSnapshot();

    };
}

#endif // !CFALLSAVEPP_FO3_HPP
