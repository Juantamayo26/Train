#include<iostream>
#include<cstdlib>
using namespace std;

// Based on accepted/ludo.cpp
int main() {
	int n, d;
	cin >> n;
	string word;
	// This tries to skip all lines, but "accidentally" skips all lines...
	while (n--) {
		cin >> d;
		while (d--) cin >> word;
	}
	// ...causing this read to wait forever
	cin >> d;
	cout << d << endl;
	while (d--) {
		cin >> word;
		cout << word << endl;
	}
	return 0;
}
