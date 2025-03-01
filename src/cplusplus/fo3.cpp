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

        if (this->save == NULL)
        {
            return;
        }
    }

    void FO3Save::printSave()
    {
        printFO3Save(this->save);
    }

    string FO3Save::getSaveSignature()
    {
        return string(this->save->saveSignature);
    }

    unsigned FO3Save::getEngineVersion()
    {
        return this->save->engineVersion;
    }

    unsigned FO3Save::getSaveNumber()
    {
        return this->save->saveNumber;
    }

    string FO3Save::getPlayerName()
    {
        return string(this->save->playerName);
    }

    unsigned FO3Save::getPlayerLevel()
    {
        return this->save->playerLevel;
    }

    string FO3Save::getPlayerTitle()
    {
        return string(this->save->playerTitle);
    }

    string FO3Save::getPlayerLocation()
    {
        return string(this->save->playerLocation);
    }

    string FO3Save::getPlayerPlaytime()
    {
        return string(this->save->playerPlaytime);
    }

    unsigned FO3Save::getSnapshotWidth()
    {
        return this->save->snapshotWidth;
    }

    unsigned FO3Save::getSnapshotHeight()
    {
        return this->save->snapshotHeight;
    }

    unsigned char* FO3Save::getSnapshot()
    {
        return this->save->snapshot;
    }
}
