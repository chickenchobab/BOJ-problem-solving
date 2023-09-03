#include <iostream>
#include <vector>
//#define MAX 1000001

using namespace std;

int n,m,c,a,b;
vector<int> set;

int find(int x){
    if(set[x]==x) return x;
    return (set[x]=find(set[x]));
}

void unite(int a,int b){
    int c1=find(a), c2=find(b);
    if(set[c1]<set[c2])
        set[c2]=c1;
    else{
        if(set[c1]==set[c2])
            set[c2]--;
        set[c1]=c2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<=n;i++){
        set.push_back(i);
    }
    while(m--){
        cin>>c>>a>>b;
        if(c==1) {
            if(find(a)==find(b)) cout<<"yes\n";
            else cout<<"no\n";
        }
        else
            unite(a,b);
    }
    return 0;
}