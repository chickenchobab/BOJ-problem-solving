#include <iostream>
#include <algorithm>

using namespace std;

int n,a,b;
typedef pair<int, int> p;
p arr[100001];

bool cmp(p x, p y){
    if(x.second==y.second)
        return x.first<y.first;
    return x.second<y.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        arr[i].first=a;
        arr[i].second=b;
    }

    sort(arr+1, arr+n+1, cmp);

    int cur=0, cnt=0;
    for(int i=1; i<=n; i++){
        if(arr[i].first>=cur) {
            cnt++; 
            cur=arr[i].second;
        }
    }
    
    cout<<cnt;
}