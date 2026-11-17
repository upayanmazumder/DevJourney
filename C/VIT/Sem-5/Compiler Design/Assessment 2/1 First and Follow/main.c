#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_PROD 25
#define MAX_TOKENS 10
#define MAX_LEN 10

char lhs[MAX_PROD][MAX_LEN];
char rhs[MAX_PROD][MAX_TOKENS][MAX_LEN];
int rhs_count[MAX_PROD];
int num_productions;

char first_set[MAX_PROD * 2][MAX_LEN];
char follow_set[MAX_PROD * 2][MAX_LEN];
int first_ptr = 0, follow_ptr = 0;

// Array to track recursion depth and prevent infinite loops in FOLLOW
int follow_visited[MAX_PROD];

int is_non_terminal(char *str) {
    return isupper((unsigned char)str[0]);
}

void add_to_first(char *val) {
    for (int i = 0; i < first_ptr; i++) {
        if (strcmp(first_set[i], val) == 0)
            return;
    }
    strcpy(first_set[first_ptr++], val);
}

void add_to_follow(char *val) {
    for (int i = 0; i < follow_ptr; i++) {
        if (strcmp(follow_set[i], val) == 0)
            return;
    }
    strcpy(follow_set[follow_ptr++], val);
}

void find_first(char *symbol) {
    if (!is_non_terminal(symbol)) {
        add_to_first(symbol);
        return;
    }

    for (int i = 0; i < num_productions; i++) {
        if (strcmp(lhs[i], symbol) == 0) {
            if (strcmp(rhs[i][0], " # ") == 0) {
                add_to_first(" # ");
            } else {
                int j = 0;
                while (j < rhs_count[i]) {
                    int current_first_ptr = first_ptr;
                    find_first(rhs[i][j]);

                    int has_epsilon = 0;
                    for (int temp = current_first_ptr; temp < first_ptr; temp++) {
                        if (strcmp(first_set[temp], " # ") == 0) {
                            has_epsilon = 1;
                        }
                    }

                    if (!has_epsilon) {
                        break;
                    }
                    j++;
                }
            }
        }
    }
}

void find_follow(char *symbol) {
    for (int i = 0; i < num_productions; i++) {
        if (strcmp(lhs[i], symbol) == 0) {
            if (follow_visited[i])
                return;
            follow_visited[i] = 1;
        }
    }

    // Rule 1: The start symbol gets '$'
    if (strcmp(lhs[0], symbol) == 0) {
        add_to_follow(" $ ");
    }

    for (int i = 0; i < num_productions; i++) {
        for (int j = 0; j < rhs_count[i]; j++) {
            if (strcmp(rhs[i][j], symbol) == 0) {

                int k = j + 1;
                int carry_on = 1;

                while (k < rhs_count[i] && carry_on) {
                    char *next_sym = rhs[i][k];

                    if (!is_non_terminal(next_sym)) {
                        add_to_follow(next_sym);
                        carry_on = 0;
                    } else {
                        // Store existing first pointer state before switching execution
                        // contexts
                        int saved_first_ptr = first_ptr;
                        first_ptr = 0;

                        find_first(next_sym);

                        int has_epsilon = 0;
                        for (int temp = 0; temp < first_ptr; temp++) {
                            if (strcmp(first_set[temp], " # ") != 0) {
                                add_to_follow(first_set[temp]);
                            } else {
                                has_epsilon = 1;
                            }
                        }
                        first_ptr = saved_first_ptr; // Restore

                        if (!has_epsilon) {
                            carry_on = 0;
                        }
                    }
                    k++;
                }

                if (carry_on && strcmp(symbol, lhs[i]) != 0) {
                    find_follow(lhs[i]);
                }
            }
        }
    }
}

int main() {
    printf(" Enter number of productions : ");
    if (scanf("%d", &num_productions) != 1)
        return 1;

    printf(" Enter productions using ' -> ' or ' = '\n");
    printf("           (e.g., E -> T E ' or E ' = #) :\n ");

    char line[100];
    fgets(line, sizeof(line), stdin); // Flush buffer

    char unique_nt[MAX_PROD][MAX_LEN];
    int unique_count = 0;

    for (int i = 0; i < num_productions; i++) {
        fgets(line, sizeof(line), stdin);

        char *token = strtok(line, " \t\n ");
        if (token == NULL)
            continue;

        strcpy(lhs[i], token);

        // Track unique non-terminals to print all answers cleanly at the end
        int found = 0;
        for (int u = 0; u < unique_count; u++) {
            if (strcmp(unique_nt[u], token) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(unique_nt[unique_count++], token);
        }

        token = strtok(NULL, " \t\n");
        if (token != NULL && (strcmp(token, "->") == 0 || strcmp(token, "=") == 0)) {
            token = strtok(NULL, " \t\n");
        }

        int r_idx = 0;
        while (token != NULL) {
            strcpy(rhs[i][r_idx++], token);
            token = strtok(NULL, " \t\n ");
        }
        rhs_count[i] = r_idx;
    }

    printf("\n ================================================ COMPUTED RESULTS "
           "================================================\n ");

    for (int u = 0; u < unique_count; u++) {
        // Compute FIRST Set
        first_ptr = 0;
        find_first(unique_nt[u]);
        printf(" FIRST(%s) = {", unique_nt[u]);
        for (int i = 0; i < first_ptr; i++)
            printf(" %s ", first_set[i]);
        printf("}\n ");

        // Compute FOLLOW Set
        follow_ptr = 0;
        memset(follow_visited, 0, sizeof(follow_visited));
        find_follow(unique_nt[u]);
        printf(" FOLLOW(%s) = {", unique_nt[u]);
        for (int i = 0; i < follow_ptr; i++)
            printf(" %s ", follow_set[i]);
        printf("}\n\n ");
    }
    printf("\n           ========================================\n ");

    return 0;
}
