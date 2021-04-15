#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll C, E, M;

int main() {
	cin >> C >> E >> M;
	if (C != 4) {
		cout << "impossible" << endl;
		return 0;
	}
	C += E;
	M += C;

	for (ll i = 2; i * i <= M; i++) {
		if (M % i != 0) continue;
		if (2 * (i + M / i) - 4 == C) {
			cout << (M / i) << " " << i << endl;
			return 0;
		}
	}

	cout << "impossible" << endl;

	return 0;
}