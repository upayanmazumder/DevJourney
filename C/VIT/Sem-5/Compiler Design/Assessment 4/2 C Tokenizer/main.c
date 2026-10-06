#include <ctype.h>
#include <stdio.h>

int main(void) {
  int c;
  while ((c = getchar()) != EOF) {
    if (isspace((unsigned char)c))
      continue;
    if (isalpha((unsigned char)c) || c == '_') {
      printf("IDENTIFIER: %c", c);
      while ((c = getchar()) != EOF && (isalnum((unsigned char)c) || c == '_'))
        putchar(c);
      if (c != EOF)
        ungetc(c, stdin);
      putchar('\n');
    } else if (isdigit((unsigned char)c)) {
      printf("NUMBER: %c", c);
      while ((c = getchar()) != EOF && isdigit((unsigned char)c))
        putchar(c);
      if (c == '.') {
        putchar(c);
        while ((c = getchar()) != EOF && isdigit((unsigned char)c))
          putchar(c);
      }
      if (c != EOF)
        ungetc(c, stdin);
      putchar('\n');
    } else {
      printf("SYMBOL: %c\n", c);
    }
  }
  return 0;
}
