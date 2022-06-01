#ifndef PROCESS_H

#include "info_connection.h"

void send_SHA256_hash(MYSQL *connection, char *txt, struct info_connection *info);
#endif // PROCESS_H
