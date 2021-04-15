#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[1005];
int B[1005];
int C[1005];
int D[1005];

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) cin >> A[i];
	for (int i = 0; i < K; i++) cin >> B[i];
	C[0] = B[0] - A[0];
	int low = min(0, C[0]);
	for (int i = 1; i < K; i++) {
		C[i] = C[i - 1] + (B[i] - A[i]);
		low = min(low, C[i]);
	}
	D[0] = -low;
	for (int i = 1; i <= K; i++) D[i] = C[i - 1] + D[0];
	int T = 0;
	for (int i = 0; i <= K; i++) T += D[i];

	int M = 0;
	bool change = true;
	while (change) {
		change = false;
		for (int i = 0; i < 2 * K; i++) {
			int j = (i <= K ? i : 2 * K - i);
			if (D[j] == 0) continue;
			if (j == 0 && A[0] > 2) {
				int r = min(D[j], A[0] - 2);
				D[j] -= r; M += r; A[0] -= r;
				change = true;
			}
			else if (j == K && A[K-1] <= N-2) {
				int r = min(D[j], N - A[K-1] - 1);
				D[j] -= r; M += r; A[K - 1] += r;
				change = true;
			}
			else {
				if (A[j] - A[j - 1] >= 4) {
					int r = min(D[j], (A[j] - A[j-1])/2 - 1);
					D[j] -= r; M += r; A[j] -= r; A[j - 1] += r;
					change = true;
				}
			}
		}
	}

	if (M == T) cout << T << endl;
	else cout << "impossible" << endl;

	return 0;
}