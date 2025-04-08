/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
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

namespace cfallsavepp
{
    FO3SAVE* FO3Save::getFO3SAVE()
    {
        return this->save;
    }

    void FO3Save::setFO3SAVE(FO3SAVE* save)
    {
        if (save == nullptr)
        {
            return;
        }

        if (this->save != nullptr)
        {
            closeFO3Save(this->save);
        }

        this->save = save;
    }



    FO3Save::FO3Save()
    {
        return;
    }

    FO3Save::FO3Save(FO3SAVE* save)
    {
        this->save = save;
    }

    FO3Save::FO3Save(string saveName)
    {
        readSave(saveName);
    }

    FO3Save::~FO3Save()
    {
        closeFO3Save(this->save);
    }



    bool FO3Save::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFO3Save(c_saveName))
        {
            this->save = readFO3Save(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FO3Save::writeSave()
    {
        return writeFO3Save(this->save);
    }

    void FO3Save::closeSave()
    {
        return closeFO3Save(this->save);
    }

    bool FO3Save::isSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        return isFO3Save(c_saveName);
    }

    bool FO3Save::isOpen()
    {
        return isFO3SaveOpen(this->save);
    }



    void FO3Save::printSave()
    {
        printFO3Save(this->save);
    }

    void FO3Save::printSaveProps()
    {
        printFO3SaveProps(this->save);
    }

    void FO3Save::printSavePropAddresses()
    {
        printFO3SavePropAddresses(this->save);
    }

    void FO3Save::printSaveSnapshot()
    {
        printFO3SaveSnapshot(this->save);
    }



    string FO3Save::getGameName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return FO3SAVE_GAME_NAME;
    }

    string FO3Save::getSaveFileName()
    {
        if (this->save == nullptr || this->save->saveFileName == nullptr)
        {
            return "";
        }

        return save->saveFileName;
    }



    string FO3Save::getSaveSignature()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveSignature;
    }

    unsigned int FO3Save::getEngineVersion()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->engineVersion;
    }

    unsigned int FO3Save::getSaveNumber()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->saveNumber;
    }



    string FO3Save::getPlayerName()
    {
        if (this->save == nullptr || this->save->playerName == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }

    unsigned int FO3Save::getPlayerLevel()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->playerLevel;
    }

    string FO3Save::getPlayerTitle()
    {
        if (this->save == nullptr || this->save->playerTitle == nullptr)
        {
            return "";
        }

        return this->save->playerTitle;
    }

    string FO3Save::getPlayerLocation()
    {
        if (this->save == nullptr || this->save->playerLocation == nullptr)
        {
            return "";
        }

        return this->save->playerLocation;
    }

    string FO3Save::getPlayerPlaytime()
    {
        if (this->save == nullptr || this->save->playerPlaytime == nullptr)
        {
            return "";
        }

        return this->save->playerPlaytime;
    }



    unsigned int FO3Save::getSnapshotWidth()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotWidth;
    }

    unsigned int FO3Save::getSnapshotHeight()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotHeight;
    }

    long unsigned int FO3Save::getSnapshotLength()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotLength;
    }

    unsigned char* FO3Save::getSnapshot()
    {
        if (this->save == nullptr || this->save->snapshot == nullptr)
        {
            return nullptr;
        }

        return this->save->snapshot;
    }
}
