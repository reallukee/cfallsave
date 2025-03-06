#include <iostream>
#include "../src/cplusplus/cfallsave.hpp"

using namespace std;
using namespace cfallsave;

int main()
{
    FO3Save* save = new FO3Save("fo3.fos");

    save->printSave();

    delete(save);

    return 0;
}
