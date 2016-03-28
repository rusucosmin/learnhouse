#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;    ///citim k
	int nc = n, r = 0;
	while(nc > 0) {
		r = r * 10 + nc % 10;
		nc = nc / 10;
	}
	if(r == n) {
		cout << "palindrom";
	}
	else
		cout << "nu e palindrom";
	return 0;
}
