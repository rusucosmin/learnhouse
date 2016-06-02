#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

const int maxn = 1005;

int n, p[maxn], m;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        int x;
        cin >> x;
        bool prim = 1;
        if(x <= 1)
            prim = 0;
        for(int d = 2; d * d <= x; ++ d)
            if(x % d == 0)
                prim = 0;
        if(prim == 1) {
            ++ m;
            p[m] = x;
        }
    }
    sort(p + 1, p + m + 1);
    for(int i = 1; i <= m; ++ i)
        cout << p[i] << ' ';
    return 0;
}
