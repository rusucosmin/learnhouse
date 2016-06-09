#include <iostream>

using namespace std;

const int maxval = 10000;

int fr[maxval];

int main() {
    //freopen("input.in", "r", stdin);
    int x;
    while(cin >> x) {
        if(x < maxval)
            ++ fr[x];
    }
    for(int i = maxval - 1; i >= 1; -- i)
        if(fr[i] == 0) {
            cout << i << ' ';
        }
}
