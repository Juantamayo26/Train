#include <bits/stdc++.h>

using namespace std;

int N, P;
int T[10005];
int S[10005];

int main() {
	cin >> N >> P;
	for(int i = 0; i < N; i++) cin >> T[i];
	T[N] = 0;

	if(T[0] == 0) {
		for(int i = 0; i < N; ++i) cout << 0 << endl;
		return 0;
	}

	int x = 0, y = N - 1;
	while(y >= 0) {
		if(T[y] > T[y + 1]) x++;
		S[y--] = x;
	}

	if(S[0] < P)
		cout << "ambiguous" << endl;
	else {
		for(int i = 0; i < N; i++) cout << S[i] << endl;
	}

	return 0;
}
