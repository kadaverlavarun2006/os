#include <stdio.h>
int main() {
    int n, i, j, t, bt[20], p[20], wt[20], tat[20];
    float awt = 0, atat = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    /* sort by burst time (shortest first) */
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (bt[i] > bt[j]) {
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i];  p[i]  = p[j];  p[j]  = t;
            }
    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time    = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", atat / n);
    return 0;
}
