#include <iostream>

using namespace std;

const int maxval = 10;

int fr[maxval];

int main() {
    freopen("input.in", "r", stdin);
    int x;
    while(cin >> x) {
        /// iau fiecare cifra din numar, si o bag la frecventa
        do {
            ++ fr[x % 10];      /// cresc frecventa ultimei cifre
            x = x / 10;         /// elimin ultima cifra
        } while(x > 0);         /// cat timp mai are cifre
    }
    int cnt = 0;
    for(int i = maxval - 1 ; i >= 0 ; -- i)
        for(int j = 1; j <= fr[i] ; ++ j) {
            cout << i << ' ';
            ++ cnt;
            if(cnt == 20) {
                cout << '\n';
                cnt = 0;
            }
        }
}

