#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>

int main(void) {
  char line[256], lhs, alpha[16][64], beta[16][64];
  int na = 0, nb = 0;
  if (!fgets(line, sizeof(line), stdin) ||
      sscanf(line, " %c ->", &lhs) != 1) {
    fprintf(stderr, "Expected production: A -> Aa | b\n");
    return 1;
  }
  char *arrow = strstr(line, "->");
  if (!arrow) return 1;
  char *save, *alt = strtok_r(arrow + 2, "|\n", &save);
  while (alt) {
    while (*alt == ' ' || *alt == '\t') alt++;
    size_t n = strlen(alt);
    while (n && (alt[n - 1] == ' ' || alt[n - 1] == '\t')) alt[--n] = '\0';
    if (!n) strcpy(beta[nb++], "#");
    else if (alt[0] == lhs) {
      if (!alt[1]) { fprintf(stderr, "Production A -> A cannot be eliminated\n"); return 1; }
      strcpy(alpha[na++], alt + 1);
    } else strcpy(beta[nb++], alt);
    alt = strtok_r(NULL, "|\n", &save);
  }
  if (!na) { printf("No immediate left recursion\n"); return 0; }
  if (!nb) { fprintf(stderr, "No non-recursive alternative\n"); return 1; }
  printf("%c -> ", lhs);
  for (int i = 0; i < nb; i++) printf("%s%c' %s", beta[i], lhs, i + 1 < nb ? "| " : "\n");
  printf("%c' -> ", lhs);
  for (int i = 0; i < na; i++) printf("%s%c' %s", alpha[i], lhs, i + 1 < na ? "| " : "| #\n");
  return 0;
}
