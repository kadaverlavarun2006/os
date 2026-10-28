
#include <stdio.h>
int main() {
    int n,m,a[10][10],mx[10][10],need[10][10];
    int av[10],fin[10]={0},seq[10],cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&mx[i][j]);
    for(int j=0;j<m;j++)scanf("%d",&av[j]);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        need[i][j]=mx[i][j]-a[i][j];
        if(need[i][j]<0)return 1;
    }
    while(cnt<n){
        int found=0;
        for(int i=0;i<n;i++)if(!fin[i]){
            int ok=1;
            for(int j=0;j<m;j++)if(need[i][j]>av[j])ok=0;
            if(ok){
                for(int j=0;j<m;j++)av[j]+=a[i][j];
                seq[cnt++]=i;fin[i]=1;found=1;
            }
        }
        if(!found)break;
    }
    printf("\nProcess\tFinish\n");
    for(int i=0;i<n;i++)printf("P%d\t%s\n",i,fin[i]?"Yes":"No");
    if(cnt==n){
        printf("Safe Sequence: ");
        for(int i=0;i<n;i++)printf("P%d ",seq[i]);
        printf("\nSAFE STATE\n");
    }else printf("UNSAFE STATE\n");
    return 0;
}
