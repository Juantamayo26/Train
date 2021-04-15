#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000005];
int B[1000005];

void sortSubset() {
	vector<int> V;
	vector<int> V2;
	for (int i = 0; i < N; i++) {
		if (B[i] == 0) {
			V.push_back(A[i]);
			V2.push_back(i + 1);
		}
	}
	for (int j = 0; j < V2.size(); j++) {
		cout << V2[j];
		if (j < V2.size() - 1) cout << " ";
		else cout << endl;
	}
	sort(V.begin(), V.end());
	for (int i = 0, j = 0; i < N; i++) {
		if (B[i] == 0) A[i] = V[j++];
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	
	cout << "3" << endl;
	memset(B, 0, sizeof(int) * N);
	int C = 0;
	for (int i = N/4; i < N; i++) {
		if (A[i] > N / 4) {
			B[i] = 1; C++;
		}
		if (C == N / 2) break;
	}
	sortSubset();

	memset(B, 0, sizeof(int) * N);
	C = N/4;
	for (int i = 0; i < N / 4; i++) B[i] = 1;
	for (int i = N / 2; i < N; i++) {
		if (A[i] > N / 2) {
			B[i] = 1; C++;
		}
		if (C == N / 2) break;
	}
	sortSubset();

	memset(B, 0, sizeof(int) * N);
	for (int i = 0; i < N / 2; i++) B[i] = 1;
	sortSubset();

	return 0;
}