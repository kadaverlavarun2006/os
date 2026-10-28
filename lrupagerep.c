
#include <stdio.h>
int main() {
    int n,f,p[100],fr[20],last[20],time=0,fault=0,hit=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
    scanf("%d",&f);
    if(f<=0||f>20)return 1;
    for(int i=0;i<f;i++){fr[i]=-1;last[i]=0;}
    printf("\nPage\tFrames\t\tStatus\n");
    for(int i=0;i<n;i++){
        int v=-1;
        for(int j=0;j<f;j++)if(fr[j]==p[i])v=j;
        time++;
        if(v!=-1){hit++;last[v]=time;}
        else{
            for(int j=0;j<f;j++)
                if(fr[j]==-1){v=j;break;}
            if(v==-1){
                v=0;
                for(int j=1;j<f;j++)if(last[j]<last[v])v=j;
            }
            fr[v]=p[i];last[v]=time;fault++;
        }
        printf("%d\t",p[i]);
        for(int j=0;j<f;j++)if(fr[j]==-1)printf("- ");else printf("%d ",fr[j]);
        printf("\t%s\n",v!=-1&&fr[v]==p[i]&&last[v]==time&&fault+hit>0?"Processed":"");
    }
    printf("Page Faults = %d\nPage Hits = %d\n",fault,hit);
    return 0;
}
