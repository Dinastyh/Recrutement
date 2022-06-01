#ifndef HASH_H
#define HASH_H

#include <wolfssl/wolfcrypt/sha256.h>

void init_hash(void);
char *hash_sha256(char *str);
void close_hash(void)

#endif
