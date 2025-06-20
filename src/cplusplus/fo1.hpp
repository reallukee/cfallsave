/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fo1.hpp
 *
 * Title       : FALLOUT 1 HEADER
 * Description : Fallout 1 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_FO1_HPP
#define CFALLSAVEPP_FO1_HPP

#include "header.hpp"

#include "../fo1.h"

using namespace std;

namespace cfallsavepp
{
    enum class CFALLSAVEPP_API FO1SaveProps
    {
        SaveSignature   = 0,
        SaveName        = 1,
        PlayerName      = 2
    };

    class CFALLSAVEPP_API FO1Save
    {

    private:

        FO1SAVE* save = nullptr;

        string getFixedStringProp(FO1SAVE_PROPS prop);

        void setFixedStringProp(FO1SAVE_PROPS prop, string value);

    public:

        FO1Save();
        FO1Save(FO1SAVE* save);
        FO1Save(string saveName);
        ~FO1Save();



        bool read(string saveName);
        bool write();
        void close();
        static bool isSave(string saveName);
        bool isOpen();

        void print();
        void printProps();
        void printPropAddresses();

        static bool createSampleSave();



        FO1SAVE* getFO1SAVE();
        void setFO1SAVE(FO1SAVE* save);

        string getGameName();
        string getSaveFileName();

        string getSaveSignature();
        void setSaveSignature(string value);
        string getSaveName();
        void setSaveName(string value);

        string getPlayerName();
        void setPlayerName(string value);

    };
}

#endif // !CFALLSAVEPP_FO1_HPP
