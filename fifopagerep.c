
#include <stdio.h>
int main() {
    int n,f,p[100],fr[20],pos=0,fault=0,hit=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
    scanf("%d",&f);
    if(f<=0||f>20)return 1;
    for(int i=0;i<f;i++)fr[i]=-1;
    printf("\nPage\tFrames\t\tStatus\n");
    for(int i=0;i<n;i++){
        int found=0;
        for(int j=0;j<f;j++)if(fr[j]==p[i])found=1;
        if(found)hit++;
        else{fr[pos]=p[i];pos=(pos+1)%f;fault++;}
        printf("%d\t",p[i]);
        for(int j=0;j<f;j++)if(fr[j]==-1)printf("- ");else printf("%d ",fr[j]);
        printf("\t%s\n",found?"Hit":"Fault");
    }
    printf("Page Faults = %d\nPage Hits = %d\n",fault,hit);
    return 0;
}
