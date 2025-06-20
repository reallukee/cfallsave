/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
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

        string getFixedStringProp(FO3SAVE_PROPS prop);
        unsigned int getUIntProp(FO3SAVE_PROPS prop);
        string getStringProp(FO3SAVE_PROPS prop);
        unsigned char* getUByteArrayProp(FO3SAVE_PROPS prop);

        void setFixedStringProp(FO3SAVE_PROPS prop, string value);
        void setUIntProp(FO3SAVE_PROPS prop, unsigned int value);
        void setStringProp(FO3SAVE_PROPS prop, string value);
        void setUByteArrayProp(FO3SAVE_PROPS prop, unsigned char* value);

    public:

        FO3Save();
        FO3Save(FO3SAVE* save);
        FO3Save(string saveName);
        ~FO3Save();



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



        FO3SAVE* getFO3SAVE();
        void setFO3SAVE(FO3SAVE* save);

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
        string getPlayerTitle();
        void setPlayerTitle(string value);
        string getPlayerLocation();
        void setPlayerLocation(string value);
        string getPlayerPlaytime();
        void setPlayerPlaytime(string value);

        unsigned int getSnapshotWidth();
        void setSnapshotWidth(unsigned int value);
        unsigned int getSnapshotHeight();
        void setSnapshotHeight(unsigned int value);
        long unsigned int getSnapshotLength();
        unsigned char* getSnapshot();
        void setSnapshot(unsigned char* value);

    };
}

#endif // !CFALLSAVEPP_FO3_HPP
