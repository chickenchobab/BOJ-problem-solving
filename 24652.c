#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cnt=0;

int search(int arr[], int l, int r, int x);


int main()
{
    int n,k,cnt;
    scanf("%d %d",&n,&k);
    

    
    


}

int search(int arr[], int l, int r, int x)
{
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==x) return 1;
        if(x<arr[mid])  r=mid-1;
        if(arr[mid]>x)  l=mid+1;
    }
    return 0;
}

