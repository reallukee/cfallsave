/**
 * -----------
 * CFallSave++
 * -----------
 *
 * A C/C++ Library to Read and Write Fallout Save Files
 *
 * File Name   : fo4.cpp
 *
 * Title       : FALLOUT 4 SOURCE
 * Description : Fallout 4 Source
 *
 * Author      : Luca Pollicino
 *               (https://github.com/reallukee)
 * Version     : 2.0.0
 * License     : MIT
 */

#include "fo4.hpp"

namespace cfallsavepp
{
    string FO4Save::getFixedStringProp(FO4SAVE_PROPS prop)
    {
        char c_value[FO4SAVE_SIGNATURE_LENGTH + 1];

        getFO4SaveProp(this->save, prop, (void**)&c_value);

        return c_value;
    }

    unsigned int FO4Save::getUIntProp(FO4SAVE_PROPS prop)
    {
        unsigned int c_value;

        getFO4SaveProp(this->save, prop, (void**)&c_value);

        return c_value;
    }

    string FO4Save::getStringProp(FO4SAVE_PROPS prop)
    {
        char* c_value = NULL;

        getFO4SaveProp(this->save, prop, (void**)&c_value);

        string value = c_value;

        free(c_value);

        return value;
    }

    short unsigned int FO4Save::getUShortProp(FO4SAVE_PROPS prop)
    {
        short unsigned int c_value;

        getFO4SaveProp(this->save, prop, (void**)&c_value);

        return c_value;
    }

    float FO4Save::getFloatProp(FO4SAVE_PROPS prop)
    {
        float c_value;

        getFO4SaveProp(this->save, prop, (void**)&c_value);

        return c_value;
    }

    unsigned char* FO4Save::getUByteArrayProp(FO4SAVE_PROPS prop)
    {
        return NULL;
    }



    void FO4Save::setFixedStringProp(FO4SAVE_PROPS prop, string value)
    {
        char c_value[FO4SAVE_SIGNATURE_LENGTH + 1];

        strcpy(c_value, value.c_str());

        c_value[FO4SAVE_SIGNATURE_LENGTH] = '\0';

        setFO4SaveProp(this->save, prop, (void**)&c_value);
    }

    void FO4Save::setUIntProp(FO4SAVE_PROPS prop, unsigned int value)
    {
        unsigned int c_value = value;

        setFO4SaveProp(this->save, prop, (void**)&c_value);
    }

    void FO4Save::setStringProp(FO4SAVE_PROPS prop, string value)
    {
        const char* c_value = value.c_str();

        setFO4SaveProp(this->save, prop, (void**)&c_value);
    }

    void FO4Save::setUShortProp(FO4SAVE_PROPS prop, short unsigned int value)
    {
        short unsigned int c_value = value;

        setFO4SaveProp(this->save, prop, (void**)&c_value);
    }

    void FO4Save::setFloatProp(FO4SAVE_PROPS prop, float value)
    {
        float c_value = value;

        setFO4SaveProp(this->save, prop, (void**)&c_value);
    }

    void FO4Save::setUByteArrayProp(FO4SAVE_PROPS prop, unsigned char* value)
    {
        return;
    }



    FO4Save::FO4Save()
    {
        return;
    }

    FO4Save::FO4Save(FO4SAVE* save)
    {
        this->save = save;
    }

    FO4Save::FO4Save(string saveName)
    {
        read(saveName);
    }

    FO4Save::~FO4Save()
    {
        closeFO4Save(this->save);
    }



    bool FO4Save::read(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        if (isFO4Save(c_saveName))
        {
            this->save = readFO4Save(c_saveName);
        }

        return this->save != nullptr;
    }

    bool FO4Save::write()
    {
        return writeFO4Save(this->save);
    }

    void FO4Save::close()
    {
        return closeFO4Save(this->save);
    }

    bool FO4Save::isSave(string saveName)
    {
        const char* c_saveName = saveName.c_str();

        return isFO4Save(c_saveName);
    }

    bool FO4Save::isOpen()
    {
        return isFO4SaveOpen(this->save);
    }



    void FO4Save::print()
    {
        printFO4Save(this->save);
    }

    void FO4Save::printProps()
    {
        printFO4SaveProps(this->save);
    }

    void FO4Save::printPropAddresses()
    {
        printFO4SavePropAddresses(this->save);
    }

    void FO4Save::printSnapshot()
    {
        printFO4SaveSnapshot(this->save);
    }



    bool FO4Save::createSampleSave()
    {
        return createFO4SampleSave();
    }



    FO4SAVE* FO4Save::getFO4SAVE()
    {
        return this->save;
    }

    void FO4Save::setFO4SAVE(FO4SAVE* save)
    {
        if (save == nullptr)
        {
            return;
        }

        if (this->save != nullptr)
        {
            closeFO4Save(this->save);
        }

        this->save = save;
    }



