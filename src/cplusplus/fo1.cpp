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

#include "fo1.hpp"

namespace cfallsave
{
    FO1Save::FO1Save()
    {
        return;
    }

    FO1Save::FO1Save(string saveName)
    {
        readSave(saveName);
    }

    FO1Save::~FO1Save()
    {
        closeFO1Save(this->save);
    }

    void FO1Save::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        this->save = readFO1Save(c_saveName);

        if (this->save == NULL)
        {
            return;
        }
    }

    void FO1Save::printSave()
    {
        printFO1Save(this->save);
    }

    string FO1Save::getSaveSignature()
    {
        return string(this->save->saveSignature);
    }

    string FO1Save::getSaveName()
    {
        return string(this->save->saveName);
    }

    string FO1Save::getPlayerName()
    {
        return string(this->save->playerName);
    }
}
