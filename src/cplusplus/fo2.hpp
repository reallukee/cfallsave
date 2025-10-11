/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fo2.hpp
 *
 * Title       : FALLOUT 2 HEADER
 * Description : Fallout 2 Header
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.2.0
 * License     : MIT
 */

#ifndef CFALLSAVEPP_FO2_HPP
#define CFALLSAVEPP_FO2_HPP

#include "header.hpp"

#include "../fo2.h"

using namespace std;

namespace cfallsavepp
{
    enum class CFALLSAVEPP_API FO2SaveProps
    {
        SaveSignature   = 0,
        SaveName        = 1,
        PlayerName      = 2
    };

    class CFALLSAVEPP_API FO2Save
    {

    private:

        FO2SAVE* save = nullptr;

        string getFixedStringProp(FO2SAVE_PROPS prop);

        void setFixedStringProp(FO2SAVE_PROPS prop, string value);

    public:

        FO2Save();
        FO2Save(FO2SAVE* save);
        FO2Save(string saveName);
        ~FO2Save();



        bool read(string saveName);
        bool write();
        void close();
        static bool isSave(string saveName);
        bool isOpen();

        void print();
        void printProps();
        void printPropAddresses();



        FO2SAVE* getFO2SAVE();
        void setFO2SAVE(FO2SAVE* save);

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

#endif // !CFALLSAVEPP_FO2_HPP
