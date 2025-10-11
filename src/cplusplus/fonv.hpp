/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fonv.hpp
 *
 * Title       : FALLOUT: NEW VEGAS HEADER
 * Description : Fallout: New Vegas Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.2.0
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

        string getFixedStringProp(FONVSAVE_PROPS prop);
        unsigned int getUIntProp(FONVSAVE_PROPS prop);
        string getStringProp(FONVSAVE_PROPS prop);
        unsigned char* getUByteArrayProp(FONVSAVE_PROPS prop);

        void setFixedStringProp(FONVSAVE_PROPS prop, string value);
        void setUIntProp(FONVSAVE_PROPS prop, unsigned int value);
        void setStringProp(FONVSAVE_PROPS prop, string value);
        void setUByteArrayProp(FONVSAVE_PROPS prop, unsigned char* value);

    public:

        FONVSave();
        FONVSave(FONVSAVE* save);
        FONVSave(string saveName);
        ~FONVSave();



        bool read(string saveName);
        bool write();
        void close();
        static bool isSave(string saveName);
        bool isOpen();

        void print();
        void printProps();
        void printPropAddresses();
        void printSnapshot();



        FONVSAVE* getFONVSAVE();
        void setFONVSAVE(FONVSAVE* save);

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

#endif // !CFALLSAVEPP_FONV_HPP
