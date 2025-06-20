/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
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

        string getFixedStringProp(FO4SAVE_PROPS prop);
        unsigned int getUIntProp(FO4SAVE_PROPS prop);
        string getStringProp(FO4SAVE_PROPS prop);
        short unsigned int getUShortProp(FO4SAVE_PROPS prop);
        float getFloatProp(FO4SAVE_PROPS prop);
        unsigned char* getUByteArrayProp(FO4SAVE_PROPS prop);

        void setFixedStringProp(FO4SAVE_PROPS prop, string value);
        void setUIntProp(FO4SAVE_PROPS prop, unsigned int value);
        void setStringProp(FO4SAVE_PROPS prop, string value);
        void setUShortProp(FO4SAVE_PROPS prop, short unsigned int value);
        void setFloatProp(FO4SAVE_PROPS prop, float value);
        void setUByteArrayProp(FO4SAVE_PROPS prop, unsigned char* value);

    public:

        FO4Save();
        FO4Save(FO4SAVE* save);
        FO4Save(string saveName);
        ~FO4Save();



        bool read(string saveName);
        bool write();
        void close();
        static bool isSave(string saveName);
        bool isOpen();

        void print();
        void printProps();
        void printPropAddresses();
        void printSnapshot();

        static bool createSampleSave();



        FO4SAVE* getFO4SAVE();
        void setFO4SAVE(FO4SAVE* save);

        string getGameName();
        string getSaveFileName();

        string getSaveSignature();
        void setSaveSignature(string value);
        unsigned int getEngineVersion();
        void setEngineVersion(unsigned int value);
        unsigned int getSaveNumber();
        void setSaveNumber(unsigned int value);

        string getPlayerName();
        void setPlayerName(string value);
        unsigned int getPlayerLevel();
        void setPlayerLevel(unsigned int value);
        string getPlayerLocation();
        void setPlayerLocation(string value);
        string getPlayerPlaytime();
        void setPlayerPlaytime(string value);
        string getPlayerRace();
        void setPlayerRace(string value);
        short unsigned int getPlayerSex();
        void setPlayerSex(short unsigned int value);
        float getPlayerCurrentXp();
        void setPlayerCurrentXp(float value);
        float getPlayerRequiredXp();
        void setPlayerRequiredXp(float value);

        unsigned int getSnapshotWidth();
        void setSnapshotWidth(unsigned int value);
        unsigned int getSnapshotHeight();
        void setSnapshotHeight(unsigned int value);
        long unsigned int getSnapshotLength();
        unsigned char* getSnapshot();
        void setSnapshot(unsigned char* value);

    };
}

#endif // !CFALLSAVEPP_FO4_HPP
