#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *p;
static char stack[512];
static int top = -1;
static void reduce(void) {
  if (top >= 0 && stack[top] == 'i') {
    stack[top] = 'E';
    return;
  }
  if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '+' &&
      stack[top - 2] == 'E') {
    top -= 2;
    stack[top] = 'E';
    return;
  }
  if (top >= 2 && stack[top] == 'E' && stack[top - 1] == '*' &&
      stack[top - 2] == 'E') {
    top -= 2;
    stack[top] = 'E';
    return;
  }
  if (top >= 2 && stack[top] == ')' && stack[top - 1] == 'E' &&
      stack[top - 2] == '(') {
    top -= 2;
    stack[top] = 'E';
  }
}
static void spaces(void) {
  while (isspace((unsigned char)*p))
    p++;
}
int main(void) {
  char line[512];
  if (!fgets(line, sizeof(line), stdin))
    return 1;
  p = line;
  while (1) {
    spaces();
    if (!*p || *p == '\n')
      break;
    if (isdigit((unsigned char)*p)) {
      while (isdigit((unsigned char)*p))
        p++;
      stack[++top] = 'i';
    } else if (strchr("()+*", *p))
      stack[++top] = *p++;
    else {
      puts("Rejected");
      return 1;
    }
    if (top >= (int)sizeof(stack) - 1) {
      puts("Rejected");
      return 1;
    }
    reduce();
  }
  while (top >= 0 && (stack[top] == ')' || stack[top] == 'E')) {
    int before = top;
    reduce();
    if (before == top)
      break;
  }
  if (top == 0 && stack[0] == 'E')
    puts("Accepted");
  else {
    puts("Rejected");
    return 1;
  }
  return 0;
}
