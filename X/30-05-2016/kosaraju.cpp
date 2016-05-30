#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>
#include <set>

using namespace std;

const int maxn = 100005;

int n, m;
vector <int> g[maxn], gt[maxn];
bitset <maxn> used;
set <set<int>> ctc;
vector <int> discovered;
set <int> actctc;

void dfst(int node) {
    used[node] = 1;
    for(auto it : gt[node])
        if(!used[it])
            dfst(it);
    discovered.push_back(node);
}

void dfs(int node) {
    used[node] = 1;
    actctc.insert(node);
    for(auto it : g[node])
        if(!used[it])
            dfs(it);
}

int main() {
    ifstream fin("ctc.in");
    ofstream fout("ctc.out");

    fin >> n >> m;
    while(m --) {
        int x, y;
        fin >> x >> y;
        g[x].push_back(y);
        gt[y].push_back(x);
    }
    for(int i = 1; i <= n; ++ i) {
        if(!used[i])
            dfst(i);
    }
    used.reset();
    for(int i = discovered.size() - 1; i >= 0; -- i)
        if(!used[discovered[i]]) {
            actctc.clear();
            dfs(discovered[i]);
            ctc.insert(actctc);
        }
    fout << ctc.size() << '\n';
    for(auto comp : ctc) {
        for(auto it : comp)
            fout << it << ' ';
        fout << '\n';
    }
}
