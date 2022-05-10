#include "info_connection.h"

#include "xalloc.h"
#include "stdio.h"
#include "toml.h"

struct info_connection *info_connection_new(char *host, char *user, char *password, char *default_database, size_t port)
{
    struct info_connection *info_connection = xcalloc(1, sizeof(struct info_connection));

    info_connection->host = xstring(host);
    info_connection->user = xstring(user);
    info_connection->password = xstring(password);
    info_connection->default_database = xstring(default_database);
    info_connection->port = port;
    return info_connection;
}

void info_connection_free(struct info_connection *info_connection)
{
    free(info_connection->host);
    free(info_connection->user);
    free(info_connection->password);
    free(info_connection->default_database);
    free(info_connection);
}

struct info_connection *get_from_config_file(void)
{
    FILE *config_file;
    char errbuf[1024];

    config_file = fopen("config.toml", "r");
    if (!config_file)
    {
        errx(2, "Fail to open config.toml file\n");
    }

    toml_table_t* conf = toml_parse_file(config_file, errbuf, sizeof(errbuf));
    fclose(config_file);

    if (!conf)
        errx(3, "Fail to parse config file: %s\n", errbuf);

    toml_table_t* db = toml_table_in(conf, "DataBase");
    if (!db)
        errx(3, "Missing [DataBase] field in config file");
    
}
