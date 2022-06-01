#ifndef EXTRACTION_EML_H
#define EXTRACTION_EML_H

struct extracted_data
{
	char *match;
	struct extracted_data *next;
};

struct extracted_data *extract_data(char *regex, char *data);
void free_extracted_data(struct extracted_data *data);

#endif
