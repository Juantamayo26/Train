#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	int n, d;
	cin >> n;
	int nskip = rand() % n;
	string word;
	while (nskip--) {
		cin >> d;
		while (d--) cin >> word;
	}
	cin >> d;
	cout << d << endl;
	while (d--) {
		cin >> word;
		cout << word << endl;
	}
	return 0;
}
