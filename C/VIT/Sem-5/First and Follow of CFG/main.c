#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 50
#define MAX_SYM 10
#define MAX_NAME 10

char head[MAX_RULES][MAX_NAME];
char body[MAX_RULES][MAX_SYM][MAX_NAME];
int bodyLen[MAX_RULES];
int total = 0;

char firstTab[MAX_RULES * 2][MAX_NAME];
char followTab[MAX_RULES * 2][MAX_NAME];
int firstLen = 0, followLen = 0;

int visited[MAX_RULES];

int isNT(const char *s) {
    return isupper((unsigned char)s[0]);
}

void pushFirst(const char *v) {
    for (int i = 0; i < firstLen; i++)
        if (strcmp(firstTab[i], v) == 0)
            return;
    strcpy(firstTab[firstLen++], v);
}

void pushFollow(const char *v) {
    for (int i = 0; i < followLen; i++)
        if (strcmp(followTab[i], v) == 0)
            return;
    strcpy(followTab[followLen++], v);
}

void computeFirst(const char *sym) {
    if (!isNT(sym)) {
        pushFirst(sym);
        return;
    }

    for (int i = 0; i < total; i++) {
        if (strcmp(head[i], sym) != 0)
            continue;

        if (strcmp(body[i][0], "#") == 0) {
            pushFirst("#");
            continue;
        }

        int j = 0;
        while (j < bodyLen[i]) {
            int mark = firstLen;
            computeFirst(body[i][j]);

            int eps = 0;
            for (int t = mark; t < firstLen; t++)
                if (strcmp(firstTab[t], "#") == 0)
                    eps = 1;

            if (!eps)
                break;
            j++;
        }
    }
}

void computeFollow(const char *sym) {
    for (int i = 0; i < total; i++) {
        if (strcmp(head[i], sym) == 0) {
            if (visited[i])
                return;
            visited[i] = 1;
        }
    }

    if (strcmp(head[0], sym) == 0)
        pushFollow("$");

    for (int i = 0; i < total; i++) {
        for (int j = 0; j < bodyLen[i]; j++) {
            if (strcmp(body[i][j], sym) != 0)
                continue;

            int k = j + 1;
            int cont = 1;

            while (k < bodyLen[i] && cont) {
                char *nxt = body[i][k];

                if (!isNT(nxt)) {
                    pushFollow(nxt);
                    cont = 0;
                } else {
                    int saved = firstLen;
                    firstLen = 0;

                    computeFirst(nxt);

                    int eps = 0;
                    for (int t = 0; t < firstLen; t++) {
                        if (strcmp(firstTab[t], "#") != 0)
                            pushFollow(firstTab[t]);
                        else
                            eps = 1;
                    }
                    firstLen = saved;

                    if (!eps)
                        cont = 0;
                }
                k++;
            }

            if (cont && strcmp(sym, head[i]) != 0)
                computeFollow(head[i]);
        }
    }
}

int main() {
    int lineCount;
    printf("Enter number of productions: ");
    if (scanf("%d", &lineCount) != 1)
        return 1;

    printf("Enter productions using '->' or '=' (e.g., E -> T E' or E' = #):\n");

    char line[200];
    fgets(line, sizeof(line), stdin);

    char uniq[MAX_RULES][MAX_NAME];
    int uniqCount = 0;

    for (int i = 0; i < lineCount; i++) {
        fgets(line, sizeof(line), stdin);

        char *tok = strtok(line, " \t\n");
        if (tok == NULL)
            continue;

        char lhsName[MAX_NAME];
        strcpy(lhsName, tok);

        int found = 0;
        for (int u = 0; u < uniqCount; u++) {
            if (strcmp(uniq[u], lhsName) == 0) {
                found = 1;
                break;
            }
        }
        if (!found)
            strcpy(uniq[uniqCount++], lhsName);

        tok = strtok(NULL, " \t\n");
        if (tok != NULL && (strcmp(tok, "->") == 0 || strcmp(tok, "=") == 0))
            tok = strtok(NULL, " \t\n");

        strcpy(head[total], lhsName);
        int n = 0;
        while (tok != NULL) {
            if (strcmp(tok, "|") == 0) {
                bodyLen[total] = n;
                total++;
                strcpy(head[total], lhsName);
                n = 0;
            } else {
                strcpy(body[total][n++], tok);
            }
            tok = strtok(NULL, " \t\n");
        }
        bodyLen[total] = n;
        total++;
    }

    printf("\n================ COMPUTED RESULTS ================\n");

    for (int u = 0; u < uniqCount; u++) {
        firstLen = 0;
        computeFirst(uniq[u]);
        printf("FIRST(%s) = { ", uniq[u]);
        for (int i = 0; i < firstLen; i++)
            printf("%s ", firstTab[i]);
        printf("}\n");

        followLen = 0;
        memset(visited, 0, sizeof(visited));
        computeFollow(uniq[u]);
        printf("FOLLOW(%s) = { ", uniq[u]);
        for (int i = 0; i < followLen; i++)
            printf("%s ", followTab[i]);
        printf("}\n\n");
    }
    printf("==================================================\n");

    return 0;
}
