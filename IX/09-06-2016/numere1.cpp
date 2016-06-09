#include <iostream>

using namespace std;

const int maxval = 1000;

int fr[maxval];

int main() {
    freopen("input.in", "r", stdin);
    int x;
    while(cin >> x) {
        if(x < maxval)
            ++ fr[x];
    }
    int cnt = 0;
    for(int i = maxval - 1; i >= 1; -- i)
        if(fr[i] == 0) {
            ++ cnt;
            cout << i << ' ';
            if(cnt == 2)
                break;
        }
}
