#include<cassert>
#include<iostream>
using namespace std;
typedef long long ll;

const ll INF = 200'000'000'000'000LL; // 2 * 10^14
const int N = 100'000 + 1;

ll A[N], B[N];

// C[i] = cost to power cities 1...i,                  & 1,i disconnected.
// D[i] = cost to power cities 1...i, except i.        & 1,i disconnected.
// E[i] = cost to power cities 1...i, except 1         & 1,i disconnected.
// F[i] = cost to power cities 1...i, except 1 and i   & 1,i disconnected.
ll C[N], D[N], E[N], F[N];

int main() {
	int n, m;

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		A[i] = INF;
	while (m--) {
		int c, a;
		cin >> c >> a;
		A[c] = a;
	}
	for (int i=1; i<=n; i++)
		cin >> B[i];

	// input is read.

	C[1] = D[1] = E[1] = F[1] = INF;

	ll sumb = 0, mina = A[1];

	for (int i = 2; i <= n; i++) {
		D[i] = min(min(C[i-1], D[i-1] + B[i-1]), sumb + mina);
		F[i] = min(min(E[i-1], F[i-1] + B[i-1]), sumb);

		C[i] = min(C[i-1] + B[i-1], D[i] + A[i]);
		E[i] = min(E[i-1] + B[i-1], F[i] + A[i]);

		sumb = sumb + B[i-1];
		mina = min(mina, A[i]);
	}

	// for (int i=1; i <= n; i++) printf("%d: %lld %lld %lld %lld %lld %lld\n", i, A[i], B[i], C[i], D[i], E[i], F[i]);

	ll res = min(min(sumb + mina, D[n] + B[n]), min(C[n], E[n] + B[n]));
	assert(res < INF);
	cout << res << endl; 
	return 0;
}
