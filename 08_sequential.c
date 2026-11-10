#include <stdio.h>
int main() {
    int f[50] = {0}, st, len, j, k, c = 1;
    while (c == 1) {
        printf("Enter starting block and length of file: ");
        scanf("%d %d", &st, &len);
        k = 0;
        if (st + len <= 50)
            for (j = st; j < st + len; j++)
                if (f[j] == 0) k++;
        if (len == k && len > 0) {
            for (j = st; j < st + len; j++) {
                f[j] = 1;
                printf("%d\t%d\n", j, f[j]);
            }
            printf("File is allocated to disk\n");
        } else
            printf("File is not allocated (blocks already in use)\n");
        printf("Do you want to enter more files (1/0)? ");
        scanf("%d", &c);
    }
    return 0;
}
