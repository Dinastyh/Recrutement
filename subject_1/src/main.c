#include <stdio.h>
#include <stdlib.h>
#include "info_connection.h"

int main(int argc, char **argv)
{
    char parameters[2] = { 0 };
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i],"-h") && !strcmp(argv[i],"--help"))
            parameters[0] = 1;
        else if (!strcmp(argv[i],"-c") || !strcmp(argv[i],"--config"))
            parameters[1] = 1;
    }
  

    if (parameters[0])
    {
        printf("Usage: ./extract <-h | --help> <-c | --config> <-s | --setup> EML-FILE\n");
        printf("- Help: Display information about bin\n");
        printf("- Config: Use the config.toml file to connect on the data base\n");
        return 1;
    }

    struct info_connection *info_connection;

    if (parameters[1])
    {
        info_connection;
    }
    else
    {
    }
}