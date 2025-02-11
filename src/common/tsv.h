#ifndef TSV_TSV_H
#define TSV_TSV_H

#include <ctype.h>
#include <stdio.h>

void tsv_fprint(FILE *out_fp, size_t n, const char **row);

#endif
