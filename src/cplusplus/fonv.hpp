/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fonv.hpp
 *
 * Title       : FALLOUT: NEW VEGAS HEADER
 * Description : Fallout: New Vegas Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_FONV_HPP
#define CFALLSAVEPP_FONV_HPP

#include "header.hpp"

#include "../fonv.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVEPP_API FONVSave
    {

    private:

        FONVSAVE* save = nullptr;

    public:

        FONVSave();
        FONVSave(string saveName);
        ~FONVSave();

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

#endif // !CFALLSAVEPP_FONV_HPP
