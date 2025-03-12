/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
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

namespace cfallsave
{
    FONVSave::FONVSave()
    {
        return;
    }

    FONVSave::FONVSave(string saveName)
    {
        readSave(saveName);
    }

    FONVSave::~FONVSave()
    {
        closeFONVSave(this->save);
    }



    void FONVSave::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        this->save = readFONVSave(c_saveName);

        if (this->save == nullptr)
        {
            return;
        }
    }

    bool FONVSave::isOpen()
    {
        return this->save != nullptr;
    }



    void FONVSave::printSave()
    {
        printFONVSave(this->save);
    }

    void FONVSave::printSaveSnapshot()
    {
        printFONVSaveSnapshot(this->save);
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
        if (this->save == nullptr)
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
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerTitle;
    }

    string FONVSave::getPlayerLocation()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerLocation;
    }

    string FONVSave::getPlayerPlaytime()
    {
        if (this->save == nullptr)
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

    unsigned char* FONVSave::getSnapshot()
    {
        if (this->save == nullptr)
        {
            return nullptr;
        }

        return this->save->snapshot;
    }
}
