// Compile and execute using:
//
//   gcc writer.c ../src/writer.c -o writer.bin && ./writer.bin

#include "../src/writer.h"

int main(int argc, char* argv[])
{
    FILE* file = fopen("wr.dat", "wb+");

    if (file == NULL)
    {
        return 1;
    }

    long unsigned int address = 0;

    char fixedString[12 + 1] = "John Fallout";
    char* string = "John Fallout";
    char* CURSEDstring = "John Fallout";

    printf("\n");

    bool r_writeFixedString = writeFixedString(file, fixedString, 12, &address, 0, true);
    printf("writeFixedString address  : %lu\n", address);

    bool r_writeString = writeString(file, &string, &address, 0, 0, true);
    printf("writeString address       : %lu\n", address);

    bool r_writeCURSEDString = writeCURSEDString(file, &CURSEDstring, &address, 0, 2, true);
    printf("writeCURSEDString address : %lu\n", address);

    printf("\n");

    printf("*******************\n");
    printf("* Writer API Test *\n");
    printf("*******************\n");

    printf("\n");

    printf("writeFixedString result  :   %s\n", r_writeFixedString ? ":)" : ":(");
    printf("writeString result       :   %s\n", r_writeString ? ":)" : ":(");
    printf("writeCURSEDString result :   %s\n", r_writeCURSEDString ? ":)" : ":(");

    printf("writeFixedString         : (%s)\n", fixedString);
    printf("writeString              : (%s)\n", string);
    printf("writeCURSEDString        : (%s)\n", CURSEDstring);

    printf("\n");

    return 0;
}
