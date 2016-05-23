#include <vector>
#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;

const int maxn = 100005;

vector <int> g[maxn];
vector <int> comp[maxn];
int n, m;
bitset <maxn> used;
vector <int> actcc;

void dfs(int node) {
    used[node] = 1;
    actcc.push_back(node);
    for(auto it : g[node])
        if(!used[it])
            dfs(it);
}

int main() {
    ifstream fin("dfs.in");
    ofstream fout("dfs.out");
    fin >> n >> m;
    while(m --) {
        int x, y;
        fin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int sz = 0;
    for(int i = 1 ; i <= n ; ++ i) {
        if(!used[i]) {
            actcc.clear();
            dfs(i);
            ++ sz;
            comp[sz] = actcc;
        }
    }
    for(int i = 1 ; i <= sz ; ++ i) {
        cerr << "Cc #" << i << '\n';
        for(auto it : comp[i])
            cerr << it << ' ';
    }
}
