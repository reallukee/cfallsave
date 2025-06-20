/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ library to read and write Fallout save files
 *
 * File Name   : fo3.cpp
 *
 * Title       : FALLOUT 3 SOURCE
 * Description : Fallout 3 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo3.hpp"

namespace cfallsavepp
{
    string FO3Save::getFixedStringProp(FO3SAVE_PROPS prop)
    {
        char c_value[FO3SAVE_SIGNATURE_LENGTH + 1];

        getFO3SaveProp(this->save, prop, (void**)&c_value);

        return c_value;
    }

    unsigned int FO3Save::getUIntProp(FO3SAVE_PROPS prop)
    {
        unsigned int c_value;

        getFO3SaveProp(this->save, prop, (void**)&c_value);

        return c_value;
    }

    string FO3Save::getStringProp(FO3SAVE_PROPS prop)
    {
        char* c_value = NULL;

        getFO3SaveProp(this->save, prop, (void**)&c_value);

        string value = c_value;

        free(c_value);

        return value;
    }

    unsigned char* FO3Save::getUByteArrayProp(FO3SAVE_PROPS prop)
    {
        return NULL;
    }



    void FO3Save::setFixedStringProp(FO3SAVE_PROPS prop, string value)
    {
        char c_value[FO3SAVE_SIGNATURE_LENGTH + 1];

        strcpy(c_value, value.c_str());

        c_value[FO3SAVE_SIGNATURE_LENGTH] = '\0';

        setFO3SaveProp(this->save, prop, (void**)&c_value);
    }

    void FO3Save::setUIntProp(FO3SAVE_PROPS prop, unsigned int value)
    {
        unsigned int c_value = value;

        setFO3SaveProp(this->save, prop, (void**)&c_value);
    }

    void FO3Save::setStringProp(FO3SAVE_PROPS prop, string value)
    {
        const char* c_value = value.c_str();

        setFO3SaveProp(this->save, prop, (void**)&c_value);
    }

    void FO3Save::setUByteArrayProp(FO3SAVE_PROPS prop, unsigned char* value)
    {
        return;
    }



    FO3Save::FO3Save()
    {
        return;
    }

    FO3Save::FO3Save(FO3SAVE* save)
    {
        this->save = save;
    }

    FO3Save::FO3Save(string saveName)
    {
        read(saveName);
    }

    FO3Save::~FO3Save()
    {
        closeFO3Save(this->save);
    }



    bool FO3Save::read(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFO3Save(c_saveName))
        {
            this->save = readFO3Save(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FO3Save::write()
    {
        return writeFO3Save(this->save);
    }

    void FO3Save::close()
    {
        return closeFO3Save(this->save);
    }

    bool FO3Save::isSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        return isFO3Save(c_saveName);
    }

    bool FO3Save::isOpen()
    {
        return isFO3SaveOpen(this->save);
    }



    void FO3Save::print()
    {
        printFO3Save(this->save);
    }

    void FO3Save::printProps()
    {
        printFO3SaveProps(this->save);
    }

    void FO3Save::printPropAddresses()
    {
        printFO3SavePropAddresses(this->save);
    }

    void FO3Save::printSnapshot()
    {
        printFO3SaveSnapshot(this->save);
    }



    bool FO3Save::createSampleSave()
    {
        return createFO3SampleSave();
    }



    FO3SAVE* FO3Save::getFO3SAVE()
    {
        return this->save;
    }

    void FO3Save::setFO3SAVE(FO3SAVE* save)
    {
        if (save == nullptr)
        {
            return;
        }

        if (this->save != nullptr)
        {
            closeFO3Save(this->save);
        }

        this->save = save;
    }



    string FO3Save::getGameName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return FO3SAVE_GAME_NAME;
    }

    string FO3Save::getSaveFileName()
    {
        if (this->save == nullptr || this->save->saveFileName == nullptr)
        {
            return "";
        }

        return save->saveFileName;
    }



    string FO3Save::getSaveSignature()
    {
        return getFixedStringProp(FO3SAVE_PROPS_SAVE_SIGNATURE);
    }

    void FO3Save::setSaveSignature(string value)
    {
        setFixedStringProp(FO3SAVE_PROPS_SAVE_SIGNATURE, value);
    }

    unsigned int FO3Save::getEngineVersion()
    {
        return getUIntProp(FO3SAVE_PROPS_ENGINE_VERSION);
    }

    void FO3Save::setEngineVersion(unsigned int value)
    {
        setUIntProp(FO3SAVE_PROPS_ENGINE_VERSION, value);
    }

    unsigned int FO3Save::getSaveNumber()
    {
        return getUIntProp(FO3SAVE_PROPS_SAVE_NUMBER);
    }

    void FO3Save::setSaveNumber(unsigned int value)
    {
        setUIntProp(FO3SAVE_PROPS_SAVE_NUMBER, value);
    }



    string FO3Save::getPlayerName()
    {
        return getStringProp(FO3SAVE_PROPS_PLAYER_NAME);
    }

    void FO3Save::setPlayerName(string value)
    {
        setStringProp(FO3SAVE_PROPS_PLAYER_NAME, value);
    }

    unsigned int FO3Save::getPlayerLevel()
    {
        return getUIntProp(FO3SAVE_PROPS_PLAYER_LEVEL);
    }

    void FO3Save::setPlayerLevel(unsigned int value)
    {
        setUIntProp(FO3SAVE_PROPS_PLAYER_LEVEL, value);
    }

    string FO3Save::getPlayerTitle()
    {
        return getStringProp(FO3SAVE_PROPS_PLAYER_TITLE);
    }

    void FO3Save::setPlayerTitle(string value)
    {
        setStringProp(FO3SAVE_PROPS_PLAYER_TITLE, value);
    }

    string FO3Save::getPlayerLocation()
    {
        return getStringProp(FO3SAVE_PROPS_PLAYER_LOCATION);
    }

    void FO3Save::setPlayerLocation(string value)
    {
        setStringProp(FO3SAVE_PROPS_PLAYER_LOCATION, value);
    }

    string FO3Save::getPlayerPlaytime()
    {
        return getStringProp(FO3SAVE_PROPS_PLAYER_PLAYTIME);
    }

    void FO3Save::setPlayerPlaytime(string value)
    {
        setStringProp(FO3SAVE_PROPS_PLAYER_PLAYTIME, value);
    }



    unsigned int FO3Save::getSnapshotWidth()
    {
        return getUIntProp(FO3SAVE_PROPS_SNAPSHOT_WIDTH);
    }

    void FO3Save::setSnapshotWidth(unsigned int value)
    {
        setUIntProp(FO3SAVE_PROPS_SNAPSHOT_WIDTH, value);
    }

    unsigned int FO3Save::getSnapshotHeight()
    {
        return getUIntProp(FO3SAVE_PROPS_SNAPSHOT_HEIGHT);
    }

    void FO3Save::setSnapshotHeight(unsigned int value)
    {
        setUIntProp(FO3SAVE_PROPS_SNAPSHOT_HEIGHT, value);
    }

    long unsigned int FO3Save::getSnapshotLength()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotLength;
    }

    unsigned char* FO3Save::getSnapshot()
    {
        return getUByteArrayProp(FO3SAVE_PROPS_SNAPSHOT);
    }

    void FO3Save::setSnapshot(unsigned char* value)
    {
        setUByteArrayProp(FO3SAVE_PROPS_SNAPSHOT, value);
    }
}
