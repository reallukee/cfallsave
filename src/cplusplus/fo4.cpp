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

namespace cfallsavepp
{
    FO4SAVE* FO4Save::getFO4SAVE()
    {
        return this->save;
    }

    void FO4Save::setFO4SAVE(FO4SAVE* save)
    {
        if (save == nullptr)
        {
            return;
        }

        if (this->save != nullptr)
        {
            closeFO4Save(this->save);
        }

        this->save = save;
    }



    FO4Save::FO4Save()
    {
        return;
    }

    FO4Save::FO4Save(FO4SAVE* save)
    {
        this->save = save;
    }

    FO4Save::FO4Save(string saveName)
    {
        readSave(saveName);
    }

    FO4Save::~FO4Save()
    {
        closeFO4Save(this->save);
    }



    bool FO4Save::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFO4Save(c_saveName))
        {
            this->save = readFO4Save(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FO4Save::writeSave()
    {
        return writeFO4Save(this->save);
    }

    void FO4Save::closeSave()
    {
        return closeFO4Save(this->save);
    }

    bool FO4Save::isSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        return isFO4Save(c_saveName);
    }

    bool FO4Save::isOpen()
    {
        return isFO4SaveOpen(this->save);
    }



    void FO4Save::printSave()
    {
        printFO4Save(this->save);
    }

    void FO4Save::printSaveProps()
    {
        printFO4SaveProps(this->save);
    }

    void FO4Save::printSavePropAddresses()
    {
        printFO4SavePropAddresses(this->save);
    }

    void FO4Save::printSaveSnapshot()
    {
        printFO4SaveSnapshot(this->save);
    }



    string FO4Save::getGameName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return FO4SAVE_GAME_NAME;
    }

    string FO4Save::getSaveFileName()
    {
        if (this->save == nullptr || this->save->saveFileName == nullptr)
        {
            return "";
        }

        return save->saveFileName;
    }



    string FO4Save::getSaveSignature()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveSignature;
    }

    unsigned int FO4Save::getEngineVersion()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->engineVersion;
    }

    unsigned int FO4Save::getSaveNumber()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->saveNumber;
    }



    string FO4Save::getPlayerName()
    {
        if (this->save == nullptr || this->save->playerName == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }

    unsigned int FO4Save::getPlayerLevel()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->playerLevel;
    }

    string FO4Save::getPlayerLocation()
    {
        if (this->save == nullptr || this->save->playerLocation == nullptr)
        {
            return "";
        }

        return this->save->playerLocation;
    }

    string FO4Save::getPlayerPlaytime()
    {
        if (this->save == nullptr || this->save->playerPlaytime == nullptr)
        {
            return "";
        }

        return this->save->playerPlaytime;
    }

    string FO4Save::getPlayerRace()
    {
        if (this->save == nullptr || this->save->playerRace == nullptr)
        {
            return "";
        }

        return this->save->playerRace;
    }

    short unsigned int FO4Save::getPlayerSex()
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



    unsigned int FO4Save::getSnapshotWidth()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotWidth;
    }

    unsigned int FO4Save::getSnapshotHeight()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotHeight;
    }

    long unsigned int FO4Save::getSnapshotLength()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotLength;
    }

    unsigned char* FO4Save::getSnapshot()
    {
        if (this->save == nullptr || this->save->snapshot == nullptr)
        {
            return nullptr;
        }

        return this->save->snapshot;
    }
}
