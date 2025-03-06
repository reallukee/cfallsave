/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo1.cpp
 *
 * Title       : FALLOUT 1 SOURCE
 * Description : Fallout 1 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo1.hpp"

namespace cfallsave
{
    FO1Save::FO1Save()
    {
        return;
    }

    FO1Save::FO1Save(string saveName)
    {
        readSave(saveName);
    }

    FO1Save::~FO1Save()
    {
        closeFO1Save(this->save);
    }



    void FO1Save::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        this->save = readFO1Save(c_saveName);

        if (this->save == nullptr)
        {
            return;
        }
    }

    bool FO1Save::isOpen()
    {
        return this->save != nullptr;
    }



    void FO1Save::printSave()
    {
        printFO1Save(this->save);
    }



    string FO1Save::getSaveSignature()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveSignature;
    }

    string FO1Save::getSaveName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveName;
    }



    string FO1Save::getPlayerName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }
}
