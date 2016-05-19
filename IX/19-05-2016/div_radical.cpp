#include <fstream>
#include <algorithm>

using namespace std;

const int maxn = 10005;

int divi[maxn], m;

int main() {
    int n;
    ifstream fin("date.in");
    ofstream fout("date.out");
    fin >> n;
    for(int d = 1; d * d <= n; ++ d) {
        if(n % d == 0) { /// daca d este chiar un divizor
            divi[m] = d;
            ++ m;
            if(d != n / d) {
                divi[m] = n / d;
                ++ m;
            }
        }
    }
    sort(divi, divi + m);
    for(int i = 0; i < m; ++ i)
        fout << divi[i] << ' ';
    return 0;
}
