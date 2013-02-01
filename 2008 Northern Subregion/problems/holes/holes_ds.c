#include <stdio.h>
#include <process.h>

FILE* out;

void error (const char* s) {
  fprintf (stderr, "Error: %s\n", s);
  if (out) fclose (out);
  exit (1);
}

int main () {
  FILE* in = fopen ("holes.in", "rt");
  int n;

  out = NULL;
  if (!in) error ("Cannot open input file");

  out = fopen ("holes.out", "wt");
  if (fscanf (in, "%d\n", &n) != 1) error ("Incorrect input number");
  if (fgetc (in) != -1) error ("File contains extra symbols");
  if (n < 0 || n > 510) error ("n not in [0..510]");

  switch (n) {
    case 0: fprintf (out, "1\n"); break;
    case 1: fprintf (out, "0\n"); break;
    default: 
      if (n % 2 == 1) fprintf (out, "4");
      for (; n > 1; n -= 2) fprintf (out, "8");
      fprintf (out, "\n");
  }

  fclose (in);
  fclose (out);
  return 0;
}
