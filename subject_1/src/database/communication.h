#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "../utils/info_connection.h"
#include <stdarg.h>

//@brief 
// Connect to MariaDB with info from config file

MYSQL *connect_to_db(struct info_connection* info);
<<<<<<< HEAD
MYSQL_STMT* prepare_statement(MYSQL *connection, char *query);
void exec_statement(MYSQL_STMT *statement, size_t nb_param, ...);

=======
void exec_statement(MYSQL_STMT *statement, size_t nb_param, ...);
MYSQL_STMT* prepare_statement(MYSQL *connection, char *query);
>>>>>>> 3ad9f3f (tqt)
#endif
