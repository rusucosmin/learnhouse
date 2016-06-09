#include <iostream>

using namespace std;

const int maxval = 10;

int fr[maxval];
int prime[] = {7, 5, 3, 2};

int main() {
    freopen("input.in", "r", stdin);

    int x;
    while(cin >> x){
       ++ fr[x];
    }
    for(int i = 0; i < 4 ; ++ i)
        if(fr[ prime[i] ] != 0) {
            cout << prime[i] << ' ' << fr [ prime[i] ] << '\n';
            break;
        }
}
