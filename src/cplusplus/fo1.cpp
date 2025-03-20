/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read Fallout Save Files
 *
 * File Name   : fo1.cpp
 *
 * Title       : FALLOUT 1 SOURCE
 * Description : Fallout 1 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo1.hpp"

namespace cfallsavepp
{
    FO1SAVE* FO1Save::getFO1SAVE()
    {
        return this->save;
    }

    void FO1Save::setFO1SAVE(FO1SAVE* save)
    {
        if (save == nullptr)
        {
            return;
        }

        if (this->save != nullptr)
        {
            closeFO1Save(this->save);
        }

        this->save = save;
    }



    FO1Save::FO1Save()
    {
        return;
    }

    FO1Save::FO1Save(FO1SAVE* save)
    {
        this->save = save;
    }

    FO1Save::FO1Save(string saveName)
    {
        readSave(saveName);
    }

    FO1Save::~FO1Save()
    {
        closeFO1Save(this->save);
    }



    bool FO1Save::readSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFO1Save(c_saveName))
        {
            this->save = readFO1Save(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FO1Save::writeSave()
    {
        return writeFO1Save(this->save);
    }

    void FO1Save::closeSave()
    {
        return closeFO1Save(this->save);
    }

    bool FO1Save::isSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        return isFO1Save(c_saveName);
    }

    bool FO1Save::isOpen()
    {
        return isFO1SaveOpen(this->save);
    }



    void FO1Save::printSave()
    {
        printFO1Save(this->save);
    }

    void FO1Save::printSaveProps()
    {
        printFO1SaveProps(this->save);
    }

    void FO1Save::printSavePropAddresses()
    {
        printFO1SavePropAddresses(this->save);
    }



    string FO1Save::getGameName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return FO1SAVE_GAME_NAME;
    }

    string FO1Save::getSaveFileName()
    {
        if (this->save == nullptr || this->save->saveFileName == nullptr)
        {
            return "";
        }

        return save->saveFileName;
    }



    string FO1Save::getSaveSignature()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveSignature;
    }

    string FO1Save::getSaveName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->saveName;
    }



    string FO1Save::getPlayerName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return this->save->playerName;
    }
}
