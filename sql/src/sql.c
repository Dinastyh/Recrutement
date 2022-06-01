#include "sql.h"

MYSQL_STMT* prepare_statement(MYSQL *connection, char *query)
{
	MYSQL_STMT *statement = mysql_stmt_init(connection);
	if (!statement)
		errx(3, "Fail to initialise the statement struct");

	if (mysql_stmt_prepare(statement, query, strlen(query)))
		errx(3, "Fail to prepare the statement %s", mysql_error(connection));

	return statement;
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

	if (mysql_stmt_bind_param(statement, bind))
		errx(3, "Fail to bind the parameters %s", mysql_error(connection));

	if (mysql_stmt_execute(statement))
		errx(3, "Fail to execute the statement %s", mysql_error(connection));
	
	mysql_stmt_close(statement);
	free(bind);
}
