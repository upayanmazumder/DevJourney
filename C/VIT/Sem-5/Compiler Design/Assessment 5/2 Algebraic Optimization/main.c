#include <stdio.h>
#include <string.h>

int main(void) {
  char line[256], dest[64], left[64], right[64], op, extra;
  while (fgets(line, sizeof(line), stdin)) {
    if (sscanf(line, " %63s = %63s %c %63s %c", dest, left, &op, right,
               &extra) == 4) {
      int optimized = 0;
      if (op == '+' && !strcmp(right, "0")) {
        printf("%s = %s\n", dest, left);
        optimized = 1;
      } else if (op == '+' && !strcmp(left, "0")) {
        printf("%s = %s\n", dest, right);
        optimized = 1;
      } else if (op == '-' && !strcmp(right, "0")) {
        printf("%s = %s\n", dest, left);
        optimized = 1;
      } else if (op == '*' && (!strcmp(right, "1") || !strcmp(left, "1"))) {
        printf("%s = %s\n", dest, !strcmp(left, "1") ? right : left);
        optimized = 1;
      } else if (op == '*' && (!strcmp(right, "0") || !strcmp(left, "0"))) {
        printf("%s = 0\n", dest);
        optimized = 1;
      } else if (op == '/' && !strcmp(right, "1")) {
        printf("%s = %s\n", dest, left);
        optimized = 1;
      }
      if (!optimized)
        printf("%s = %s %c %s\n", dest, left, op, right);
    } else if (sscanf(line, " %63s = %63s %c", dest, left, &op) == 3) {
      printf("%s = %s %c\n", dest, left, op);
    } else
      fputs(line, stdout);
  }
  return 0;
}
