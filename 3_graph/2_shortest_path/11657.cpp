#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define INF 111111111

using namespace std;

typedef tuple<int, int, int> iii;
int n, m, a, b, c;
long long d[555];
vector<iii> edge;

bool bellman_ford(){

        d[1] = 0;

		for (int i=1; i<=n-1; i++){       
            for(iii j : edge){           
                int a, b, ab;
                tie(a, b, ab) = {get<0>(j), get<1>(j), get<2>(j)};
                if(d[a] == INF) continue;
                if(d[b] > d[a] + ab) d[b] = d[a] + ab;
            }
		}
		for (iii j : edge){
            int a, b, ab;
            tie(a, b, ab) = {get<0>(j), get<1>(j), get<2>(j)};
            if(d[a] == INF) continue;
			if(d[b] > d[a] + ab) return false;
		}
		return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    for(int i=1; i<=n; i++) d[i]=INF;

    for(int i=1; i<=m; i++){
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }
    
    if(bellman_ford()){
        for(int i=2; i<=n; i++){
            if (d[i] != INF) cout << d[i] << '\n';
            else cout << -1 << '\n';
        }
    } 
    else{
        cout << -1;
    }

    
    
    return 0;
}