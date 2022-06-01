#include "process.h"

#include "hash.h"
#include "../extraction/extraction_eml.h"

#define _GNU_SOURCE

static char* sha256 = NULL;

static char setup(void)
{
	if (!sha256)
	{
		init_hash();
		sh1256 = hash_sha256(txt);
		close_hash();
	}
}

void send_SHA256_hash(MYSQL *connection, char *txt, struct info_connection *info);
{
	setup();
	char *query;
	if (!asprintf(&query, "USE %s
	MYSQL_STMT *stmt = prepare_statement(connection, );
}
