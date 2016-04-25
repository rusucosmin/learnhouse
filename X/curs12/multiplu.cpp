#include <fstream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

const char infile[] = "multiplu.in";
const char outfile[] = "multiplu.out";

ifstream fin(infile);
ofstream fout(outfile);

const int MAXN = 2000005;

int A, B, M, Father[MAXN], last[MAXN], K;

inline int GCD(int A, int B) {
    int r;
    while(A % B != 0) {
        r = A % B;
        A = B;
        B = r;
    }
    return B;
}

void Write(const int &Node) {
    if(Node != 1) {
        Write(Father[Node]);
    }
    fout << last[Node] - 1;
}

int main() {
    queue <int> Q;
    fin >> A >> B;                              // citim cele doua numere
    K = (A * B) / GCD(A, B);                    // calculam m
    Q.push(1);
    last[1] = 2;
    Father[1] = 1;
    while(!Q.empty() && last[0] == 0) {
        int actNumber = Q.front();
        Q.pop();
        for(int i = 0 ; i < 2 ; ++ i) {         /// luam cifra zero si unu
            int newNumber = (actNumber * 10 + i) % K;
            if(!last[newNumber]) {
                Father[newNumber] = actNumber;
                last[newNumber] = i + 1;
                Q.push(newNumber);
            }
        }
    }
    Write(0);
    fin.close();
    fout.close();
    return 0;
}
