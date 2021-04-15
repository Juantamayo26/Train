#include<iostream>
using namespace std;
typedef long long ll;

int main() {
	ll corners, edges, middles;
	cin >> corners >> edges >> middles;

	if (corners != 4 || edges % 2 == 1) {
		cout << "impossible" << endl;
		return 0;
	}

	ll area = corners + edges + middles;
	ll w_and_h = edges/2 + corners;
	cerr << area << " " << w_and_h << endl;
	for (ll h = 2; h * h <= area && h + h <= w_and_h; h++) {
		ll w = w_and_h - h;
		if (w*h == area) {
			cout << w << " " << h << endl;
			return 0;
		}
	}
	cout << "impossible" << endl;
	return 0;
}
