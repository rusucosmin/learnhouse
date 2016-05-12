#include <fstream>  ///fstream
#include <iostream>

using namespace std;

ifstream fin("adunare.in");     ///declaram fluxul de intrare din fisier
ofstream fout("adunare.out");   /// idem pentru fluxul de iesire din fisier

int main() {
    int a, b;
    fin >> a >> b;
    fout << a + b << '\n';
    return 0;
}
