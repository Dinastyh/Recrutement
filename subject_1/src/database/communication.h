#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include "info_connection.h"

//@brief 
// Connect to MariaDB with info from config file

MYSQL *connect_to_db(struct info_connection* info);

#endif