    string FO4Save::getGameName()
    {
        if (this->save == nullptr)
        {
            return "";
        }

        return FO4SAVE_GAME_NAME;
    }

    string FO4Save::getSaveFileName()
    {
        if (this->save == nullptr || this->save->saveFileName == nullptr)
        {
            return "";
        }

        return save->saveFileName;
    }



    string FO4Save::getSaveSignature()
    {
        return getFixedStringProp(FO4SAVE_PROPS_SAVE_SIGNATURE);
    }

    void FO4Save::setSaveSignature(string value)
    {
        setFixedStringProp(FO4SAVE_PROPS_SAVE_SIGNATURE, value);
    }

    unsigned int FO4Save::getEngineVersion()
    {
        return getUIntProp(FO4SAVE_PROPS_ENGINE_VERSION);
    }

    void FO4Save::setEngineVersion(unsigned int value)
    {
        setUIntProp(FO4SAVE_PROPS_ENGINE_VERSION, value);
    }

    unsigned int FO4Save::getSaveNumber()
    {
        return getUIntProp(FO4SAVE_PROPS_SAVE_NUMBER);
    }

    void FO4Save::setSaveNumber(unsigned int value)
    {
        setUIntProp(FO4SAVE_PROPS_SAVE_NUMBER, value);
    }



    string FO4Save::getPlayerName()
    {
        return getStringProp(FO4SAVE_PROPS_PLAYER_NAME);
    }

    void FO4Save::setPlayerName(string value)
    {
        setStringProp(FO4SAVE_PROPS_PLAYER_NAME, value);
    }

    unsigned int FO4Save::getPlayerLevel()
    {
        return getUIntProp(FO4SAVE_PROPS_PLAYER_LEVEL);
    }

    void FO4Save::setPlayerLevel(unsigned int value)
    {
        setUIntProp(FO4SAVE_PROPS_PLAYER_LEVEL, value);
    }

    string FO4Save::getPlayerLocation()
    {
        return getStringProp(FO4SAVE_PROPS_PLAYER_LOCATION);
    }

    void FO4Save::setPlayerLocation(string value)
    {
        setStringProp(FO4SAVE_PROPS_PLAYER_LOCATION, value);
    }

    string FO4Save::getPlayerPlaytime()
    {
        return getStringProp(FO4SAVE_PROPS_PLAYER_PLAYTIME);
    }

    void FO4Save::setPlayerPlaytime(string value)
    {
        setStringProp(FO4SAVE_PROPS_PLAYER_PLAYTIME, value);
    }

    string FO4Save::getPlayerRace()
    {
        return getStringProp(FO4SAVE_PROPS_PLAYER_RACE);
    }

    void FO4Save::setPlayerRace(string value)
    {
        setStringProp(FO4SAVE_PROPS_PLAYER_RACE, value);
    }

    short unsigned int FO4Save::getPlayerSex()
    {
        return getUShortProp(FO4SAVE_PROPS_PLAYER_SEX);
    }

    void FO4Save::setPlayerSex(short unsigned int value)
    {
        setUShortProp(FO4SAVE_PROPS_PLAYER_SEX, value);
    }

    float FO4Save::getPlayerCurrentXp()
    {
        return getFloatProp(FO4SAVE_PROPS_PLAYER_CURRENT_XP);
    }

    void FO4Save::setPlayerCurrentXp(float value)
    {
        setFloatProp(FO4SAVE_PROPS_PLAYER_CURRENT_XP, value);
    }

    float FO4Save::getPlayerRequiredXp()
    {
        return getFloatProp(FO4SAVE_PROPS_PLAYER_REQUIRED_XP);
    }

    void FO4Save::setPlayerRequiredXp(float value)
    {
        setFloatProp(FO4SAVE_PROPS_PLAYER_REQUIRED_XP, value);
    }



    unsigned int FO4Save::getSnapshotWidth()
    {
        return getUIntProp(FO4SAVE_PROPS_SNAPSHOT_WIDTH);
    }

    void FO4Save::setSnapshotWidth(unsigned int value)
    {
        setUIntProp(FO4SAVE_PROPS_SNAPSHOT_WIDTH, value);
    }

    unsigned int FO4Save::getSnapshotHeight()
    {
        return getUIntProp(FO4SAVE_PROPS_SNAPSHOT_HEIGHT);
    }

    void FO4Save::setSnapshotHeight(unsigned int value)
    {
        setUIntProp(FO4SAVE_PROPS_SNAPSHOT_HEIGHT, value);
    }

    long unsigned int FO4Save::getSnapshotLength()
    {
        if (this->save == nullptr)
        {
            return 0;
        }

        return this->save->snapshotLength;
    }

    unsigned char* FO4Save::getSnapshot()
    {
        return getUByteArrayProp(FO4SAVE_PROPS_SNAPSHOT);
    }

    void FO4Save::setSnapshot(unsigned char* value)
    {
        setUByteArrayProp(FO4SAVE_PROPS_SNAPSHOT, value);
    }
}
