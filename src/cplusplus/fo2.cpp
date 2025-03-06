/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo2.cpp
 *
 * Title       : FALLOUT 2 SOURCE
 * Description : Fallout 2 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo2.hpp"

namespace cfallsave
{
    FO2Save::FO2Save()
    {
        return;
    }

    FO2Save::FO2Save(string saveName)
    {
        readSave(saveName);
    }

    FO2Save::~FO2Save()
    {
        closeFO2Save(this->save);
    }



    void FO2Save::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        this->save = readFO2Save(c_saveName);

        if (this->save == nullptr)
        {
            return;
        }
    }

    bool FO2Save::isOpen()
    {
        return this->save != nullptr;
    }



    void FO2Save::printSave()
    {
        printFO2Save(this->save);
    }



    string FO2Save::getSaveSignature()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveSignature;
    }

    string FO2Save::getSaveName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveName;
    }



    string FO2Save::getPlayerName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }
}
