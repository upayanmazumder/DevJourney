#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char input[512];
static size_t pos;
static int temp_no;
static void skip_space(void) { while (isspace((unsigned char)input[pos])) pos++; }
static char *expression(void);
static char *new_temp(void) {
  char name[32]; snprintf(name, sizeof(name), "t%d", ++temp_no);
  char *result = malloc(strlen(name) + 1);
  if (!result) exit(1);
  strcpy(result, name); return result;
}
static char *factor(void) {
  skip_space();
  if (input[pos] == '(') {
    pos++; char *v = expression(); skip_space();
    if (input[pos] != ')') { fprintf(stderr, "Invalid expression\n"); exit(1); }
    pos++; return v;
  }
  size_t start = pos;
  if (isalpha((unsigned char)input[pos]) || input[pos] == '_') {
    pos++; while (isalnum((unsigned char)input[pos]) || input[pos] == '_') pos++;
  } else if (isdigit((unsigned char)input[pos])) {
    pos++; while (isdigit((unsigned char)input[pos]) || input[pos] == '.') pos++;
  } else { fprintf(stderr, "Invalid expression\n"); exit(1); }
  size_t n = pos - start;
  char *v = malloc(n + 1);
  if (!v)
    exit(1);
  memcpy(v, input + start, n);
  v[n] = '\0';
  return v;
}
static char *combine(char *left, char op, char *right) {
  char *t = new_temp(); printf("%s = %s %c %s\n", t, left, op, right); return t;
}
static char *term(void) {
  char *v = factor();
  for (;;) { skip_space(); char op = input[pos]; if (op != '*' && op != '/') break; pos++; v = combine(v, op, factor()); }
  return v;
}
static char *expression(void) {
  char *v = term();
  for (;;) { skip_space(); char op = input[pos]; if (op != '+' && op != '-') break; pos++; v = combine(v, op, term()); }
  return v;
}
int main(void) {
  if (!fgets(input, sizeof(input), stdin)) return 1;
  char *result = expression(); skip_space();
  if (input[pos] != '\0' && input[pos] != '\n') { fprintf(stderr, "Invalid expression\n"); return 1; }
  printf("Result = %s\n", result); return 0;
}
