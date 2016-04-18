#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

const int maxn = 1005;

#define VLAD for(int i = 1 ; i <= n ; i ++)

char s[maxn][maxn];
int n, m, dist[maxn][maxn];
queue <pair<int, int> > q;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1,  0,-1};

inline bool inside(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m && s[x][y] != '#';
}

void lee() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d = 0 ; d < 4 ; ++ d) {
            int xnou = x + dx[d];
            int ynou = y + dy[d];
            if(inside(xnou, ynou) && dist[xnou][ynou] == -1) {
                dist[xnou][ynou] = dist[x][y] + 1;
                q.push(make_pair(xnou, ynou));
            }
        }
    }
}

int main() {
    ifstream fin("input.in");
    ofstream fout("output.out");
    fin >> n >> m;
    fin.get();
    VLAD
    {
        fin.getline(s[i]+1, maxn);
        for(int j = 1 ; j <= m ; ++ j)
            if(s[i][j] == 'P') {
                q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = -1;
            }
    }
    lee();
    for(int i = 1 ; i <= n ; ++ i, fout << '\n')
        for(int j = 1 ; j <= m ; ++ j)
            fout << dist[i][j] << ' ';
}
