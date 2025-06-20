/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
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
    string FO2Save::getFixedStringProp(FO2SAVE_PROPS prop)
    {
        switch (prop)
        {
        case FO2SAVE_PROPS_SAVE_SIGNATURE:
        {
            char c_value[FO2SAVE_SIGNATURE_LENGTH + 1];

            getFO2SaveProp(this->save, prop, (void**)&c_value);

            return c_value;
        }

        case FO2SAVE_PROPS_SAVE_NAME:
        case FO2SAVE_PROPS_PLAYER_NAME:
        {
            char c_value[FO2SAVE_STRING_SIZE];

            getFO2SaveProp(this->save, prop, (void**)&c_value);

            return c_value;
        }

        default:
            return "";
        }
    }



    void FO2Save::setFixedStringProp(FO2SAVE_PROPS prop, string value)
    {
        switch (prop)
        {
        case FO2SAVE_PROPS_SAVE_SIGNATURE:
        {
            char c_value[FO2SAVE_SIGNATURE_LENGTH + 1];

            strcpy(c_value, value.c_str());

            c_value[FO2SAVE_SIGNATURE_LENGTH] = '\0';

            setFO2SaveProp(this->save, prop, (void**)&c_value);

            break;
        }

        case FO2SAVE_PROPS_SAVE_NAME:
        case FO2SAVE_PROPS_PLAYER_NAME:
        {
            char c_value[FO2SAVE_STRING_SIZE + 1];

            strcpy(c_value, value.c_str());

            c_value[FO2SAVE_STRING_SIZE] = '\0';

            setFO2SaveProp(this->save, prop, (void**)&c_value);

            break;
        }

        default:
            break;
        }
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
        read(saveName);
    }

    FO2Save::~FO2Save()
    {
        closeFO2Save(this->save);
    }



    bool FO2Save::read(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFO2Save(c_saveName))
        {
            this->save = readFO2Save(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FO2Save::write()
    {
        return writeFO2Save(this->save);
    }

    void FO2Save::close()
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



    void FO2Save::print()
    {
        printFO2Save(this->save);
    }

    void FO2Save::printProps()
    {
        printFO2SaveProps(this->save);
    }

    void FO2Save::printPropAddresses()
    {
        printFO2SavePropAddresses(this->save);
    }



    bool FO2Save::createSampleSave()
    {
        return createFO2SampleSave();
    }



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
        return getFixedStringProp(FO2SAVE_PROPS_SAVE_SIGNATURE);
    }

    void FO2Save::setSaveSignature(string value)
    {
        setFixedStringProp(FO2SAVE_PROPS_SAVE_SIGNATURE, value);
    }

    string FO2Save::getSaveName()
    {
        return getFixedStringProp(FO2SAVE_PROPS_SAVE_NAME);
    }

    void FO2Save::setSaveName(string value)
    {
        setFixedStringProp(FO2SAVE_PROPS_SAVE_NAME, value);
    }



    string FO2Save::getPlayerName()
    {
        return getFixedStringProp(FO2SAVE_PROPS_PLAYER_NAME);
    }

    void FO2Save::setPlayerName(string value)
    {
        setFixedStringProp(FO2SAVE_PROPS_PLAYER_NAME, value);
    }
}
