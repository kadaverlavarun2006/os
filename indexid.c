
#include <stdio.h>
int main() {
    int disk[100]={0},n,idx,len,b[100],ok;
    scanf("%d",&n);
    printf("\nFile\tIndex\tData Blocks\n");
    for(int f=1;f<=n;f++){
        scanf("%d%d",&idx,&len);
        if(idx<0||idx>=100||len<=0||len>99||disk[idx]){
            printf("F%d\tNot allocated\n",f);
            continue;
        }
        for(int i=0;i<len;i++)scanf("%d",&b[i]);
        ok=1;
        for(int i=0;i<len;i++){
            if(b[i]<0||b[i]>=100||b[i]==idx||disk[b[i]])ok=0;
            for(int j=0;j<i;j++)if(b[i]==b[j])ok=0;
        }
        if(ok){
            disk[idx]=f;
            for(int i=0;i<len;i++)disk[b[i]]=f;
            printf("F%d\t%d\t",f,idx);
            for(int i=0;i<len;i++)printf("%d ",b[i]);
            printf("\n");
        }else printf("F%d\tNot allocated\n",f);
    }
    return 0;
}
