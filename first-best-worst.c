//Use the same program for all three. Change mode to 1 for First Fit, 2 for Best Fit, or 3 for Worst Fit.
#include <stdio.h>
int main() {
    int nb,np,b[20],p[20],a[20],mode;
    scanf("%d",&nb);
    for(int i=0;i<nb;i++)scanf("%d",&b[i]);
    scanf("%d",&np);
    for(int i=0;i<np;i++)scanf("%d",&p[i]);
    scanf("%d",&mode);
    for(int i=0;i<np;i++){
        a[i]=-1;
        int k=-1;
        for(int j=0;j<nb;j++)
            if(b[j]>=p[i]){
                if(mode==1){k=j;break;}
                if(k==-1||(mode==2&&b[j]<b[k])||
                   (mode==3&&b[j]>b[k]))k=j;
            }
        if(k!=-1){a[i]=k;b[k]-=p[i];}
    }
    printf("\nProcess\tSize\tBlock\n");
    for(int i=0;i<np;i++){
        printf("P%d\t%d\t",i+1,p[i]);
        if(a[i]==-1)printf("Not Allocated\n");
        else printf("%d\n",a[i]+1);
    }
    return 0;
}
