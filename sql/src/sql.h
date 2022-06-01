#ifndef SQL_H
#define SQL_H

#include <stddef.h>
#include <mysql/mysql.h>

MYSQL_STMT *sql_prepare_stmt(MYSQL *mysql, const char *query);
void sql_exec_insert_stmt(MYSQL_STMT *stmt, size_t number, ...);

#endif
