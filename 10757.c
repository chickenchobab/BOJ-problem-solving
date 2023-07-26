#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char a[10002],b[10002];
    scanf("%s %s",a,b);

    int l1=strlen(a), l2=strlen(b);
    int i1=l1-1,i2=l2-1;
    int max=l1>l2?l1:l2;
    int idx=max;
    int* arr=calloc(sizeof(int),max+1);

    while(1)
    {
        int sum;

        if(i1<0 && i2<0)  break;
        else if(i1<0 && i2>=0) sum=b[i2--]-'0';
        else if(i1>=0 && i2<0)  sum=a[i1--]-'0';
        else sum=a[i1--]-'0'+b[i2--]-'0';
        if(sum+arr[idx]>9) 
        {
            arr[idx-1]+=1;
        }
        arr[idx]=(sum+arr[idx])%10;
        idx--;
    }
    for(int i=0;i<max+1;i++)
    {
        if(!i && !arr[i]) continue;
        printf("%d",arr[i]);
    }
    return 0;
}