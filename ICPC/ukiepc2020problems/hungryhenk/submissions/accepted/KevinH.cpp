#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
	cin >> N;
	string S;
	getline(cin, S);
	getline(cin, S);
	for (int i = 0; i < S.length(); i++) if (S[i] == ' ') S[i] = '\n';
	cout << S << endl;
	return 0;
}