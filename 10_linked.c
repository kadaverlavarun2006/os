#include <stdio.h>
int main() {
    int f[50] = {0}, b[50], n, i, ok, c = 1;
    while (c == 1) {
        printf("Enter number of blocks in the file: ");
        scanf("%d", &n);
        printf("Enter the block numbers: ");
        ok = 1;
        for (i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            if (f[b[i]] != 0) ok = 0;
        }
        if (ok) {
            for (i = 0; i < n; i++) f[b[i]] = 1;
            printf("File is allocated. Chain: ");
            for (i = 0; i < n; i++) printf("%d -> ", b[i]);
            printf("NULL\n");
        } else
            printf("A block in the file is already allocated\n");
        printf("Do you want to enter more files (1/0)? ");
        scanf("%d", &c);
    }
    return 0;
}
