
#include <stdio.h>
int main() {
    int n,m,a[10][10],r[10][10],w[10],fin[10]={0};
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&r[i][j]);
    for(int j=0;j<m;j++)scanf("%d",&w[j]);
    for(int i=0;i<n;i++){
        int zero=1;
        for(int j=0;j<m;j++)if(a[i][j])zero=0;
        fin[i]=zero;
    }
    int change;
    do{
        change=0;
        for(int i=0;i<n;i++)if(!fin[i]){
            int ok=1;
            for(int j=0;j<m;j++)if(r[i][j]>w[j])ok=0;
            if(ok){
                for(int j=0;j<m;j++)w[j]+=a[i][j];
                fin[i]=1;change=1;
            }
        }
    }while(change);
    printf("\nProcess\tStatus\n");
    int dead=0;
    for(int i=0;i<n;i++){
        printf("P%d\t%s\n",i,fin[i]?"Not Deadlocked":"Deadlocked");
        if(!fin[i])dead=1;
    }
    printf("%s\n",dead?"Deadlock Detected":"No Deadlock");
    return 0;
}
