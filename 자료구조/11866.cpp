#include <iostream>

using namespace std;

int main(){
    int n,k; cin>>n>>k;
    int idx=k-1;
    int* arr=new int[n];
    for(int i=0; i<n;i++){
        arr[i]=i+1;
    }
    cout<<"<";
    for(int i=0;i<n;i++,idx=(idx+k)%n){
        cout<<arr[idx];
        if(i!=n-1) cout<<", ";
    }
    cout<<">";
    delete arr;
}