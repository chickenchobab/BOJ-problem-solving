#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int arr[10001] = {0,};

    int n; cin>>n;
    for(int i=0;i<n;i++){
        int tmp; cin>>tmp;
        arr[tmp]++;
    }
    for(int i=1;i<10001;i++){
        while(arr[i]--){
            cout<<i<<'\n';
        }
    }
    
}