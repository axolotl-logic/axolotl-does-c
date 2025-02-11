#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "common/tsv.h"

void redirect_stdout(void) {
  setbuf(stdout, NULL);
  cr_redirect_stdout();
}

Test(tsv, tsv_fprint, .init = redirect_stdout, .timeout = 1) {
  FILE *out_fp = stdout;

  tsv_fprint(out_fp, 2, (const char *[]){"Hello", "World"});

  cr_assert_stdout_eq_str("Hello\tWorld\n");
}
