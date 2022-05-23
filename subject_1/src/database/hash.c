#include <hash.h>

Sha sha;

void init_hash(void)
{
	wc_InitSha256(&sha);
}

char *hash_sha256(char *str)
{
	char *hash_str = calloc(SHA256_DIGEST_LENGTH, sizeof(char));
	wc_Sha256Update(&sha, str, strlen(str));
	wc_Sha256Final(&sha, hash_str);
	return hash_str;
}

void close_hash(void)
{
	wc_Sha256Free(&sha);
}
