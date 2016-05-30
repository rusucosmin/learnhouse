#include <iostream>
#include <vector>
#include <fstream>
#include <bitset>
#include <algorithm>
using namespace std;

const int maxn = 15005;
const long long inf = (1LL << 60);

vector <int> g[maxn], gt[maxn], tsort;
int n, m, v[maxn];
long long dp[maxn]; /// dp[node] = suma maxima a unui lant care se termina pe node
bitset <maxn> used;

void dfs(int node) {
    used[node] = 1;
    for(auto it : g[node]) {
        if(!used[it])
            dfs(it);
    }
    tsort.push_back(node);
}

int main(){
    int t;
    ifstream fin("easygraph.in");
    ofstream fout("easygraph.out");
    fin >> t;
    while(t --) {
        fin >> n >> m;
        for(int i=1;i<=n;++i)
            fin>>v[i];
        for(int i=1;i<=m;++i){
            int x,y;
            fin>>x>>y;
            g[x].push_back(y);
            gt[y].push_back(x);
        }
        for(int i = 1; i <= n; ++ i)
            if(!used[i])
                dfs(i);
        reverse(tsort.begin(), tsort.end());
        long long rasp = -inf;
        for(auto it : tsort) {
            dp[it] = v[it];
            for(auto last : gt[it]) {
                dp[it] = max(dp[it], dp[last] + v[it]);
            }
            rasp = max(rasp, dp[it]);
        }
        fout << rasp << '\n';

        used.reset();
        for(int i = 1; i <= n; ++ i) {
            g[i].clear();
            gt[i].clear();
        }
    }
}
