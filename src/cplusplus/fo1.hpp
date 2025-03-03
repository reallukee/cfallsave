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

#ifndef CFALLSAVE_FO1_HPP
#define CFALLSAVE_FO1_HPP

#include "header.hpp"

#include "../fo1.h"

using namespace std;

namespace cfallsave
{
    class CFALLSAVE_CPP_API FO1Save
    {

    private:

        FO1SAVE* save;

    public:

        FO1Save();
        FO1Save(string saveName);
        ~FO1Save();

        void readSave(string saveName);

        void printSave();

        string getSaveSignature();
        string getSaveName();

        string getPlayerName();

    };
}

#endif // !CFALLSAVE_FO1_HPP
