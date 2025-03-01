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

#include "fo2.hpp"

namespace cfallsave
{
    FO2Save::FO2Save()
    {
        return;
    }

    FO2Save::FO2Save(string saveName)
    {
        readSave(saveName);
    }

    FO2Save::~FO2Save()
    {
        closeFO2Save(this->save);
    }

    void FO2Save::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        this->save = readFO2Save(c_saveName);

        if (this->save == NULL)
        {
            return;
        }
    }

    void FO2Save::printSave()
    {
        printFO2Save(this->save);
    }

    string FO2Save::getSaveSignature()
    {
        return string(this->save->saveSignature);
    }

    string FO2Save::getSaveName()
    {
        return string(this->save->saveName);
    }

    string FO2Save::getPlayerName()
    {
        return string(this->save->playerName);
    }
}
