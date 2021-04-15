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

int main() {
	p10[0] = 1;
	for (int i = 1; i <= 18; i++)
		p10[i] = p10[i-1] * 10;

	ll n, m;
	cin >> n;

	vector<ll> v;
	while (n) {
		m = solve(n);
		n -= m;
		v.push_back(m);
	}

	cout << v.size() << endl;
	for (ll x : v)
		cout << x << endl;
	return 0;
}
