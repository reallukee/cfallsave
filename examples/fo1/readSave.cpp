#include <iostream>
#include "../../src/cplusplus/cfallsave.hpp"

using namespace std;
using namespace cfallsavepp;

int main(int argc, char* argv[])
{
    FO1Save* save = new FO1Save("fo1.dat");

    save->printSave();

    delete save;

    return 0;
}
