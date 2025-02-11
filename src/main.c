#include "common/tsv.h"

#include <stdio.h>

int main(void) {
  FILE *out_fp = stdout;
  tsv_fprint(out_fp, 2, (const char *[]){"Hello", "World"});
}
