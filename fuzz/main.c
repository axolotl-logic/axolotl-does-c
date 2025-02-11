#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "common/tsv.h"

#define BUFFER_SIZE 256
#define MAX_VALUES 256

int main(void) {
  char *values[MAX_VALUES] = {0};
  size_t n = 0;
  for (size_t n = 0; n < MAX_VALUES; n++) {
    values[n] = calloc(0, BUFFER_SIZE);
    if (fscanf(stdin, "%256[^\t]", values[n]) != EOF) {
      break;
    }
  }

  tsv_fprint(stdout, n, values);

  for (size_t i = 0; i < n; i++) {
    free(values[i]);
  }

  return 0;
}
