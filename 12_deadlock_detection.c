#include <stdio.h>
int main() {
    int n, m, i, j, found, dead = 0;
    int alloc[10][10], req[10][10], work[10], fin[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);
    for (i = 0; i < n; i++) {
        printf("Enter allocation for P%d: ", i);
        for (j = 0; j < m; j++) scanf("%d", &alloc[i][j]);
    }
    for (i = 0; i < n; i++) {
        printf("Enter request for P%d: ", i);
        for (j = 0; j < m; j++) scanf("%d", &req[i][j]);
    }
    printf("Enter available resources: ");
    for (j = 0; j < m; j++) scanf("%d", &work[j]);

    for (i = 0; i < n; i++) {           /* process holding nothing can't be deadlocked */
        fin[i] = 1;
        for (j = 0; j < m; j++)
            if (alloc[i][j] != 0) fin[i] = 0;
    }
    do {
        found = 0;
        for (i = 0; i < n; i++) {
            if (!fin[i]) {
                int ok = 1;
                for (j = 0; j < m; j++)
                    if (req[i][j] > work[j]) { ok = 0; break; }
                if (ok) {
                    for (j = 0; j < m; j++) work[j] += alloc[i][j];
                    fin[i] = 1;
                    found = 1;
                }
            }
        }
    } while (found);
    for (i = 0; i < n; i++)
        if (!fin[i]) dead++;
    if (dead == 0)
        printf("\nNo deadlock detected.\n");
    else {
        printf("\nDeadlock detected. Deadlocked processes: ");
        for (i = 0; i < n; i++)
            if (!fin[i]) printf("P%d ", i);
        printf("\n");
    }
    return 0;
}
