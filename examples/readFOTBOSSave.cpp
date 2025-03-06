#include <iostream>
#include "../src/cplusplus/cfallsave.hpp"

using namespace std;
using namespace cfallsave;

int main()
{
    FOTBOSSave* save = new FOTBOSSave("fotbos.sav");

    save->printSave();

    delete(save);

    return 0;
}
