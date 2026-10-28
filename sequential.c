
#include <stdio.h>
int main() {
    int disk[100]={0},n,s,len,ok;
    scanf("%d",&n);
    printf("\nFile\tStart\tLength\tBlocks\n");
    for(int f=1;f<=n;f++){
        scanf("%d%d",&s,&len);
        ok=(s>=0&&len>0&&s+len<=100);
        for(int i=s;ok&&i<s+len;i++)
            if(disk[i])ok=0;
        if(ok){
            for(int i=s;i<s+len;i++)disk[i]=f;
            printf("F%d\t%d\t%d\t",f,s,len);
            for(int i=s;i<s+len;i++)printf("%d ",i);
            printf("\n");
        }else printf("F%d\tNot allocated\n",f);
    }
    return 0;
}
