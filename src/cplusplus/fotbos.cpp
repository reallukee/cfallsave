/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fotbos.cpp
 *
 * Title       : FALLOUT TACTICS: BROTHERHOOD OF STEEL SOURCE
 * Description : Fallout Tactics: Brotherhood of Steel Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.2.0
 * License     : MIT
 */

#include "fotbos.hpp"

namespace cfallsavepp
{
    string FOTBOSSave::getFixedStringProp(FOTBOSSAVE_PROPS prop)
    {
        char c_value[FOTBOSSAVE_SIGNATURE_LENGTH + 1];

        getFOTBOSSaveProp(this->save, prop, (void**)&c_value);

        return c_value;
    }

    string FOTBOSSave::getStringProp(FOTBOSSAVE_PROPS prop)
    {
        char* c_value = NULL;

        getFOTBOSSaveProp(this->save, prop, (void**)&c_value);

        string value = c_value;

        free(c_value);

        return value;
    }



    void FOTBOSSave::setFixedStringProp(FOTBOSSAVE_PROPS prop, string value)
    {
        char c_value[FOTBOSSAVE_SIGNATURE_LENGTH + 1];

        strcpy(c_value, value.c_str());

        c_value[FOTBOSSAVE_SIGNATURE_LENGTH] = '\0';

        setFOTBOSSaveProp(this->save, prop, (void**)&c_value);
    }

    void FOTBOSSave::setStringProp(FOTBOSSAVE_PROPS prop, string value)
    {
        const char* c_value = value.c_str();

        setFOTBOSSaveProp(this->save, prop, (void**)&c_value);
    }



    FOTBOSSave::FOTBOSSave()
    {
        return;
    }

    FOTBOSSave::FOTBOSSave(FOTBOSSAVE* save)
    {
        this->save = save;
    }

    FOTBOSSave::FOTBOSSave(string saveName)
    {
        read(saveName);
    }

    FOTBOSSave::~FOTBOSSave()
    {
        closeFOTBOSSave(this->save);
    }



    bool FOTBOSSave::read(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFOTBOSSave(c_saveName))
        {
            this->save = readFOTBOSSave(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FOTBOSSave::write()
    {
        return writeFOTBOSSave(this->save);
    }

    void FOTBOSSave::close()
    {
        return closeFOTBOSSave(this->save);
    }

    bool FOTBOSSave::isSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        return isFOTBOSSave(c_saveName);
    }

    bool FOTBOSSave::isOpen()
    {
        return isFOTBOSSaveOpen(this->save);
    }



    void FOTBOSSave::print()
    {
        printFOTBOSSave(this->save);
    }

    void FOTBOSSave::printProps()
    {
        printFOTBOSSaveProps(this->save);
    }

    void FOTBOSSave::printPropAddresses()
    {
        printFOTBOSSavePropAddresses(this->save);
    }



    FOTBOSSAVE* FOTBOSSave::getFOTBOSSAVE()
    {
        return this->save;
    }

    void FOTBOSSave::setFOTBOSSAVE(FOTBOSSAVE* save)
    {
        if (save == nullptr)
        {
            return;
        }

        if (this->save != nullptr)
        {
            closeFOTBOSSave(this->save);
        }

        this->save = save;
    }



    string FOTBOSSave::getGameName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return FOTBOSSAVE_GAME_NAME;
    }

    string FOTBOSSave::getSaveFileName()
    {
        if (this->save == nullptr || this->save->saveFileName == nullptr)
        {
            return "";
        }

        return save->saveFileName;
    }



    string FOTBOSSave::getSaveSignature()
    {
        return getFixedStringProp(FOTBOSSAVE_PROPS_SAVE_SIGNATURE);
    }

    void FOTBOSSave::setSaveSignature(string value)
    {
        setFixedStringProp(FOTBOSSAVE_PROPS_SAVE_SIGNATURE, value);
    }

    string FOTBOSSave::getSaveName()
    {
        return getStringProp(FOTBOSSAVE_PROPS_SAVE_NAME);
    }

    void FOTBOSSave::setSaveName(string value)
    {
        setStringProp(FOTBOSSAVE_PROPS_SAVE_NAME, value);
    }



    string FOTBOSSave::getPlayerName()
    {
        return getStringProp(FOTBOSSAVE_PROPS_PLAYER_NAME);
    }

    void FOTBOSSave::setPlayerName(string value)
    {
        setStringProp(FOTBOSSAVE_PROPS_PLAYER_NAME, value);
    }

    string FOTBOSSave::getPlayerLocation()
    {
        return getStringProp(FOTBOSSAVE_PROPS_PLAYER_LOCATION);
    }

    void FOTBOSSave::setPlayerLocation(string value)
    {
        setStringProp(FOTBOSSAVE_PROPS_PLAYER_LOCATION, value);
    }

    string FOTBOSSave::getGameDateTime()
    {
        return getStringProp(FOTBOSSAVE_PROPS_GAME_DATE_TIME);
    }

    void FOTBOSSave::setGameDateTime(string value)
    {
        setStringProp(FOTBOSSAVE_PROPS_GAME_DATE_TIME, value);
    }
}
