#include <iostream>
#define MAX 50

using namespace std;

int c1=0,c2=0;

void f1(int n){
    if(n==1 || n==2) {c1++; return;}
    else {f1(n-1); f1(n-2);}
}

void f2(int n){
    int d[MAX]={0,};
    d[1]=d[2]=1;
    for(int i=3;i<=n;i++){
        if(d[i]) continue;
        d[i]=d[i-1]+d[i-2];
        c2++;
    }
}

int main(){
    int n;
    cin>>n;
    f1(n); f2(n);
    cout<<c1<<' '<<c2;
    return 0;

}