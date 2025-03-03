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

#ifndef CFALLSAVE_FO3_HPP
#define CFALLSAVE_FO3_HPP

#include "header.hpp"

#include "../fo3.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVE_CPP_API FO3Save
    {

    private:

        FO3SAVE* save;

    public:

        FO3Save();
        FO3Save(string saveName);
        ~FO3Save();

        void readSave(string saveName);

        void printSave();

        string getSaveSignature();
        unsigned getEngineVersion();
        unsigned getSaveNumber();

        string getPlayerName();
        unsigned getPlayerLevel();
        string getPlayerTitle();
        string getPlayerLocation();
        string getPlayerPlaytime();

        unsigned getSnapshotWidth();
        unsigned getSnapshotHeight();
        unsigned char* getSnapshot();

    };
}

#endif // !CFALLSAVE_FO3_HPP
