#include <iostream>
#include "../../src/cplusplus/cfallsave.hpp"

using namespace std;
using namespace cfallsavepp;

int main(int argc, char* argv[])
{
    FO4Save* save = new FO4Save("fo4.fos");

    save->printSave();

    delete save;

    return 0;
}
