#include <iostream>

using namespace std;

int main() {
    int nr, n;

    cout << "Introduceti un numar: ";
    cin >> nr;


    if(nr == 1) { /// daca utilizatorul a introdus 1
        cout << "Introduceti inaltimea piramidei: ";
        cin >> n;
        for(int linie = n - 1 ; linie >= 1 ; linie --) {
            int nrstelute = 2*linie - 1;
            int nrdiez = (2*n - 1 - nrstelute) / 2;
            for(int coloana = 1 ; coloana <= nrdiez ; ++ coloana)
                cout << "#";
            for(int coloana = 1 ; coloana <= nrstelute ; ++ coloana)
                cout << "*";
            for(int coloana = 1 ; coloana <= nrdiez ; ++ coloana)
                cout << "#";
            cout << endl;
        }
        cout << endl;
    }
    else if(nr == 2) {
        cout << "Introduceti n: ";
        cin >> n;
        for(int i = 1 ; i <= n; ++ i)
            cout << i << ' ';
        cout << endl;
    }
    else if(nr == 3) {
        cin >> n;
        cout << "Primele " << n << " numere naturale pare (in ordine descrescatoare) sunt: ";
        for(int i = 2*n ; i >= 2 ; i -= 2)
            cout << i << ' ';
    }
    cout << "La revedere!\n";
}

