#include <iostream>

using namespace std;

int n;
char arr[729*3][729*3];

void starpoint(int num){
   
    if(num==1) return;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i%num>=num/3 && i%num<2*num/3 && j%num>=num/3 && j%num<2*num/3)
                arr[i][j]=' ';
            else if(arr[i][j]!=' ')
                arr[i][j]='*';
        }
    }
    starpoint(num/3);
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;

    starpoint(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
}