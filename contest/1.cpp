#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

int N, M, A, B, X;
int finished[200001];
int cntGroup[200001];
vector<int> v[200001];
int visited[200001];
int groupIdx;
pair<int, vector<int>> mx;
int cnt;
bool cycleFlag;
map<pair<int, int>, int> m;

void dfs(int s) {
    finished[s] = groupIdx;
    ++cntGroup[groupIdx];

    for (int nxt : v[s]) {
        if (!finished[nxt]) {
            dfs(nxt);
        }
    }
}

void dfsCnt(int s) {
    visited[s] = 1;
    ++cnt;

    for (int nxt : v[s]) {
        if (!visited[nxt] && nxt != X) {
            dfsCnt(nxt);
        } else if (nxt == X && cnt != 1) {
            cycleFlag = true;
            m[{s, nxt}] = m[{nxt, s}] = 1;
        }
    }
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        cin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
    }

    cin >> X;

    for (int i = 1; i <= N; ++i) {
        if (!finished[i]) {
            ++groupIdx;
            dfs(i);
        }
    }

    for (int i = 1; i <= groupIdx; ++i) {
        if (mx.first == cntGroup[i]) {
            mx.second.push_back(i);
        } else if (mx.first < cntGroup[i]) {
            mx.first = cntGroup[i];
            mx.second.clear();
            mx.second.push_back(i);
        }
    }

    if (find(mx.second.begin(), mx.second.end(), finished[X]) != mx.second.end()) {
        mx.first = 0;
        mx.second.clear();

        for (int i = 1; i <= groupIdx; ++i) {
            if (i != finished[X]) {
                if (mx.first < cntGroup[i]) {
                    mx.first = cntGroup[i];
                    mx.second.clear();
                    mx.second.push_back(i);
                } else if (mx.first == cntGroup[i]) {
                    mx.second.push_back(i);
                }
            }
        }
        
        for (int nxt : v[X]) {
            if (!m[{X, nxt}]) {
                m[{X, nxt}] = m[{nxt, X}] = 1;
                cycleFlag = false;
                cnt = 0;

                dfsCnt(nxt);

                if (!cycleFlag) cnt += 1;

                if (cnt > mx.first) mx.first = cnt;
            }
        }
    }

    cout << mx.first;

    return 0;
}