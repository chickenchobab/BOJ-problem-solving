#include <stdio.h>
#include <stdlib.h>

int cnt=0;

void merge(int A[],int p,int q,int r,int k)
{
    int i=p,j=q+1,t=0;
    int tmp[r-p+1];
    while(i<=q && j<=r)
    {
        
        if(A[i]<=A[j])
            tmp[t++]=A[i++];
        else
            tmp[t++]=A[j++];
    }
    while(i<=q)
        tmp[t++]=A[i++];
    while(j<=r)
        tmp[t++]=A[j++];
    i=p; t=0;
    while(i<=r)
    {
        if(cnt==k) break;
        A[i++]=tmp[t++];
        cnt++;
        // for(int i=0;i<5;i++)
        // {
        //     printf("%d ",A[i]);
        // }
        // printf("key:%d\n",cnt);
    }
        

    
  
    
        
    

}
void merge_sort(int A[], int p, int r,int k)
{

    if(p<r) 
    {
        int q=(p+r)/2;
        merge_sort(A,p,q,k);
        merge_sort(A,q+1,r,k);
        merge(A,p,q,r,k);
        
    }
    
    
}



int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int* A=malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        A[i]=tmp;
    }
    merge_sort(A,0,n-1,k);
    if(cnt<k) printf("%d",-1);
    else{
        for(int i=0;i<n;i++)
            printf("%d ",A[i]);
    }

}