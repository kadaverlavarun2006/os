#include <stdio.h>
int main() {
    int f[50] = {0}, ind[50], n, i, ib, ok, c = 1;
    while (c == 1) {
        printf("Enter index block: ");
        scanf("%d", &ib);
        if (f[ib] != 0)
            printf("Index block is already allocated\n");
        else {
            printf("Enter number of blocks needed: ");
            scanf("%d", &n);
            printf("Enter the block numbers: ");
            ok = 1;
            for (i = 0; i < n; i++) {
                scanf("%d", &ind[i]);
                if (f[ind[i]] != 0) ok = 0;
            }
            if (ok) {
                f[ib] = 1;
                for (i = 0; i < n; i++) f[ind[i]] = 1;
                printf("File is allocated. Index table:\n");
                for (i = 0; i < n; i++)
                    printf("%d -------> %d\n", ib, ind[i]);
            } else
                printf("A block in the file is already allocated\n");
        }
        printf("Do you want to enter more files (1/0)? ");
        scanf("%d", &c);
    }
    return 0;
}
