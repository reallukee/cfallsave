/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : fonv.cpp
 *
 * Title       : FALLOUT: NEW VEGAS SOURCE
 * Description : Fallout: New Vegas Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fonv.hpp"

namespace cfallsavepp
{
    FONVSAVE* FONVSave::getFONVSAVE()
    {
        return this->save;
    }

    void FONVSave::setFONVSAVE(FONVSAVE* save)
    {
        if (save == nullptr)
        {
            return;
        }

        if (this->save != nullptr)
        {
            closeFONVSave(this->save);
        }

        this->save = save;
    }



    FONVSave::FONVSave()
    {
        return;
    }

    FONVSave::FONVSave(FONVSAVE* save)
    {
        this->save = save;
    }

    FONVSave::FONVSave(string saveName)
    {
        readSave(saveName);
    }

    FONVSave::~FONVSave()
    {
        closeFONVSave(this->save);
    }



    bool FONVSave::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFONVSave(c_saveName))
        {
            this->save = readFONVSave(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FONVSave::writeSave()
    {
        return writeFONVSave(this->save);
    }

    void FONVSave::closeSave()
    {
        return closeFONVSave(this->save);
    }

    bool FONVSave::isSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        return isFONVSave(c_saveName);
    }

    bool FONVSave::isOpen()
    {
        return isFONVSaveOpen(this->save);
    }



    void FONVSave::printSave()
    {
        printFONVSave(this->save);
    }

    void FONVSave::printSaveProps()
    {
        printFONVSaveProps(this->save);
    }

    void FONVSave::printSavePropAddresses()
    {
        printFONVSavePropAddresses(this->save);
    }

    void FONVSave::printSaveSnapshot()
    {
        printFONVSaveSnapshot(this->save);
    }



    string FONVSave::getGameName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return FONVSAVE_GAME_NAME;
    }

    string FONVSave::getSaveFileName()
    {
        if (this->save == nullptr || this->save->saveFileName == nullptr)
        {
            return "";
        }

        return save->saveFileName;
    }



    string FONVSave::getSaveSignature()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveSignature;
    }

    unsigned int FONVSave::getEngineVersion()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->engineVersion;
    }

    unsigned int FONVSave::getSaveNumber()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->saveNumber;
    }



    string FONVSave::getPlayerName()
    {
        if (this->save == nullptr || this->save->playerName == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }

    unsigned int FONVSave::getPlayerLevel()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->playerLevel;
    }

    string FONVSave::getPlayerTitle()
    {
        if (this->save == nullptr || this->save->playerTitle == nullptr)
        {
            return "";
        }

        return this->save->playerTitle;
    }

    string FONVSave::getPlayerLocation()
    {
        if (this->save == nullptr || this->save->playerLocation == nullptr)
        {
            return "";
        }

        return this->save->playerLocation;
    }

    string FONVSave::getPlayerPlaytime()
    {
        if (this->save == nullptr || this->save->playerPlaytime == nullptr)
        {
            return "";
        }

        return this->save->playerPlaytime;
    }



    unsigned int FONVSave::getSnapshotWidth()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotWidth;
    }

    unsigned int FONVSave::getSnapshotHeight()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotHeight;
    }

    long unsigned int FONVSave::getSnapshotLength()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotLength;
    }

    unsigned char* FONVSave::getSnapshot()
    {
        if (this->save == nullptr || this->save->snapshot == nullptr)
        {
            return nullptr;
        }

        return this->save->snapshot;
    }
}
