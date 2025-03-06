/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fotbos.cpp
 *
 * Title       : FALLOUT TACTICS: BROTHERHOOD OF STEEL SOURCE
 * Description : Fallout Tactics: Brotherhood of Steel Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fotbos.hpp"

namespace cfallsave
{
    FOTBOSSave::FOTBOSSave()
    {
        return;
    }

    FOTBOSSave::FOTBOSSave(string saveName)
    {
        readSave(saveName);
    }

    FOTBOSSave::~FOTBOSSave()
    {
        closeFOTBOSSave(this->save);
    }



    void FOTBOSSave::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        this->save = readFOTBOSSave(c_saveName);

        if (this->save == nullptr)
        {
            return;
        }
    }

    bool FOTBOSSave::isOpen()
    {
        return this->save != nullptr;
    }



    void FOTBOSSave::printSave()
    {
        printFOTBOSSave(this->save);
    }



    string FOTBOSSave::getSaveSignature()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveSignature;
    }

    string FOTBOSSave::getSaveName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveName;
    }



    string FOTBOSSave::getPlayerName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }

    string FOTBOSSave::getPlayerLocation()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerLocation;
    }

    string FOTBOSSave::getGameDateTime()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->gameDateTime;
    }
}
