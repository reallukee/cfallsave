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

#ifndef CFALLSAVE_FO2_HPP
#define CFALLSAVE_FO2_HPP

#include "header.hpp"

#include "../fo2.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVE_CPP_API FO2Save
    {

    private:

        FO2SAVE* save;

    public:

        FO2Save();
        FO2Save(string saveName);
        ~FO2Save();

        void readSave(string saveName);

        void printSave();

        string getSaveSignature();
        string getSaveName();

        string getPlayerName();

    };
}

#endif // !CFALLSAVE_FO2_HPP
