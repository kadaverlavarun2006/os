
#include <stdio.h>
int main() {
    int disk[100]={0},n,len,b[100],ok;
    scanf("%d",&n);
    printf("\nFile\tStart\tEnd\tLinked Blocks\n");
    for(int f=1;f<=n;f++){
        scanf("%d",&len);
        if(len<=0||len>100){
            printf("F%d\tNot allocated\n",f);
            continue;
        }
        for(int i=0;i<len;i++)scanf("%d",&b[i]);
        ok=1;
        for(int i=0;i<len;i++){
            if(b[i]<0||b[i]>=100||disk[b[i]])ok=0;
            for(int j=0;j<i;j++)if(b[i]==b[j])ok=0;
        }
        if(ok){
            for(int i=0;i<len;i++)disk[b[i]]=f;
            printf("F%d\t%d\t%d\t",f,b[0],b[len-1]);
            for(int i=0;i<len;i++){
                printf("%d",b[i]);
                if(i<len-1)printf(" -> ");
            }
            printf(" -> NULL\n");
        }else printf("F%d\tNot allocated\n",f);
    }
    return 0;
}
