#include <iostream>

using namespace std;

int main() {
    int n;
        /**

        s = 0, nr = 1
        
        Alg1:
        while(s > 0) {
            ++ nr;
            s -= 10;
        }

        Alg2:
        if(s > 0) {
            do {
                ++ nr;
                s -= 10;
            }while(s > 0);
        }
    */

    int op, cn, sum, pr, cnt;
    int stop = 0;
    while(stop == 0) {
        cout << "Meniu\n";
        cout << "1. Suma cifrelor\n";
        cout << "2. Produsul cifrelor\n";
        cout << "3. Numarul cifrelor\n";
        cout << "4. Numarul cifrelor nule\n";
        cout << "5. Iesire\n";
        cout << "Introdu operatia: ";
        cin >> op;
        if(op != 5) {
            cout << "Introdu n: ";
            cin >> n;
        }
        switch(op) {
        case 1:
            sum = 0;
            cn = n;
            while(cn > 0) {              //// cat timp n mai are cifre
                sum = sum + cn % 10;     //// adaugam ultima cifra la suma
                cn = cn / 10;
            }
            cout << "Suma cifrelor numarului " << n << " este " << sum << '\n';
            break;
        case 2:
            pr=1;
            cn=n;
            do {
                pr=pr*(cn%10);
                cn=cn/10;
            }while(cn > 0);
            cout << "Produsul cifrelor numarului " << n << " este " << pr << '\n';
            break;
        case 3:
            cnt = 0;
            cn = n;
            do {
                cnt ++;
                cn /= 10; /// echivalent cu cn = cn / 10 (prescuratare)
            }while(cn > 0);
            cout << "Numarul cifrelor numarului " << n << " este " << cnt << '\n';
            break;
        case 4:
            cnt = 0;
            cn = n;
            do {
                if(cn % 10 == 0)
                    cnt ++;
                cn = cn / 10;
            } while(cn > 0);
            cout << "Numarul cifrelor nule ale numarului " << n << " este " << cnt << '\n';
            break;
        case 5:
            stop = 1;
            break;
        default:
            cout << "Operatie invalida!\n";
        }
    }
    cout << "Le revedere\n";
}

