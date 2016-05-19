#include <fstream>
/// File stream - pentru lucrul cu fisiere
#include <iostream>
/// Nu este nevoie, decat daca vrem sa afisam in consola
#include <iomanip>
/// pentru functia de precizie
/// setprecision() si fixed

using namespace std;

const int maxn = 1005;
/// lungimea maxima a sirului (vectorului)

int n; /// lungimea efectiva
int v[maxn]; /// vectorul propiru-zis

int main() {
    /// 'declaram' fisierele
    ifstream fin("date.in");
    ofstream fout("date.out");
    long long sum = 0, prod = 1;

    fin >> n;/// citim lungimea efectiva a vectorului
    for(int i = 0; i < n; ++ i) { /// pentru fiecare element de la 0 la n - 1
        fin >> v[i];        /// citim elementului i
    }
    for(int i = 0; i < n; ++ i) {
        sum += v[i];        /// sum = sum + v[i]; adaug v[i] la sum
        prod *= v[i];       /// prod = prod * v[i]; adaug v[i] la prod
    }
    fout << "suma este: " << sum << '\n'; /// afisam suma este: sum si linie noua
    fout << "produsul este: " << prod << '\n'; /// afisam produsul
    fout << fixed << setprecision(4) << "media este: " << (long double)sum / n << '\n';

    /// inchidem fisierele
    fin.close();
    fout.close();
    return 0;
}
