#include "tsv.h"

#include <stdbool.h>
#include <stdio.h>

void tsv_fprint(FILE *out_fp, size_t n, const char **values) {
  bool first = true;
  for (size_t i = 0; i < n; i++) {
    if (!first) {
      fprintf(out_fp, "\t");
    } else {
      first = false;
    }

    const char *value = values[i];
    fprintf(out_fp, "%s", value);
  }

  // Conclude with a newline.
  fprintf(out_fp, "\n");
}
