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
	while (t < total) {
		if (i == 0) {
			if (ss[i] == 0 || p[i] < 3) {
				i++;
			}
			else {
				p[i]--;
				ss[i]--;
				t++;
			}
		}
		else if (i < k) {
			if (ss[i] == 0 || p[i] - p[i - 1] < 4) {
				i++;
			}
			else {
				p[i - 1]++;
				p[i]--;
				ss[i]--;
				t++;
				if (ss[i - 1] > 0) i--;
			}
		}
		else { // i == k
			if (ss[i] == 0 || n - p[i - 1] < 2) {
				cout << "impossible" << endl;
				return 0;
			}
			else {
				p[i - 1]++;
				ss[i]--;
				t++;
				if (ss[i - 1] > 0) i--;
			}
		}
	}
	cout << total << endl;
	return 0;
}
