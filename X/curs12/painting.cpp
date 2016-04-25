#include<iostream>
#include<fstream>
#include <bitset>
#include<vector>

using namespace std;

const int maxn = 100005;

vector<int> g[maxn], arb[maxn];
int n, m, culoare[maxn];
bitset <maxn> used;

void dfs(int node, int dad) {
    culoare[node] = 1;
    for(auto vec : g[node]) {
        if(vec == dad)
            continue;
        /// ajunge doar daca vec != dad
        arb[node].push_back(vec);
        dfs(vec, node);
    }
}

void color(int node, int col) {
    if(used[node])
        return ;
    used[node] = 1;
    culoare[node] = col;
    for(auto fiu : arb[node])
        color(fiu, col);
}

int main() {
    freopen("painting.in", "r", stdin);
    freopen("painting.out", "w", stdout);
    cin.sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i < n; ++ i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    vector <pair<int, int> > v;
    for(int i = 1 ; i <= m ; ++ i) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    for(int i = v.size() - 1 ; i >= 0 ; -- i) {
        color(v[i].first, v[i].second);
    }
    for(int i = 1 ; i <= n ; ++ i) {
        cout << culoare[i] << ' ';
    }
}

