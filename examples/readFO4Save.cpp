#include <iostream>
#include "../src/cplusplus/cfallsave.hpp"

using namespace std;
using namespace cfallsave;

int main()
{
    FO4Save* save = new FO4Save("fo4.fos");

    save->printSave();

    delete(save);

    return 0;
}
