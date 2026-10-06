#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>

int main(void) {
  char line[256], lhs, alternatives[16][64];
  int count = 0;
  if (!fgets(line, sizeof(line), stdin) || sscanf(line, " %c ->", &lhs) != 1) {
    fprintf(stderr, "Expected production: A -> abc | abd\n");
    return 1;
  }
  char *arrow = strstr(line, "->");
  if (!arrow)
    return 1;
  char *save, *alt = strtok_r(arrow + 2, "|\n", &save);
  while (alt && count < 16) {
    while (*alt == ' ' || *alt == '\t')
      alt++;
    size_t n = strlen(alt);
    while (n && (alt[n - 1] == ' ' || alt[n - 1] == '\t'))
      alt[--n] = '\0';
    strcpy(alternatives[count++], n ? alt : "#");
    alt = strtok_r(NULL, "|\n", &save);
  }
  if (count < 2) {
    fprintf(stderr, "Need at least two alternatives\n");
    return 1;
  }
  size_t prefix = strlen(alternatives[0]);
  for (int i = 1; i < count; i++) {
    size_t n = strlen(alternatives[i]);
    if (n < prefix)
      prefix = n;
    size_t j = 0;
    while (j < prefix && alternatives[0][j] == alternatives[i][j])
      j++;
    prefix = j;
  }
  if (!prefix) {
    fprintf(stderr, "No common prefix to factor\n");
    return 1;
  }
  printf("%c -> %.*s%c'\n%c' -> ", lhs, (int)prefix, alternatives[0], lhs, lhs);
  for (int i = 0; i < count; i++)
    printf("%s%s", alternatives[i][prefix] ? alternatives[i] + prefix : "#",
           i + 1 < count ? " | " : "\n");
  return 0;
}
