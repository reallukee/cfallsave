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

#ifndef CFALLSAVE_FO4_HPP
#define CFALLSAVE_FO4_HPP

#include "header.hpp"

#include "../fo4.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVE_CPP_API FO4Save
    {

    private:

        FO4SAVE* save;

    public:

        FO4Save();
        FO4Save(string saveName);
        ~FO4Save();

        void readSave(string saveName);

        void printSave();

        string getSaveSignature();
        unsigned getEngineVersion();
        unsigned getSaveNumber();

        string getPlayerName();
        unsigned getPlayerLevel();
        string getPlayerLocation();
        string getPlayerPlaytime();
        string getPlayerRace();
        unsigned short getPlayerSex();
        float getPlayerCurrentXp();
        float getPlayerRequiredXp();

        unsigned getSnapshotWidth();
        unsigned getSnapshotHeight();
        unsigned char* getSnapshot();

    };
}

#endif // !CFALLSAVE_FO4_HPP
