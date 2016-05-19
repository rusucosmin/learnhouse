#include <fstream>
#include <iostream>

using namespace std;

const int maxn = 1005;

int n, v[maxn];

int main() {
    ifstream fin("date.in");
    ofstream fout("date.out");

    fin >> n;
    for(int i = 0; i < n; ++ i)
        fin >> v[i];

    for(int i = 0; i + 1 < n; ++ i)
        for(int j = i + 1; j < n; ++ j)
            if(v[i] > v[j])
                swap(v[i], v[j]);
    for(int i = 0; i < n; ++ i)
        fout << v[i] << ' ';
}
