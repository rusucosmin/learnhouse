#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("date.in");
    ofstream fout("date.out");
    int n;
    fin >> n;
    for(int i = 1 ; i <= n / 2 ; ++ i) { /// fixam fiecare divizor in complexitate O(N)
        if(n % i == 0) /// daca restul impartirii lui n la i este 0->i divizor a lui n
            fout << i << ' ';
    }
    fout << n << ' ';
    return 0;
}
