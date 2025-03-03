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

#ifndef CFALLSAVE_FONV_HPP
#define CFALLSAVE_FONV_HPP

#include "header.hpp"

#include "../fonv.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVE_CPP_API FONVSave
    {

    private:

        FONVSAVE* save;

    public:

        FONVSave();
        FONVSave(string saveName);
        ~FONVSave();

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

#endif // !CFALLSAVE_FONV_HPP
