#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	long long sum = 0;
	cin >> n;
	for(int d1 = 1 ; d1 * d1 <= n ; ++ d1)
		if(n % d1 == 0) {
			if(d1 % 2 == 1)
 				sum = sum + d1;
			int d2 = n / d1;
			if(d2 != d1 && d2 % 2 == 1)
				sum += d2;
		}
	cout << sum;
	return 0;
}
