#include <iostream>
#include <cassert>
#include <stdlib.h>

using namespace std;

const int dx[] = {1,-1, 0, 0, 1, 1,-1,-1};
const int dy[] = {0, 0, 1,-1, 1,-1, 1,-1};

int n, m, a[100][100];

bool inside(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void fill(int x, int y) {
    if(x == 1 || y == 1 || x == n || y == m) {
       cout << x << ' ' << y << '\n';
       exit(0);
    }
    a[x][y] = 0;
    for(int d = 0 ; d < 4 ; ++ d) {
        int xnou = x + dx[d];
        int ynou = y + dy[d];
        if(inside(xnou, ynou) && a[xnou][ynou] == 1)
            fill(xnou, ynou);
    }
}

int main() {
    freopen("input.in", "r", stdin);
    int xst, yst;
    cin >> n >> m >> xst >> yst;
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = 1 ; j <= m ; ++ j)
            cin >> a[i][j];
    fill(xst, yst);
    return 0;
}
