
#include <stdio.h>
int main() {
    int n,bt[20],pr[20],p[20],wt[20],tat[20];
    float aw=0,at=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&bt[i],&pr[i]);p[i]=i+1;
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(pr[i]>pr[j]){
                int t=pr[i];pr[i]=pr[j];pr[j]=t;
                t=bt[i];bt[i]=bt[j];bt[j]=t;
                t=p[i];p[i]=p[j];p[j]=t;
            }
    wt[0]=0;
    for(int i=1;i<n;i++)wt[i]=wt[i-1]+bt[i-1];
    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];aw+=wt[i];at+=tat[i];
        printf("P%d\t%d\t%d\t\t%d\t%d\n",p[i],bt[i],pr[i],wt[i],tat[i]);
    }
    printf("Average WT = %.2f\nAverage TAT = %.2f\n",aw/n,at/n);
    return 0;
}
