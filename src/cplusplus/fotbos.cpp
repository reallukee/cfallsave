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

namespace cfallsavepp
{
    FOTBOSSAVE* FOTBOSSave::getFOTBOSSAVE()
    {
        return this->save;
    }

    void FOTBOSSave::setFOTBOSSAVE(FOTBOSSAVE* save)
    {
        if (save == nullptr)
        {
            return;
        }

        if (this->save != nullptr)
        {
            closeFOTBOSSave(this->save);
        }

        this->save = save;
    }



    FOTBOSSave::FOTBOSSave()
    {
        return;
    }

    FOTBOSSave::FOTBOSSave(FOTBOSSAVE* save)
    {
        this->save = save;
    }

    FOTBOSSave::FOTBOSSave(string saveName)
    {
        readSave(saveName);
    }

    FOTBOSSave::~FOTBOSSave()
    {
        closeFOTBOSSave(this->save);
    }



    bool FOTBOSSave::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFOTBOSSave(c_saveName))
        {
            this->save = readFOTBOSSave(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FOTBOSSave::writeSave()
    {
        return writeFOTBOSSave(this->save);
    }

    void FOTBOSSave::closeSave()
    {
        return closeFOTBOSSave(this->save);
    }

    bool FOTBOSSave::isSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        return isFOTBOSSave(c_saveName);
    }

    bool FOTBOSSave::isOpen()
    {
        return isFOTBOSSaveOpen(this->save);
    }



    void FOTBOSSave::printSave()
    {
        printFOTBOSSave(this->save);
    }

    void FOTBOSSave::printSaveProps()
    {
        printFOTBOSSaveProps(this->save);
    }

    void FOTBOSSave::printSavePropAddresses()
    {
        printFOTBOSSavePropAddresses(this->save);
    }



    string FOTBOSSave::getGameName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return FOTBOSSAVE_GAME_NAME;
    }

    string FOTBOSSave::getSaveFileName()
    {
        if (this->save == nullptr || this->save->saveFileName == nullptr)
        {
            return "";
        }

        return save->saveFileName;
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
        if (this->save == nullptr || this->save->saveName == nullptr)
        {
            return "";
        }

        return this->save->saveName;
    }



    string FOTBOSSave::getPlayerName()
    {
        if (this->save == nullptr || this->save->playerName == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }

    string FOTBOSSave::getPlayerLocation()
    {
        if (this->save == nullptr || this->save->playerLocation == nullptr)
        {
            return "";
        }

        return this->save->playerLocation;
    }

    string FOTBOSSave::getGameDateTime()
    {
        if (this->save == nullptr || this->save->gameDateTime == nullptr)
        {
            return "";
        }

        return this->save->gameDateTime;
    }
}
