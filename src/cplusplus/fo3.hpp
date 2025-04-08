/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
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

namespace cfallsavepp
{
    enum class CFALLSAVEPP_API FO3SaveProps
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

    class CFALLSAVEPP_API FO3Save
    {

    private:

        FO3SAVE* save = nullptr;

    public:

        FO3SAVE* getFO3SAVE();
        void setFO3SAVE(FO3SAVE* save);



        FO3Save();
        FO3Save(FO3SAVE* save);
        FO3Save(string saveName);
        ~FO3Save();

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

#endif // !CFALLSAVEPP_FO3_HPP
