#include <stdio.h>
#include <string.h>

#define MAX_EXPR 256
typedef struct { char left[64], right[64], op, result[64]; } Expression;
static Expression expressions[MAX_EXPR];
static int count;
static int same(const Expression *e, const char *a, char op, const char *b) {
  if (e->op == op && !strcmp(e->left, a) && !strcmp(e->right, b)) return 1;
  return (op == '+' || op == '*') && e->op == op &&
         !strcmp(e->left, b) && !strcmp(e->right, a);
}
static void invalidate(const char *name) {
  for (int i = 0; i < count;) {
    if (!strcmp(expressions[i].left, name) || !strcmp(expressions[i].right, name) ||
        !strcmp(expressions[i].result, name)) {
      expressions[i] = expressions[--count];
    } else i++;
  }
}
int main(void) {
  char line[256], dest[64], left[64], right[64], op, extra;
  while (fgets(line, sizeof(line), stdin)) {
    if (sscanf(line, " %63s = %63s %c %63s %c", dest, left, &op, right, &extra) == 4) {
      int found = -1;
      for (int i = 0; i < count; i++) {
        if (same(&expressions[i], left, op, right)) { found = i; break; }
      }
      char prior_result[64] = "";
      if (found >= 0) snprintf(prior_result, sizeof(prior_result), "%s", expressions[found].result);
      invalidate(dest);
      if (found >= 0) printf("%s = %s\n", dest, prior_result);
      else {
        printf("%s = %s %c %s\n", dest, left, op, right);
        if (count < MAX_EXPR) {
          Expression *e = &expressions[count++];
          snprintf(e->left, sizeof(e->left), "%s", left);
          snprintf(e->right, sizeof(e->right), "%s", right);
          snprintf(e->result, sizeof(e->result), "%s", dest); e->op = op;
        }
      }
    } else if (sscanf(line, " %63s = %63s", dest, left) == 2) {
      invalidate(dest); printf("%s = %s\n", dest, left);
    } else fputs(line, stdout);
  }
  return 0;
}
