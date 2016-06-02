#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("maxsecv.in");
    ofstream fout("maxsecv.out");

    int n, cnt = 0;
    int max1 = 0, max2 = 0;
    fin >> n;
    for(int i = 1; i <= n; ++ i) {
        int x;
        fin >> x;
        if(x == 0) {
            if(max1 < cnt) {
                max2 = max1;
                max1 = cnt;
            }
            else if(max2 < cnt)
                max2 = cnt;
            cnt = 0;
        }
        else
            ++ cnt;
    }
    if(max1 < cnt) {
        max2 = max1;
        max1 = cnt;
    }
    else if(max2 < cnt)
        max2 = cnt;
    fout << max1 + max2 << '\n';
    return 0;
}
