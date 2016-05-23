#include <fstream>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100005;

vector <int> g[maxn];
int deg[maxn], n, m;
vector <int> tsort;

int main() {
    ifstream fin("sortaret.in");
    ofstream fout("sortaret.out");

    fin >> n >> m;
    while(m --) {
        int x, y;
        fin >> x >> y;
        g[x].push_back(y);
        ++ deg[y];
    }
    queue <int> q;
    for(int i = 1; i <= n; ++ i)
        if(deg[i] == 0)
            q.push(i);
    while(!q.empty()) {
        int node = q.front();
        tsort.push_back(node);
        q.pop();
        for(auto it : g[node])
            if(-- deg[it] == 0)
                q.push(it);
    }
    for(auto it : tsort)
        fout << it << ' ';
}
