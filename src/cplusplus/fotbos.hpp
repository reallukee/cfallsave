/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : fotbos.hpp
 *
 * Title       : FALLOUT TACTICS: BROTHERHOOD OF STEEL HEADER
 * Description : Fallout Tactics: Brotherhood of Steel Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_FOTBOS_HPP
#define CFALLSAVEPP_FOTBOS_HPP

#include "header.hpp"

#include "../fotbos.h"

using namespace std;

namespace cfallsavepp
{
    enum class CFALLSAVEPP_API FOTBOSSaveProps
    {
        SaveSignature   = 0,
        SaveName        = 1,
        PlayerName      = 2,
        PlayerLocation  = 3,
        GameDateTime    = 4
    };

    class CFALLSAVEPP_API FOTBOSSave
    {

    private:

        FOTBOSSAVE* save = nullptr;

        string getFixedStringProp(FOTBOSSAVE_PROPS prop);
        string getStringProp(FOTBOSSAVE_PROPS prop);

        void setFixedStringProp(FOTBOSSAVE_PROPS prop, string value);
        void setStringProp(FOTBOSSAVE_PROPS prop, string value);

    public:

        FOTBOSSave();
        FOTBOSSave(FOTBOSSAVE* save);
        FOTBOSSave(string saveName);
        ~FOTBOSSave();



        bool read(string saveName);
        bool write();
        void close();
        static bool isSave(string saveName);
        bool isOpen();

        void print();
        void printProps();
        void printPropAddresses();

        static bool createSampleSave();



        FOTBOSSAVE* getFOTBOSSAVE();
        void setFOTBOSSAVE(FOTBOSSAVE* save);

        string getGameName();
        string getSaveFileName();

        string getSaveSignature();
        void setSaveSignature(string value);
        string getSaveName();
        void setSaveName(string value);

        string getPlayerName();
        void setPlayerName(string value);
        string getPlayerLocation();
        void setPlayerLocation(string value);
        string getGameDateTime();
        void setGameDateTime(string value);

    };
}

#endif // !CFALLSAVEPP_FOTBOS_HPP
