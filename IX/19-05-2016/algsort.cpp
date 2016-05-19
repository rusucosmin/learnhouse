#include <iostream>
#include <fstream>
#include <algorithm> /// sa putem folosi sort()

using namespace std;

const int maxn = 1005;

int n, v[maxn];

int main() {
    fin >> n;
    for(int i = 0; i < n; ++ i) {
        fin >> v[i];
    }
    sort(v, v + n);
    for(int i = 0; i < n;  ++ i)
        cout << v[i] << ' ';
    return 0;
}
