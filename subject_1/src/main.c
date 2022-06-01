#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database/info_connection.h"

int main(int argc, char **argv)
{
    char parameter = 0;
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i],"-h") && !strcmp(argv[i],"--help"))
            parameter = 1;
    }
  

    if (parameter || argc != 2)
    {
        printf("Usage: ./extract EML-FILE\n");
        return 1;
    }

    struct info_connection *info_connection = get_from_config_file();
	
	MYSQL *connection = connect_to_db(info_connection);

	return 0;
}

