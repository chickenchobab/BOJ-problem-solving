#include <iostream>

using namespace std;

bool arr[123456*2+1];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,cnt;
    while(1){
        cin>>n;
        cnt=0;
        if(!n) break;

        for(int i=2;i<=2*n;i++){
            if(arr[i]) continue;
            for(int j=2*i; j<=2*n; j+=i){
                arr[j]=true;
            }
        }

        for(int i=n+1; i<=2*n; i++){
            if(!arr[i]) cnt++;
        }
        cout<<cnt<<'\n';
    }
    


    return 0;
}