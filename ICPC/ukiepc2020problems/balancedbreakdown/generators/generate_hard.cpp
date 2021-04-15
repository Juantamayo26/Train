#include<cassert>
#include<cstdlib>
#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

ll p10[19];

ll solve(ll n) {
	vector<int> a;
	for (ll x = n; x; x /= 10)
		a.push_back(x % 10);
	int L = a.size();

	bool p = true;
	for (int i = L; i--; )
		p &= a[i] == a[L-1-i];

	if (p) return n;
	if (p10[L-1] == n) return n-1;

	ll hi = 0, lo = 0;
	for (int i = 0; i < (L+1)/2; i++)
		hi = hi*10 + a[L-1-i];
	for (int i = L/2; i--; )
		lo = lo*10 + a[L-1-i];

	if (hi*p10[L/2] + lo <= n)
		return hi*p10[L/2] + lo;
	lo = 0;
	for (ll x = --hi / ((L&1)?10:1); x; x /= 10)
		lo = 10LL*lo + (x%10);
	return hi*p10[L/2] + lo;
}

const int N = 10'000'000;
int prv[N], nneeded[N];

int main(int argc, char **argv) {
	// Usage: ./a.out n_lo n_hi {seed}
	assert(argc == 4);
	ll n_lo = stoll(argv[1]);
	ll n_hi = stoll(argv[1]);
	srand(stoll(argv[3]));

	p10[0] = 1;
	for (int i = 1; i <= 18; i++)
		p10[i] = p10[i-1] * 10;

	nneeded[0] = 0;
	for (int n = 1; n < N; n++) {
		prv[n] = solve(n);
		nneeded[n] = 1 + nneeded[n - prv[n]];
		// if (nneeded[n] >= 5) cout << n << ": " << nneeded[n] << endl;
	}

	while (true) {
		ll num = (ll(rand()) * RAND_MAX + rand()) % p10[18];
		int nr = 0;
		ll x = num;
		for (x = num; x >= N; x -= solve(x)) {
			nr++;
		}
		nr += nneeded[nr];
		if (nr + nneeded[x] >= 8) {
			cout << "Nice " << (nr + nneeded[x]) << ": " << num  << endl;
		}
	}
	return 0;
}
