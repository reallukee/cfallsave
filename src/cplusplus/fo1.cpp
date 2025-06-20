/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
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
    string FO1Save::getFixedStringProp(FO1SAVE_PROPS prop)
    {
        switch (prop)
        {
        case FO1SAVE_PROPS_SAVE_SIGNATURE:
        {
            char c_value[FO1SAVE_SIGNATURE_LENGTH + 1];

            getFO1SaveProp(this->save, prop, (void**)&c_value);

            return c_value;
        }

        case FO1SAVE_PROPS_SAVE_NAME:
        case FO1SAVE_PROPS_PLAYER_NAME:
        {
            char c_value[FO1SAVE_STRING_SIZE];

            getFO1SaveProp(this->save, prop, (void**)&c_value);

            return c_value;
        }

        default:
            return "";
        }
    }



    void FO1Save::setFixedStringProp(FO1SAVE_PROPS prop, string value)
    {
        switch (prop)
        {
        case FO1SAVE_PROPS_SAVE_SIGNATURE:
        {
            char c_value[FO1SAVE_SIGNATURE_LENGTH + 1];

            strcpy(c_value, value.c_str());

            c_value[FO1SAVE_SIGNATURE_LENGTH] = '\0';

            setFO1SaveProp(this->save, prop, (void**)&c_value);

            break;
        }

        case FO1SAVE_PROPS_SAVE_NAME:
        case FO1SAVE_PROPS_PLAYER_NAME:
        {
            char c_value[FO1SAVE_STRING_SIZE + 1];

            strcpy(c_value, value.c_str());

            c_value[FO1SAVE_STRING_SIZE] = '\0';

            setFO1SaveProp(this->save, prop, (void**)&c_value);

            break;
        }

        default:
            break;
        }
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
        read(saveName);
    }

    FO1Save::~FO1Save()
    {
        closeFO1Save(this->save);
    }



    bool FO1Save::read(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFO1Save(c_saveName))
        {
            this->save = readFO1Save(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FO1Save::write()
    {
        return writeFO1Save(this->save);
    }

    void FO1Save::close()
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



    void FO1Save::print()
    {
        printFO1Save(this->save);
    }

    void FO1Save::printProps()
    {
        printFO1SaveProps(this->save);
    }

    void FO1Save::printPropAddresses()
    {
        printFO1SavePropAddresses(this->save);
    }



    bool FO1Save::createSampleSave()
    {
        return createFO1SampleSave();
    }



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
        return getFixedStringProp(FO1SAVE_PROPS_SAVE_SIGNATURE);
    }

    void FO1Save::setSaveSignature(string value)
    {
        setFixedStringProp(FO1SAVE_PROPS_SAVE_SIGNATURE, value);
    }

    string FO1Save::getSaveName()
    {
        return getFixedStringProp(FO1SAVE_PROPS_SAVE_NAME);
    }

    void FO1Save::setSaveName(string value)
    {
        setFixedStringProp(FO1SAVE_PROPS_SAVE_NAME, value);
    }



    string FO1Save::getPlayerName()
    {
        return getFixedStringProp(FO1SAVE_PROPS_PLAYER_NAME);
    }

    void FO1Save::setPlayerName(string value)
    {
        setFixedStringProp(FO1SAVE_PROPS_PLAYER_NAME, value);
    }
}
