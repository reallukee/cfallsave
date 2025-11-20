// Compile and execute using:
//
//   gcc reader.c ../src/reader.c -o reader.out && ./reader.out

#include "../src/reader.h"

int main(int argc, const char* argv[])
{
    FILE* file = fopen("wr.dat", "rb+");

    if (file == NULL)
    {
        return 1;
    }

    long unsigned int address = 0;

    char fixedString[12 + 1];
    char* string = NULL;
    char* CURSEDstring = NULL;

    printf("\n");

    bool r_readFixedString = readFixedString(file, fixedString, 12, &address, 0, true);
    printf("readFixedString address  : %lu\n", address);

    bool r_readString = readString(file, &string, &address, 0, 0, true);
    printf("readString address       : %lu\n", address);

    bool r_readCURSEDString = readCURSEDString(file, &CURSEDstring, &address, 0, 2, true);
    printf("readCURSEDString address : %lu\n", address);

    printf("\n");

    printf("*******************\n");
    printf("* Reader API Test *\n");
    printf("*******************\n");

    printf("\n");

    printf("readFixedString result  :   %s\n", r_readFixedString ? ":)" : ":(");
    printf("readString result       :   %s\n", r_readString ? ":)" : ":(");
    printf("readCURSEDString result :   %s\n", r_readCURSEDString ? ":)" : ":(");

    printf("readFixedString         : (%s)\n", fixedString);
    printf("readString              : (%s)\n", string);
    printf("readCURSEDString        : (%s)\n", CURSEDstring);

    printf("\n");

    return 0;
}
