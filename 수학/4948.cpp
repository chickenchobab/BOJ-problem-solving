#include <iostream>

using namespace std;

int is_prime(const int& n){
    for(int i=2;i<n;i++){
        if(!(n%i)) return 0;
    }
    return 1;
}

int main(){

    ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int n;
    while(1){
        cin>>n;
        if(!n) break;

        int cnt=0;
        for(int i=n+1;i<=2*n;i++){
            cnt+=is_prime(i);
        }
        cout<<cnt<<'\n';
    }


    return 0;
}