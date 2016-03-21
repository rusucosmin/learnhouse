#include <iostream>
#include <fstream>
using namespace std;

int l, c, n, k;

int z(int n, int xst, int yst, int xfn, int yfn) {
    if(n == 0)
        return 1;
    int midx = (xst + xfn) / 2;
    int midy = (yst + yfn) / 2;
    //cadranul 1
    if(xst <= l && l <= midx && yst <= c && c <= midy)
        return z(n - 1, xst, yst, midx, midy);
    //cadranul 2
    int var = (1 << (n - 1));
    if(xst <= l && l <= midx && midy + 1 <= c && c <= yfn)
        return var * var + z(n - 1, xst, midy + 1, midx, yfn);
    //cadranul 3
    if(midx + 1 <= l && l <= xfn && yst <= c && c <= midy)
        return  2 * var * var + z(n - 1, midx + 1, yst, xfn, midy);
    ///cadranul 4
    return 3 * var * var + z(n - 1, midx + 1, midy + 1, xfn, yfn);
}

int main() {
    ifstream fin("z.in");
    ofstream fout("z.out");
    fin >> n >> k;
    while(k --) {
        fin >> l >> c;
        /// 2^n = 1 << n
        fout << z(n, 1, 1, 1<<n, 1<<n) << '\n';
    }
}
