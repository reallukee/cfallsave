/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo4.hpp
 *
 * Title       : FALLOUT 4 HEADER
 * Description : Fallout 4 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_FO4_HPP
#define CFALLSAVEPP_FO4_HPP

#include "header.hpp"

#include "../fo4.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVEPP_API FO4Save
    {

    private:

        FO4SAVE* save = nullptr;

    public:

        FO4Save();
        FO4Save(string saveName);
        ~FO4Save();

        void readSave(string saveName);
        bool isOpen();

        void printSave();
        void printSaveSnapshot();

        string getSaveSignature();
        unsigned getEngineVersion();
        unsigned getSaveNumber();

        string getPlayerName();
        unsigned getPlayerLevel();
        string getPlayerLocation();
        string getPlayerPlaytime();
        string getPlayerRace();
        unsigned short getPlayerSex();
        float getPlayerCurrentXp();
        float getPlayerRequiredXp();

        unsigned getSnapshotWidth();
        unsigned getSnapshotHeight();
        unsigned char* getSnapshot();

    };
}

#endif // !CFALLSAVEPP_FO4_HPP
