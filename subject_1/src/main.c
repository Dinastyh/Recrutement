#include <stdio.h>
#include <stdlib.h>
#include "info_connection.h"

int main(int argc, char **argv)
{
    char parameters = 0;
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i],"-h") && !strcmp(argv[i],"--help"))
            parameters[0] = 1;
    }
  

    if (parameters)
    {
        printf("Usage: ./extract EML-FILE\n");
        return 1;
    }

    struct info_connection *info_connection = get_from_config_file();
}
