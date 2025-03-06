/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo4.cpp
 *
 * Title       : FALLOUT 4 SOURCE
 * Description : Fallout 4 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo4.hpp"

namespace cfallsave
{
    FO4Save::FO4Save()
    {
        return;
    }

    FO4Save::FO4Save(string saveName)
    {
        readSave(saveName);
    }

    FO4Save::~FO4Save()
    {
        closeFO4Save(this->save);
    }



    void FO4Save::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        this->save = readFO4Save(c_saveName);

        if (this->save == nullptr)
        {
            return;
        }
    }

    bool FO4Save::isOpen()
    {
        return this->save != nullptr;
    }



    void FO4Save::printSave()
    {
        printFO4Save(this->save);
    }

    void FO4Save::printSaveSnapshot()
    {
        printFO4SaveSnapshot(this->save);
    }



    string FO4Save::getSaveSignature()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveSignature;
    }

    unsigned FO4Save::getEngineVersion()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->engineVersion;
    }

    unsigned FO4Save::getSaveNumber()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->saveNumber;
    }



    string FO4Save::getPlayerName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }

    unsigned FO4Save::getPlayerLevel()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->playerLevel;
    }

    string FO4Save::getPlayerLocation()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerLocation;
    }

    string FO4Save::getPlayerPlaytime()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerPlaytime;
    }

    string FO4Save::getPlayerRace()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerRace;
    }

    unsigned short FO4Save::getPlayerSex()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->playerSex;
    }

    float FO4Save::getPlayerCurrentXp()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->playerCurrentXp;
    }

    float FO4Save::getPlayerRequiredXp()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->playerRequiredXp;
    }



    unsigned FO4Save::getSnapshotWidth()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotWidth;
    }

    unsigned FO4Save::getSnapshotHeight()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotHeight;
    }

    unsigned char* FO4Save::getSnapshot()
    {
        if (this->save == nullptr)
        {
            return nullptr;
        }

        return this->save->snapshot;
    }
}
