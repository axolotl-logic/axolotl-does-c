#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "common/tsv.h"

#define BUFFER_SIZE 256
#define ROW_REALLOC_SIZE 256

int main(void)
{
	char **values = (char **)malloc(sizeof(*values) * ROW_REALLOC_SIZE);

	size_t values_len = 0;
	// Run until EOF, memory runs out, or heat death of universe
	while (true) {
		char **new_values = (char **)realloc(
			(void *)values,
			(sizeof(*values) * values_len) +
				(ROW_REALLOC_SIZE * sizeof(*values)));
		assert(new_values && "Out of memory");
		values = new_values;

		char *buffer = calloc(0, BUFFER_SIZE);
		if (values == NULL) {
			values = &buffer;
		} else {
			values[values_len] = buffer;
		}

		if (scanf("%256[^\t]", values[values_len]) <= 0) {
			break;
		}

		values_len++;
	}

	tsv_fprint(stdout, values_len, (const char **)values);

	for (size_t i = 0; i < values_len; i++) {
		free(values[i]);
	}

	return 0;
}
