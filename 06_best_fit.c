#include <stdio.h>
int main() {
    int nb, np, b[20], p[20], a[20], i, j;
    printf("Enter number of blocks: ");
    scanf("%d", &nb);
    for (i = 0; i < nb; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &b[i]);
    }
    printf("Enter number of processes: ");
    scanf("%d", &np);
    for (i = 0; i < np; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &p[i]);
    }
    for (i = 0; i < np; i++) {
        a[i] = -1;
        for (j = 0; j < nb; j++) {
            if (b[j] >= p[i] && (a[i] == -1 || b[j] < b[a[i]]))
                a[i] = j;
        }
        if (a[i] != -1)
            b[a[i]] -= p[i];   /* reduce block size */
    }
    printf("\nProcess No\tProcess Size\tBlock No\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, p[i]);
        if (a[i] != -1) printf("%d\n", a[i] + 1);
        else printf("Not Allocated\n");
    }
    return 0;
}
