#include <iostream>
#include "../src/cplusplus/cfallsave.hpp"

using namespace std;
using namespace cfallsave;

int main()
{
    FO2Save* save = new FO2Save("fo2.dat");

    save->printSave();

    delete(save);

    return 0;
}
