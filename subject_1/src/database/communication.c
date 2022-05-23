#include "communication.h"

#include <err.h>

MYSQL *connect_to_db(struct info_connection* info)
{
    MYSQL *connection = mysql_init(0);
    if (!connection)
	errx(3, "Fail to initialise the connection struct");
    
    if (!mysql_read_connect(
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
