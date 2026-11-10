#include <stdio.h>
int main() {
    int n, f, i, j, k = 0, faults = 0, hit, p[50], fr[10], last[10];
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) scanf("%d", &p[i]);
    for (i = 0; i < f; i++) fr[i] = -1;
    printf("\nPage\tFrames\t\tStatus\n");
    for (i = 0; i < n; i++) {
        hit = 0;
        for (j = 0; j < f; j++)
            if (fr[j] == p[i]) { hit = 1; last[j] = i; break; }
        if (!hit) {
            int pos = -1, min = 1000;
            for (j = 0; j < f; j++)
                if (fr[j] == -1) { pos = j; break; }
            if (pos == -1) {       /* replace least recently used page */
                for (j = 0; j < f; j++)
                    if (last[j] < min) { min = last[j]; pos = j; }
            }
            fr[pos] = p[i];
            last[pos] = i;
            faults++;
        }
        printf("%d\t", p[i]);
        for (j = 0; j < f; j++) {
            if (fr[j] == -1) printf("- ");
            else printf("%d ", fr[j]);
        }
        printf("\t%s\n", hit ? "Hit" : "Fault");
    }
    printf("\nTotal page faults = %d\n", faults);
    printf("Page hit ratio    = %.2f\n", (float)(n - faults) / n);
    return 0;
}
