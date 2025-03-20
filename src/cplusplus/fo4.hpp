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

namespace cfallsavepp
{
    enum class CFALLSAVEPP_API FO4SaveProps
    {
        SaveSignature       = 0,
        EngineVersion       = 1,
        SaveNumber          = 2,
        PlayerName          = 3,
        PlayerLevel         = 4,
        PlayerLocation      = 5,
        PlayerPlaytime      = 6,
        PlayerRace          = 7,
        PlayerSex           = 8,
        PlayerCurrentXP     = 9,
        PlayerRequiredXP    = 10,
        SnapshotWidth       = 11,
        SnapshotHeight      = 12,
        Snapshot            = 13
    };

    class CFALLSAVEPP_API FO4Save
    {

    private:

        FO4SAVE* save = nullptr;

    public:

        FO4SAVE* getFO4SAVE();
        void setFO4SAVE(FO4SAVE* save);



        FO4Save();
        FO4Save(FO4SAVE* save);
        FO4Save(string saveName);
        ~FO4Save();

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
        string getPlayerLocation();
        string getPlayerPlaytime();
        string getPlayerRace();
        short unsigned int getPlayerSex();
        float getPlayerCurrentXp();
        float getPlayerRequiredXp();

        unsigned int getSnapshotWidth();
        unsigned int getSnapshotHeight();
        long unsigned int getSnapshotLength();
        unsigned char* getSnapshot();

    };
}

#endif // !CFALLSAVEPP_FO4_HPP
