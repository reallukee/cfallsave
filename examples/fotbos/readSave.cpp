#include <iostream>
#include "../../src/cplusplus/cfallsave.hpp"

using namespace std;
using namespace cfallsavepp;

int main(int argc, char* argv[])
{
    FOTBOSSave* save = new FOTBOSSave("fotbos.sav");

    save->printSave();

    delete save;

    return 0;
}
