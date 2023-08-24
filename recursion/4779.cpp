#include <iostream>

using namespace std;

int n=1;
char arr[27*27*27*27];

void cut(int num){
    if(num==0) return;
    for(int i=0;i<n;i++){
        if(i%num>=num/3 && i%num<2*num/3)
            arr[i]=' ';
        else if(arr[i]!=' ')
            arr[i]='-';
    }
    cut(num/3);
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int log;
    while(cin>>log){
        while(log--) n*=3;
        cut(n);
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<'\n';
        n=1;
    }
    return 0;
    
}