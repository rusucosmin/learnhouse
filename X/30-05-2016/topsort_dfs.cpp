#include <fstream>
#include <bitset>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 100005;

vector <int> g[maxn];
int n, m;
vector <int> tsort;
bitset <maxn> used;

void dfs(int node) {
    used[node] = 1;
    for(auto it : g[node])
        if(!used[it])
            dfs(it);
    tsort.push_back(node);
}

int main() {
    ifstream fin("sortaret.in");
    ofstream fout("sortaret.out");

    fin >> n >> m;
    while(m --) {
        int x, y;
        fin >> x >> y;
        g[x].push_back(y);
    }
    for(int i = 1; i <= n; ++ i)
        if(!used[i])
            dfs(i);
    reverse(tsort.begin(), tsort.end());
    for(auto it : tsort)
        fout << it << ' ';
}
