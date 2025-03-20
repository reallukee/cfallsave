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

namespace cfallsavepp
{
    enum class CFALLSAVEPP_API FONVSaveProps
    {
        SaveSignature   = 0,
        EngineVersion   = 1,
        SaveNumber      = 2,
        PlayerName      = 3,
        PlayerLevel     = 4,
        PlayerTitle     = 5,
        PlayerLocation  = 6,
        PlayerPlaytime  = 7,
        SnapshotWidth   = 8,
        SnapshotHeight  = 9,
        Snapshot        = 10
    };

    class CFALLSAVEPP_API FONVSave
    {

    private:

        FONVSAVE* save = nullptr;

    public:

        FONVSAVE* getFONVSAVE();
        void setFONVSAVE(FONVSAVE* save);



        FONVSave();
        FONVSave(FONVSAVE* save);
        FONVSave(string saveName);
        ~FONVSave();

        bool readSave(string saveName);
        bool writeSave();
        void closeSave();
        static bool isSave(string saveName);
        bool isOpen();

        void printSave();
        void printSaveProps();
        void printSavePropAddresses();
        void printSaveSnapshot();



        string getGameName();
        string getSaveFileName();

        string getSaveSignature();
        unsigned int getEngineVersion();
        unsigned int getSaveNumber();

        string getPlayerName();
        unsigned int getPlayerLevel();
        string getPlayerTitle();
        string getPlayerLocation();
        string getPlayerPlaytime();

        unsigned int getSnapshotWidth();
        unsigned int getSnapshotHeight();
        long unsigned int getSnapshotLength();
        unsigned char* getSnapshot();

    };
}

#endif // !CFALLSAVEPP_FONV_HPP
