#include<cassert>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	vector<int> T(n), nsolved(n+1, 0);
	for (int &x : T) cin >> x;

	T.push_back(0);

	for (int i=n-1; i >= 0; i--) {
		if (T[i] > T[i+1]) {
			nsolved[i] = nsolved[i+1] + 1;
		} else {
			nsolved[i] = nsolved[i+1];
		}

		if (T[i] == 0)
			assert(nsolved[i] == 0);
	}

	assert(nsolved[0] <= p);

	if (0 < nsolved[0] && nsolved[0] < p) {
		cout << "ambiguous" << endl;
	} else {
		for (int i=0; i<n; i++)
			cout << nsolved[i] << endl;
	}
	return 0;
}
