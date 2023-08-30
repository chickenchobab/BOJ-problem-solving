#include <iostream>
#include <queue>
 
using namespace std;

typedef long long ll;

struct cmp{
    bool operator()(ll& a, ll& b){
        if(abs(a)==abs(b))  
            return a>b;
        return abs(a)>abs(b);
    }
};

int n;
priority_queue<ll, vector<ll>, cmp> pq;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(!tmp){
            if(pq.empty()) cout<<0<<'\n';
            else {cout<<pq.top()<<'\n'; pq.pop();}
        }
        else
            pq.push(tmp);
    }
}
