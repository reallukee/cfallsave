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

        if (this->save == NULL)
        {
            return;
        }
    }

    void FO4Save::printSave()
    {
        printFO4Save(this->save);
    }

    string FO4Save::getSaveSignature()
    {
        return string(this->save->saveSignature);
    }

    unsigned FO4Save::getEngineVersion()
    {
        return this->save->engineVersion;
    }

    unsigned FO4Save::getSaveNumber()
    {
        return this->save->saveNumber;
    }

    string FO4Save::getPlayerName()
    {
        return string(this->save->playerName);
    }

    unsigned FO4Save::getPlayerLevel()
    {
        return this->save->playerLevel;
    }

    string FO4Save::getPlayerLocation()
    {
        return string(this->save->playerLocation);
    }

    string FO4Save::getPlayerPlaytime()
    {
        return string(this->save->playerPlaytime);
    }

    string FO4Save::getPlayerRace()
    {
        return string(this->save->playerRace);
    }

    unsigned short FO4Save::getPlayerSex()
    {
        return this->save->playerSex;
    }

    float FO4Save::getPlayerCurrentXp()
    {
        return this->save->playerCurrentXp;
    }

    float FO4Save::getPlayerRequiredXp()
    {
        return this->save->playerRequiredXp;
    }

    unsigned FO4Save::getSnapshotWidth()
    {
        return this->save->snapshotWidth;
    }

    unsigned FO4Save::getSnapshotHeight()
    {
        return this->save->snapshotHeight;
    }

    unsigned char* FO4Save::getSnapshot()
    {
        return this->save->snapshot;
    }
}
