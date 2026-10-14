#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int number(const char *text, long long *value) {
    char *end;
    errno = 0;
    *value = strtoll(text, &end, 10);
    return !errno && end != text && *end == '\0';
}

int main(void) {
    const char *lines[] = {"t1 = 4 + 6", "t2 = x + 0", "t3 = 1 * y",
                           "t4 = 8 / 2", "t5 = 5 / 0", "t6 = a * b"};
    char line[256], dest[64], left[64], right[64], op, extra;
    puts("Original code:");
    for (size_t i = 0; i < sizeof(lines) / sizeof(lines[0]); i++)
        puts(lines[i]);
    puts("\nOptimized code:");
    for (size_t i = 0; i < sizeof(lines) / sizeof(lines[0]); i++) {
        snprintf(line, sizeof(line), "%s\n", lines[i]);
        long long a, b, result;
        if (sscanf(line, " %63s = %63s %c %63s %c", dest, left, &op, right, &extra) != 4) {
            fputs(line, stdout);
            continue;
        }

        if (number(left, &a) && number(right, &b)) {
            int valid = 1;
            switch (op) {
            case '+':
                valid = !__builtin_add_overflow(a, b, &result);
                break;
            case '-':
                valid = !__builtin_sub_overflow(a, b, &result);
                break;
            case '*':
                valid = !__builtin_mul_overflow(a, b, &result);
                break;
            case '/':
                valid = b != 0 && !(a == (-9223372036854775807LL - 1) && b == -1);
                if (valid)
                    result = a / b;
                break;
            default:
                valid = 0;
            }
            if (valid) {
                printf("%s = %lld\n", dest, result);
                continue;
            }
        }

        const char *replacement = NULL;
        if (op == '+' && !strcmp(right, "0"))
            replacement = left;
        if (op == '+' && !strcmp(left, "0"))
            replacement = right;
        if (op == '-' && !strcmp(right, "0"))
            replacement = left;
        if (op == '*' && !strcmp(right, "1"))
            replacement = left;
        if (op == '*' && !strcmp(left, "1"))
            replacement = right;
        if (op == '/' && !strcmp(right, "1"))
            replacement = left;
        if (replacement)
            printf("%s = %s\n", dest, replacement);
        else
            printf("%s = %s %c %s\n", dest, left, op, right);
    }
    return 0;
}
