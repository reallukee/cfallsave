#include "cli.hpp"

#include "commands.hpp"

void commandLineArgs(int argc, char* argv[])
{
    if (argc == 1)
    {
        help();

        return;
    }

    if (strcmp(argv[1], "help") == 0 && argc > 1)
    {
        help();
    }

    if (strcmp(argv[1], "about") == 0 && argc > 1)
    {
        about();
    }

    if (strcmp(argv[1], "create-sample-saves") == 0 && argc > 1)
    {
        createSampleSaves();
    }

    if (strcmp(argv[1], "read-fo1") == 0 && argc > 2)
    {
        readFO1(argv[2]);
    }

    if (strcmp(argv[1], "read-fo2") == 0 && argc > 2)
    {
        readFO2(argv[2]);
    }

    if (strcmp(argv[1], "read-fotbos") == 0 && argc > 2)
    {
        readFOTBOS(argv[2]);
    }

    if (strcmp(argv[1], "read-fo3") == 0 && argc > 2)
    {
        readFO3(argv[2]);
    }

    if (strcmp(argv[1], "read-fonv") == 0 && argc > 2)
    {
        readFONV(argv[2]);
    }

    if (strcmp(argv[1], "read-fo4") == 0 && argc > 2)
    {
        readFO4(argv[2]);
    }
}

void about()
{
    printf("\n");

    printf("********************\n");
    printf("* CFallSave++ Test *\n");
    printf("*      v%s      *\n", CFALLSAVEPP_VERSION_S);
    printf("********************\n");

    printf("\n");
}

void help()
{
    printf("\n");

    printf("./test++ <Command> <Args...>\n");

    printf("\n");

    printf(" - help\n");
    printf(" - about\n");

    printf("\n");

    printf(" - create-sample-saves\n");
    printf(" - read-fo1 <Save>\n");
    printf(" - read-fo2 <Save>\n");
    printf(" - read-fotbos <Save>\n");
    printf(" - read-fo3 <Save>\n");
    printf(" - read-fonv <Save>\n");
    printf(" - read-fo4 <Save>\n");

    printf("\n");
}
