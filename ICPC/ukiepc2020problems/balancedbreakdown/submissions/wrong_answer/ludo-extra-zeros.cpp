#include<iostream>
#include<set>
#include<vector>
using namespace std;

#define REP(i,n) for (int i=1;i<(n); i++)
typedef long long ll;

int main() {
	srand(31415);

	ll n, m;
	cin >> n;

	set<int> smalls;
	REP(a, 10) {
		for (int x : {a, 11*a}) smalls.insert(x);
		REP(b, 10) {
			for (int x : {101*a + 10*b, 1001*a + 110*b })
				smalls.insert(x);
			REP(c, 10)
				for (int x : { 10001*a + 1010*b + 100*c, 100001*a + 10010*b + 1100*c })
					smalls.insert(x);
		}
	}

	vector<ll> res;
	while (n) {
		if (n < 1'000'000) {
			m = *(--smalls.upper_bound(n));
		} else {
			ll p = 1LL;
			while (p <= n) p *= 10;
			ll hi = n / (p / 1000) + 1;
			do {
				if (--hi == 100) { m = p/10-1; break; }
				m = hi * (p / 1000) + 100*(hi%10) + 10*((hi/10)%10) + (hi/100)%10;
			} while (m > n);
		}
		res.push_back(m);
		n -= m;
	}

	cout << res.size() << endl;
	for (ll x : res) {
		// pad with some zeros
		if (rand() % (1 + (x % 10)) == 0)
			cout << '0';
		cout << x << endl;
	}
	return 0;
}
