#include <stdio.h>
int main() {
    int n, m, i, j, cnt = 0, found;
    int alloc[10][10], max[10][10], need[10][10], avail[10], fin[10] = {0}, seq[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);
    for (i = 0; i < n; i++) {
        printf("Enter allocation for P%d: ", i);
        for (j = 0; j < m; j++) scanf("%d", &alloc[i][j]);
    }
    for (i = 0; i < n; i++) {
        printf("Enter maximum need for P%d: ", i);
        for (j = 0; j < m; j++) scanf("%d", &max[i][j]);
    }
    printf("Enter available resources: ");
    for (j = 0; j < m; j++) scanf("%d", &avail[j]);

    printf("\nNeed matrix:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    while (cnt < n) {
        found = 0;
        for (i = 0; i < n; i++) {
            if (!fin[i]) {
                int ok = 1;
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j]) { ok = 0; break; }
                if (ok) {
                    for (j = 0; j < m; j++) avail[j] += alloc[i][j];
                    seq[cnt++] = i;
                    fin[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) break;
    }
    if (cnt == n) {
        printf("\nSystem is in SAFE state.\nSafe sequence: ");
        for (i = 0; i < n; i++) printf("P%d%s", seq[i], i < n - 1 ? " -> " : "\n");
    } else
        printf("\nSystem is in UNSAFE state (deadlock may occur).\n");
    return 0;
}
