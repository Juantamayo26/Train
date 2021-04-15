#include<algorithm>
#include<cassert>
#include<climits>
#include<iostream>
#include<map>
#include<vector>

using namespace std;
using ll = long long;

ll p10[19];

vector<int> digits(ll n) {
	vector<int> dig;
	for (ll x = n; x; x /= 10)
		dig.push_back(x%10);
	return dig;
}

bool is_palin(ll n) {
	vector<int> dig = digits(n);
	for (int i = 0, j = dig.size() - 1; i < j; i++, j--)
		if (dig[i] != dig[j])
			return false;
	return true;
}

// returns the biggest (or one-to-biggest) m <= n which is a palindrome.
ll round_down(ll n) {
	assert(n > 0);
	if (is_palin(n))
		return n;

	vector<int> dig = digits(n);
	int ndig = dig.size();
	if (p10[ndig - 1] == n)
		return n-1; // 99..99

	ll hi = n / p10[ndig/2];
	if (hi == p10[(ndig-1)/2])
		return p10[ndig-1] + 1; // 100..001
	hi--;

	ll res = hi, rev = hi / (ndig % 2 == 1 ? 10 : 1);
	for (int i = 0; i < ndig/2; i++, rev /= 10)
		res = res * 10LL + (rev % 10);
	return res;
}

const int LIMIT = 200 * 1000;

/*
For n = 10^18, choose { n-1, 1 }.
Suppose now n < 10^18, then n has <=18 digits.
By taking the high half and subtracting one, and making the lower half the reverse of the higher half,
	we get a palindrome p s.t. n-p <= 2 * 10^9 and has <=10 digits.
Applying this twice, n - p_1 - p_2 <= 2 * 10^5 and has <= 6 digits.
*/

int main() {
	p10[0] = 1LL;
	for (int i=1; i < 19; i++)
		p10[i] = p10[i-1] * 10LL;

	// list of small palindromes:
	vector<int> ps;
	for (int num = 1; num < LIMIT; num++) {
		if (is_palin(num))
			ps.push_back(num);
	}

	// best[n] is a palindrome p s.t. n = p or n - p is a palindrome.
	vector<int> best(LIMIT, -1);
	for (int p : ps) {
		best[p] = p;
		for (int q : ps) {
			if (q > p || p+q >= LIMIT)
				break;
			best[p + q] = q;
		}
	}

	ll n;
	cin >> n;
	vector<ll> solution;

	// do this at most twice:
	for (int i = 0; i < 2 && n > 0; i++) {
		ll p = round_down(n);
		n -= p;
		solution.push_back(p);
	}

	assert(n < LIMIT);

	if (n > 0 && best[n] == -1) {
		// Claim: n is the sum of exactly 3 palindromes.
		for (int p : ps) {
			assert(p < n);
			if (best[n - p] != -1) {
				n -= p;
				solution.push_back(p);
				break;
			}
		}
	}

	// Claim: n is the sum of <= 2 palindromes.
	while (n > 0) {
		solution.push_back(best[n]);
		n -= best[n];
	}

	// Claim: solution contains 5 palindromes with sum equal to n.
	assert(solution.size() <= 5);
	cout << solution.size() << endl;
	for (ll num : solution)
		cout << num << endl;
	return 0;
}
