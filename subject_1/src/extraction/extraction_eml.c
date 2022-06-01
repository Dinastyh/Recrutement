#include "extraction_eml.h"

#include <regex.h>
#include "../utils/xalloc.h"
#include <err.h>

static struct extracted_data *extract_data_new(char *match, struct extracted_data *prev)
{
<<<<<<< HEAD
<<<<<<< HEAD
	struct extracted_data *extacted = xcalloc(1, sizeof(struct extracted_data));
	return extracted;
=======
=======
>>>>>>> 3ad9f3f (tqt)
	struct extracted_data *data = xcalloc(1, sizeof(struct extracted_data));
	data->match = match;
	if (prev)
		prev->next = data;
	return data;
}

void free_extracted_data(struct extracted_data *data)
{
	struct extracted_data *next;
	while (data) {
		next = data->next;
		free(data->match);
		free(data);
		data = next;
	}
}

struct extracted_data *extract_data(char *regex_str, char *data)
{
	struct extracted_data *extracted = xcalloc(1, sizeof(struct extracted_data));
	struct extracted_data *out = extracted;

	regex_t regex;
	if (regcomp(&regex, regex_str, REG_EXTENDED | REG_NOSUB) != 0) {
		errx(4, "Regcomp failed");
	}

	char *current = data;

	int check = 0;
	while (!check)
	{
		regmatch_t match;
		check = regexec(&regex, current, 1, &match, 0);

		if (check == 0)
		{
			char *match_str = xcalloc(match.rm_eo - match.rm_so + 1, sizeof(char));
			strncpy(match_str, current + match.rm_so, match.rm_eo - match.rm_so);
			match_str[match.rm_eo - match.rm_so] = '\0';
			extracted = extract_data_new(match_str, extracted);
			current += match.rm_eo;
		}
	}

	regfree(&regex);
	return out;
<<<<<<< HEAD
>>>>>>> 3ad9f3f (tqt)
=======
>>>>>>> 3ad9f3f (tqt)
}


