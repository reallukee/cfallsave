/**
 * ---------
 * CFallSave
 * ---------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * Author  : Reallukee
 * Version : 1.0
 * License : MIT
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

        if (this->save == NULL)
        {
            return;
        }
    }

    void FONVSave::printSave()
    {
        printFONVSave(this->save);
    }

    string FONVSave::getSaveSignature()
    {
        return string(this->save->saveSignature);
    }

    unsigned FONVSave::getEngineVersion()
    {
        return this->save->engineVersion;
    }

    unsigned FONVSave::getSaveNumber()
    {
        return this->save->saveNumber;
    }

    string FONVSave::getPlayerName()
    {
        return string(this->save->playerName);
    }

    unsigned FONVSave::getPlayerLevel()
    {
        return this->save->playerLevel;
    }

    string FONVSave::getPlayerTitle()
    {
        return string(this->save->playerTitle);
    }

    string FONVSave::getPlayerLocation()
    {
        return string(this->save->playerLocation);
    }

    string FONVSave::getPlayerPlaytime()
    {
        return string(this->save->playerPlaytime);
    }

    unsigned FONVSave::getSnapshotWidth()
    {
        return this->save->snapshotWidth;
    }

    unsigned FONVSave::getSnapshotHeight()
    {
        return this->save->snapshotHeight;
    }

    unsigned char* FONVSave::getSnapshot()
    {
        return this->save->snapshot;
    }
}
