/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : fo2.cpp
 *
 * Title       : FALLOUT 2 SOURCE
 * Description : Fallout 2 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo2.hpp"

namespace cfallsavepp
{
    FO2SAVE* FO2Save::getFO2SAVE()
    {
        return this->save;
    }

    void FO2Save::setFO2SAVE(FO2SAVE* save)
    {
        if (save == nullptr)
        {
            return;
        }

        if (this->save != nullptr)
        {
            closeFO2Save(this->save);
        }

        this->save = save;
    }



    FO2Save::FO2Save()
    {
        return;
    }

    FO2Save::FO2Save(FO2SAVE* save)
    {
        this->save = save;
    }

    FO2Save::FO2Save(string saveName)
    {
        readSave(saveName);
    }

    FO2Save::~FO2Save()
    {
        closeFO2Save(this->save);
    }



    bool FO2Save::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFO2Save(c_saveName))
        {
            this->save = readFO2Save(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FO2Save::writeSave()
    {
        return writeFO2Save(this->save);
    }

    void FO2Save::closeSave()
    {
        return closeFO2Save(this->save);
    }

    bool FO2Save::isSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        return isFO2Save(c_saveName);
    }

    bool FO2Save::isOpen()
    {
        return isFO2SaveOpen(this->save);
    }



    void FO2Save::printSave()
    {
        printFO2Save(this->save);
    }

    void FO2Save::printSaveProps()
    {
        printFO2SaveProps(this->save);
    }

    void FO2Save::printSavePropAddresses()
    {
        printFO2SavePropAddresses(this->save);
    }



    string FO2Save::getGameName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return FO2SAVE_GAME_NAME;
    }

    string FO2Save::getSaveFileName()
    {
        if (this->save == nullptr || this->save->saveFileName == nullptr)
        {
            return "";
        }

        return save->saveFileName;
    }



    string FO2Save::getSaveSignature()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveSignature;
    }

    string FO2Save::getSaveName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveName;
    }



    string FO2Save::getPlayerName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }
}
