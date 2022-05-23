#include "communication.h"

#include <err.h>
#include <string.h>

MYSQL *connect_to_db(struct info_connection* info)
{
    MYSQL *connection = mysql_init(0);
    if (!connection)
	errx(3, "Fail to initialise the connection struct");
    
    if (!mysql_real_connect(
		connnection,
		info_connection->host,
		info_connection->user,
		info_connection->password,
		info_connection->port,
		NULL,
		0
		))
	errx(3, "Fail to connect to the data base %s", mysql_error(connection));

    return connection;
}

MYSQL_STMT* prepare_statement(MYSQL *connection, char *query)
{
	MYSQL_STMT *statement = mysql_stmt_init(connection);
	if (!statement)
		errx(3, "Fail to initialise the statement struct");

	if (mysql_stmt_prepare(statement, query, strlen(query)))
		errx(3, "Fail to prepare the statement %s", mysql_error(connection));

	return statement;
}

void execute_statement(MYSQL_STMT *statement)
{
}

void exec_statement(MYSQL_STMT *statement, size_t nb_param, ...)
{
	MYSQL_BIND *bind = calloc(nb_param, sizeof(MYSQL_BIND));
	va_list parameters;
	va_start(parameters, nb_param);
	for (size_t i = 0; i < nb_param; i++)
	{
		bind[i].buffer_type = MYSQL_TYPE_STRING;
		bind[i].buffer = va_arg(args, char*);
		bind[i].buffer_length = strlen(bind[i].buffer);
	}
	va_end(parameters);

	
	
	if (mysql_stmt_execute(statement))
		errx(3, "Fail to execute the statement %s", mysql_error(connection));

	if (mysql_stmt_execute(statement))
		errx(3, "Fail to execute the statement %s", mysql_error(connection));
	

}


