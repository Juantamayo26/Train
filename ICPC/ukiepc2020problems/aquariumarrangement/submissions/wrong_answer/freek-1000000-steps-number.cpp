#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
using vll = vector<ll>;

int main() {
	ll n, k;
	cin >> n >> k;
	vll p(k), d(k), ss(k + 1);
	for (ll i = 0; i < k; i++)
		cin >> p[i];
	for (ll i = 0; i < k; i++)
		cin >> d[i];
	ll mini = 0, total = 0;
	for (ll i = 1; i <= k; i++) {
		ll s = ss[i - 1] + d[i - 1] - p[i - 1];
		mini = min(mini, s);
		total += s;
		ss[i] = s;
	}
	for (ll i = 0; i <= k; i++)
		ss[i] -= mini;
	total -= mini * (k + 1);
	ll t = 0, i = 0;
	while (t < min(total, (ll) 1000000)) {
		if (i == 0) {
			if (ss[i] == 0 || p[i] < 3) {
				i++;
			}
			else {
				ll s = min(ss[i], p[i] - 2);
				p[i] -= s;
				ss[i] -= s;
				t += s;
				i++;
			}
		}
		else if (i < k) {
			if (ss[i] == 0 || p[i] - p[i - 1] < 4) {
				i++;
			}
			else {
				ll s = min(ss[i], (p[i] - p[i - 1] - 2) / 2);
				p[i - 1] += s;
				p[i] -= s;
				ss[i] -= s;
				t += s;
				i--;
			}
		}
		else { // i == k
			if (ss[i] == 0 || n - p[i - 1] < 2) {
				cout << "impossible" << endl;
				return 0;
			}
			else {
				ll s = min(ss[i], n - p[i - 1] - 1);
				p[i - 1] += s;
				ss[i] -= s;
				t += s;
				i--;
			}
		}
	}
	cout << total << endl;
	return 0;
}
