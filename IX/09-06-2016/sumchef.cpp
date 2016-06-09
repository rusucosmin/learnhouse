#include <iostream>

using namespace std;

const int maxval = 10;

int fr[maxval];
int n, x;

int main() {
    freopen("input.in", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> x;
        while(x > 0) {
            ++ fr[x % 10];
            x = x / 10;
        }
    }
    long long sum = 0;
    for(int i = 1; i <= 9; ++ i)
        sum = sum + 1LL * fr[i] * i * i * i;
}
