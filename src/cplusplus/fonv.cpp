/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fonv.cpp
 *
 * Title       : FALLOUT: NEW VEGAS SOURCE
 * Description : Fallout: New Vegas Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fonv.hpp"

namespace cfallsavepp
{
    string FONVSave::getFixedStringProp(FONVSAVE_PROPS prop)
    {
        char c_value[FONVSAVE_SIGNATURE_LENGTH + 1];

        getFONVSaveProp(this->save, prop, (void**)&c_value);

        return c_value;
    }

    unsigned int FONVSave::getUIntProp(FONVSAVE_PROPS prop)
    {
        unsigned int c_value;

        getFONVSaveProp(this->save, prop, (void**)&c_value);

        return c_value;
    }

    string FONVSave::getStringProp(FONVSAVE_PROPS prop)
    {
        char* c_value = NULL;

        getFONVSaveProp(this->save, prop, (void**)&c_value);

        string value = c_value;

        free(c_value);

        return value;
    }

    unsigned char* FONVSave::getUByteArrayProp(FONVSAVE_PROPS prop)
    {
        return NULL;
    }



    void FONVSave::setFixedStringProp(FONVSAVE_PROPS prop, string value)
    {
        char c_value[FONVSAVE_SIGNATURE_LENGTH + 1];

        strcpy(c_value, value.c_str());

        c_value[FONVSAVE_SIGNATURE_LENGTH] = '\0';

        setFONVSaveProp(this->save, prop, (void**)&c_value);
    }

    void FONVSave::setUIntProp(FONVSAVE_PROPS prop, unsigned int value)
    {
        unsigned int c_value = value;

        setFONVSaveProp(this->save, prop, (void**)&c_value);
    }

    void FONVSave::setStringProp(FONVSAVE_PROPS prop, string value)
    {
        const char* c_value = value.c_str();

        setFONVSaveProp(this->save, prop, (void**)&c_value);
    }

    void FONVSave::setUByteArrayProp(FONVSAVE_PROPS prop, unsigned char* value)
    {
        return;
    }



    FONVSave::FONVSave()
    {
        return;
    }

    FONVSave::FONVSave(FONVSAVE* save)
    {
        this->save = save;
    }

    FONVSave::FONVSave(string saveName)
    {
        read(saveName);
    }

    FONVSave::~FONVSave()
    {
        closeFONVSave(this->save);
    }



    bool FONVSave::read(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFONVSave(c_saveName))
        {
            this->save = readFONVSave(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FONVSave::write()
    {
        return writeFONVSave(this->save);
    }

    void FONVSave::close()
    {
        return closeFONVSave(this->save);
    }

    bool FONVSave::isSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        return isFONVSave(c_saveName);
    }

    bool FONVSave::isOpen()
    {
        return isFONVSaveOpen(this->save);
    }



    void FONVSave::print()
    {
        printFONVSave(this->save);
    }

    void FONVSave::printProps()
    {
        printFONVSaveProps(this->save);
    }

    void FONVSave::printPropAddresses()
    {
        printFONVSavePropAddresses(this->save);
    }

    void FONVSave::printSnapshot()
    {
        printFONVSaveSnapshot(this->save);
    }



    bool FONVSave::createSampleSave()
    {
        return createFONVSampleSave();
    }



    FONVSAVE* FONVSave::getFONVSAVE()
    {
        return this->save;
    }

    void FONVSave::setFONVSAVE(FONVSAVE* save)
    {
        if (save == nullptr)
        {
            return;
        }

        if (this->save != nullptr)
        {
            closeFONVSave(this->save);
        }

        this->save = save;
    }



    string FONVSave::getGameName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return FONVSAVE_GAME_NAME;
    }

    string FONVSave::getSaveFileName()
    {
        if (this->save == nullptr || this->save->saveFileName == nullptr)
        {
            return "";
        }

        return save->saveFileName;
    }



    string FONVSave::getSaveSignature()
    {
        return getFixedStringProp(FONVSAVE_PROPS_SAVE_SIGNATURE);
    }

    void FONVSave::setSaveSignature(string value)
    {
        setFixedStringProp(FONVSAVE_PROPS_SAVE_SIGNATURE, value);
    }

    unsigned int FONVSave::getEngineVersion()
    {
        return getUIntProp(FONVSAVE_PROPS_ENGINE_VERSION);
    }

    void FONVSave::setEngineVersion(unsigned int value)
    {
        setUIntProp(FONVSAVE_PROPS_ENGINE_VERSION, value);
    }

    unsigned int FONVSave::getSaveNumber()
    {
        return getUIntProp(FONVSAVE_PROPS_SAVE_NUMBER);
    }

    void FONVSave::setSaveNumber(unsigned int value)
    {
        setUIntProp(FONVSAVE_PROPS_SAVE_NUMBER, value);
    }



    string FONVSave::getPlayerName()
    {
        return getStringProp(FONVSAVE_PROPS_PLAYER_NAME);
    }

    void FONVSave::setPlayerName(string value)
    {
        setStringProp(FONVSAVE_PROPS_PLAYER_NAME, value);
    }

    unsigned int FONVSave::getPlayerLevel()
    {
        return getUIntProp(FONVSAVE_PROPS_PLAYER_LEVEL);
    }

    void FONVSave::setPlayerLevel(unsigned int value)
    {
        setUIntProp(FONVSAVE_PROPS_PLAYER_LEVEL, value);
    }

    string FONVSave::getPlayerTitle()
    {
        return getStringProp(FONVSAVE_PROPS_PLAYER_TITLE);
    }

    void FONVSave::setPlayerTitle(string value)
    {
        setStringProp(FONVSAVE_PROPS_PLAYER_TITLE, value);
    }

    string FONVSave::getPlayerLocation()
    {
        return getStringProp(FONVSAVE_PROPS_PLAYER_LOCATION);
    }

    void FONVSave::setPlayerLocation(string value)
    {
        setStringProp(FONVSAVE_PROPS_PLAYER_LOCATION, value);
    }

    string FONVSave::getPlayerPlaytime()
    {
        return getStringProp(FONVSAVE_PROPS_PLAYER_PLAYTIME);
    }

    void FONVSave::setPlayerPlaytime(string value)
    {
        setStringProp(FONVSAVE_PROPS_PLAYER_PLAYTIME, value);
    }



    unsigned int FONVSave::getSnapshotWidth()
    {
        return getUIntProp(FONVSAVE_PROPS_SNAPSHOT_WIDTH);
    }

    void FONVSave::setSnapshotWidth(unsigned int value)
    {
        setUIntProp(FONVSAVE_PROPS_SNAPSHOT_WIDTH, value);
    }

    unsigned int FONVSave::getSnapshotHeight()
    {
        return getUIntProp(FONVSAVE_PROPS_SNAPSHOT_HEIGHT);
    }

    void FONVSave::setSnapshotHeight(unsigned int value)
    {
        setUIntProp(FONVSAVE_PROPS_SNAPSHOT_HEIGHT, value);
    }

    long unsigned int FONVSave::getSnapshotLength()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotLength;
    }

    unsigned char* FONVSave::getSnapshot()
    {
        return getUByteArrayProp(FONVSAVE_PROPS_SNAPSHOT);
    }

    void FONVSave::setSnapshot(unsigned char* value)
    {
        setUByteArrayProp(FONVSAVE_PROPS_SNAPSHOT, value);
    }
}
