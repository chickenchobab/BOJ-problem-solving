#include <stdio.h>

int sucnum(int n, int pivot,int initnum)
{
    if(n==0) return initnum;
    if(n==1) return pivot;
    
    return sucnum(n-2, pivot, initnum)-sucnum(n-1,pivot,initnum);
}

int main()
{
    int n,num,cnt,max=0,maxpiv;
    scanf("%d",&n);

    for(int i=1;i<=n;i++) //all pivot
    {
        cnt=0;
        while(1)
        {
            int output=sucnum(cnt,i,n);
            if(output>=0) cnt++;
            else break;
        }
        if(max<=cnt)
        {
            max=cnt;
            maxpiv=i;
        } 
    }
    printf("%d\n",max);

    for(int i=0;i<max;i++)
    {
        int output=sucnum(i,maxpiv,n);
        printf("%d ",output);
    }
}