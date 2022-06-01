#include "info_connection.h"

#include "../utils/xalloc.h"
#include <stdio.h>
#include "../utils/toml.h"


static void gen_default_conf(void);

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
    //Check existence of config.toml 
    FILE *config_file = fopen("config.toml", "r");
    if (!config_file)
    {
        warn("Fail to open config.toml file\n");
	gen_default_conf();
	errx(2, "Default configuration generated");
    }

    //Read config file
    char errbuf[1024];

    toml_table_t* conf = toml_parse_file(config_file, errbuf, sizeof(errbuf));
    fclose(config_file);

    if (!conf)
        errx(3, "Fail to parse config file: %s\n", errbuf);

    toml_table_t* db = toml_table_in(conf, "DataBase");
    if (!db)
        errx(3, "Missing [DataBase] field in config file");
    
    //Extract value

    toml_datum_t host = toml_string_in(db, "host");
    if (!host.ok)
    {
	errx(3, "Missing host field in config file");
    }

    toml_datum_t user = toml_string_in(db, "user");
    if (!user.ok)
    {
	errx(3, "Missing user field in config file");
    }

    toml_datum_t password = toml_string_in(db, "password");
    if (!password.ok)
    {
	errx(3, "Missing password field in config file");
    }

     toml_datum_t default_database = toml_string_in(db, "default_database");
    if (!default_database.ok)
    {
	errx(3, "Missing default_database field in config file");
    }

    toml_datum_t port = toml_int_in(db, "port");
    if (!port.ok)
    {
	errx(3, "Missing port field in config file");
    }

    struct info_connection *info = info_connection_new(host.u.s, user.u.s, password.u.s, default_database.u.s, port.u.i);
    toml_free(conf);
    fclose(config_file);

    return info;
}

static void gen_default_conf(void)
{
    FILE * file = fopen("config.toml", "w");

    if (!file)
	errx(2, "Fail to generate default config in config.toml\n");

    char default_config[] = "[DataBase]\nhost = localhost\nuser = db_user\npassword = db_user_password\ndefault_database = db_default\nport = 3306\n";

    size_t size = fwrite(default_config, 1, sizeof(default_config), file);
    if (size != sizeof(default_config))
	errx(2, "Fail to generate default config in config.toml\n");
    fclose(file);
}

