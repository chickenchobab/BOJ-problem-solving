#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,cur=0,sum=0,total=0;
    cin>>n;

    int *price = new int[n];
    int *need = new int[n];
    int *cnt = new int[n];
    
    need[0]=0;
    for(int i=1;i<n;i++){
        cin>>need[i];
        sum+=need[i];
    }

    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    
    for(int i=0;i<n;i++){
        cnt[i]=0;
    }

    for(int i=1;i<n && cur<sum;i++)
    {
        if(need[i]>cur)
    }


    

    return 0;
}