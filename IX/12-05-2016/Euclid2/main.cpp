#include <iostream>
#include <fstream>

using namespace std;

    /*
    /// cu scaderi
    while(a != b) {
        if(a > b)
            a = a - b;
        else /// b < a
            b = b - a;
    }
    /// while-ul s-a oprit, deci a != b e false
    /// => a == b
    fout << a << '\n';
    */

int main() {
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int t;
    fin >> t;

    for(int i = 1; i <= t; ++ i) {
        int a, b;
        fin >> a >> b;

        int r;
        while(a != 0) {
            r = b % a;
            b = a;
            a = r;
        }
        fout << b << '\n';
    }
    return 0;
}
