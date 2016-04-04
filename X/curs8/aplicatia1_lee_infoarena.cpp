#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

const int maxn = 1005;

ifstream fin("input.in");
ofstream fout("output.out");

int n, m, a[maxn][maxn], dist[maxn][maxn];
queue <pair<int, int> > q;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1,  0,-1};

inline bool inside(int xnou, int ynou) {
    return xnou >= 1 && xnou <= n && ynou >= 1 && ynou <= m;
}

void lee() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d = 0 ; d < 4 ; ++ d) {
            int xnou = x + dx[d];
            int ynou = y + dy[d];
            if(inside(xnou, ynou) && a[xnou][ynou] != 1
                        && dist[xnou][ynou] == 0) {
                dist[xnou][ynou] = dist[x][y] + 1;
                q.push(make_pair(xnou, ynou));
            }
        }
    }
    int minim = (1 << 30);
    for(int i = 1 ; i <= n ; ++ i, fout << '\n')
        for(int j = 1 ; j <= m ; ++ j) {
            fout << dist[i][j] << ' ';
            if(dist[i][j] != 0 && a[i][j] == -2 && (i == 1 || j == 1 || i == n || j == m))
                minim = min(minim, dist[i][j]);
        }
    fout << minim << '\n';
}

int main() {
    fin >> n >> m;
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = 1 ; j <= m ; ++ j) {
            fin >> a[i][j];
            if(a[i][j] == -1) {
                q.push(make_pair(i, j));
                dist[i][j] = 1; /// pornesc cu 1
            }
        }
    lee();
}
