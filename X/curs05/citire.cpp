#include <iostream>

using namespace std;

void citire() {
    char ch;
    cin.get(ch);
    if(ch != 'x')
        citire();
    cout << ch;
}

void printbase(int n, int base) {
    if(n > 0) {
        printbase(n / base, base);
        if(n % base < 10)
            cout << n % base;
        else
            cout << (char)((n % base - 10) + 'A');
    }
}

int main() {
    printbase(2568, 16);
}
