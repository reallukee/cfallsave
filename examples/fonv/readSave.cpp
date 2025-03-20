#include <iostream>
#include "../../src/cplusplus/cfallsave.hpp"

using namespace std;
using namespace cfallsavepp;

int main(int argc, char* argv[])
{
    FONVSave* save = new FONVSave("fonv.fos");

    save->printSave();

    delete save;

    return 0;
}
