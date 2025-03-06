/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo3.cpp
 *
 * Title       : FALLOUT 3 SOURCE
 * Description : Fallout 3 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo3.hpp"

namespace cfallsave
{
    FO3Save::FO3Save()
    {
        return;
    }

    FO3Save::FO3Save(string saveName)
    {
        readSave(saveName);
    }

    FO3Save::~FO3Save()
    {
        closeFO3Save(this->save);
    }



    void FO3Save::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        this->save = readFO3Save(c_saveName);

        if (this->save == nullptr)
        {
            return;
        }
    }

    bool FO3Save::isOpen()
    {
        return this->save != nullptr;
    }



    void FO3Save::printSave()
    {
        printFO3Save(this->save);
    }

    void FO3Save::printSaveSnapshot()
    {
        printFO3SaveSnapshot(this->save);
    }



    string FO3Save::getSaveSignature()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveSignature;
    }

    unsigned FO3Save::getEngineVersion()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->engineVersion;
    }

    unsigned FO3Save::getSaveNumber()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->saveNumber;
    }



    string FO3Save::getPlayerName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }

    unsigned FO3Save::getPlayerLevel()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->playerLevel;
    }

    string FO3Save::getPlayerTitle()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerTitle;
    }

    string FO3Save::getPlayerLocation()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerLocation;
    }

    string FO3Save::getPlayerPlaytime()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerPlaytime;
    }



    unsigned FO3Save::getSnapshotWidth()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotWidth;
    }

    unsigned FO3Save::getSnapshotHeight()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotHeight;
    }

    unsigned char* FO3Save::getSnapshot()
    {
        if (this->save == nullptr)
        {
            return nullptr;
        }

        return this->save->snapshot;
    }
}
