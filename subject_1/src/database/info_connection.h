#ifndef INFO_CONNECTION_H
#define INFO_CONNECTION_H

#include <stddef.h>

//@brief
// Structure containing all information about the db connection

struct info_connection {
    char *host;
    char *user;
    char *password;
    char *default_database;
    size_t port;
};


struct info_connection *info_connection_new(char *host, char *user, char *password, char *default_database, size_t port);
void info_connection_free(struct info_connection *info_connection);
struct info_connection *get_from_config_file(void);

#endif
