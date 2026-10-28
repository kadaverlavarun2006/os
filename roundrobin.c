
#include <stdio.h>
int main() {
    int n,bt[20],rem[20],wt[20]={0},tat[20];
    int q,time=0,done;
    float aw=0,at=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&bt[i]);rem[i]=bt[i];}
    scanf("%d",&q);
    if(q<=0)return 1;
    do {
        done=1;
        for(int i=0;i<n;i++)if(rem[i]>0){
            done=0;
            if(rem[i]>q){time+=q;rem[i]-=q;}
            else{time+=rem[i];wt[i]=time-bt[i];rem[i]=0;}
        }
    }while(!done);
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];aw+=wt[i];at+=tat[i];
        printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("Average WT = %.2f\nAverage TAT = %.2f\n",aw/n,at/n);
    return 0;
}
