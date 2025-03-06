#include <iostream>
#include "../src/cplusplus/cfallsave.hpp"

using namespace std;
using namespace cfallsave;

int main()
{
    FONVSave* save = new FONVSave("fonv.fos");

    save->printSave();

    delete(save);

    return 0;
}
