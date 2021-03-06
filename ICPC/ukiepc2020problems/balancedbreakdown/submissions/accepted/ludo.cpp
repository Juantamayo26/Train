#include<algorithm>
#include<cassert>
#include<iostream>
#include<map>
#include<vector>

using namespace std;
using ll = long long;

ll p10[19];

int numlen(ll n) {
	int len = 0;
	while (p10[len] < n) len++;
	return len;
}

bool palindrome(ll n) {
	vector<int> dig;
	for (ll x = n; x; x /= 10)
		dig.push_back(x%10);

	for (int i=0, j = dig.size()-1; i<j; i++, j--)
		if (dig[i] != dig[j]) return false;
	return true;
}

ll merge(ll msb, int n) {
	ll lsb = 0, x = msb;
	if (n & 1) {
		x /= 10;
	}
	while (x) {
		lsb = lsb * 10 + (x % 10);
		x /= 10;
	}

	return msb * p10[n/2] + lsb;
}

bool valid_solution(ll n, vector<ll> v) {
	ll left = n;
	for (ll x : v) {
		if (!palindrome(x)) return false;
		left -= x;
	}
	return left == 0 && v.size() <= 3;
}

const int TABLE_SIZE = 100 * 1000;
int nr_palins[TABLE_SIZE], prv[TABLE_SIZE];

vector<ll> solve(ll n, int max_allowed = 3) {
	static map< ll, vector<ll> > cache;

	if (n < TABLE_SIZE) {
		vector<ll> res;
		while (n) {
			res.push_back(prv[n]);
			n -= prv[n];
		}
		return res;
	}

	if (palindrome(n)) return { n };

	int len = numlen(n);
	if (p10[len] == n) {
		// { 1, 99..9 }
		return { 1, n-1 };
	}

	if (cache.find(n) != cache.end()) return cache[n];

	ll msb = n / p10[len/2];
	ll both = merge(msb, len);

	int nlen = len;
	if (both > n) {
		// if (msb == p10[(len-1)/2]) nlen--;
		if (msb == p10[(len-1)/2]) {
			nlen--;
			msb = p10[len/2];
		}
		both = merge(--msb, nlen);
	}
	assert(both <= n);

	vector<ll> res = solve(n - both, max_allowed - 1);
	res.push_back(both);

	// Note: msb >= 100

	// The limit for this for-loop is a bit sketchy...
	// Not sure if this always produces the right answer...
	for (int rep = 0; rep < 99; rep++) {
		// For faster performance but worse output:
		// if (res.size() <= max_allowed) break;

		// Sanity check:
		// if (msb == p10[(len-1)/2]) break;
		if (msb == p10[(len-1)/2]) {
			nlen--;
			msb = p10[len/2];
		}

		both = merge(--msb, nlen);
		vector<ll> alt = solve(n - both, max_allowed - 1);
		alt.push_back(both);
		if (alt.size() < res.size())
			res = alt;
	}

	return cache[n] = res;
}

int main() {
	p10[0] = 1;
	for (int i=1; i <= 18; i++)
		p10[i] = p10[i-1] * 10;

	vector<int> palins;
	for (int n = 1, len = 1, pow = 10; n < 1000; n++) {
		if (n == pow) len++, pow *= 10;
		palins.push_back(merge(n, len*2));
		palins.push_back(merge(n, len*2-1));
	}

	sort(begin(palins), end(palins));

	nr_palins[0] = prv[0] = 0;
	for (int n = 1; n < TABLE_SIZE; n++) {
		auto it = upper_bound(begin(palins), end(palins), n);
		int best = 1, value = nr_palins[n-1];
		do {
			if (it == begin(palins)) {
				break;
			}
			--it;
			if (nr_palins[n - *it] < value) {
				best = *it;
				value = nr_palins[n - best];
			}
		} while (value >= 2);
		nr_palins[n] = value + 1;
		prv[n] = best;
	}

	ll n;
	cin >> n;

	vector<ll> ans = solve(n);
	// You may try to break this:
	assert(ans.size() <= 3);
	cout << ans.size() << endl;
	for (ll x : ans)
		cout << x << endl;
	return 0;
}
