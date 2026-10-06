#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

static const char *input;
static int error;
static void spaces(void) {
  while (isspace((unsigned char)*input))
    input++;
}
static double expression(void);
static double factor(void) {
  spaces();
  if (*input == '(') {
    input++;
    double v = expression();
    spaces();
    if (*input != ')')
      error = 1;
    else
      input++;
    return v;
  }
  char *end;
  double v = strtod(input, &end);
  if (end == input) {
    error = 1;
    return 0;
  }
  input = end;
  return v;
}
static double term(void) {
  double v = factor();
  for (;;) {
    spaces();
    char op = *input;
    if (op != '*' && op != '/')
      break;
    input++;
    double r = factor();
    if (op == '*')
      v *= r;
    else if (r == 0)
      error = 1;
    else
      v /= r;
  }
  return v;
}
static double expression(void) {
  spaces();
  int sign = 1;
  while (*input == '+' || *input == '-') {
    if (*input++ == '-')
      sign = -sign;
    spaces();
  }
  double v = sign * term();
  for (;;) {
    spaces();
    char op = *input;
    if (op != '+' && op != '-')
      break;
    input++;
    double r = term();
    v = op == '+' ? v + r : v - r;
  }
  return v;
}
int main(void) {
  char line[512];
  if (!fgets(line, sizeof(line), stdin))
    return 1;
  input = line;
  double value = expression();
  spaces();
  if (error || *input) {
    puts("Invalid expression");
    return 1;
  }
  printf("Result = %.6g\n", value);
  return 0;
}
