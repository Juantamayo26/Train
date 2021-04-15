#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

ll newton(__int128 a) {
	__int128 x = max(__int128(a), a / 100);
	for(int rep = 0; rep < 20 && x > 0; ++rep) x -= (x * x - a) / (2 * x);
	for(__int128 g = x - 3; g <= x + 3; ++g)
		if(g >= 0 && g * g == a) return (ll)g;
	return -1;
}

int main() {
	ll c, e, m;
	cin >> c >> e >> m;

	// w*h = c+e+m
	// 2w + 2h = c+e+4
	// 	=>	w = -h + 2 + (c+e)/2
	// 	=>	h(-h+2+(c+e)/2) = c+e+m
	// 	=>	-2h^2 + (4+c+e)h - 2(c+e+m) = 0

	__int128 D = __int128(4 + c + e) * __int128(4 + c + e) - 16 * __int128(c + e + m);
	if(c != 4 || e % 2 || D < 0) {
		cout << "impossible" << endl;
		exit(0);
	}

	ll sqd = newton(D);
	for(int co = -1; sqd >= 0 && co <= 1; co += 2) {
		ll h = (4 + c + e) + co * sqd;
		if(h < 2 || h % 4 > 0) continue;
		h /= 4;
		ll w = (c + e + m) / h;
		if(w * h == c + e + m && w >= 2 && c + e == 2 * (w + h) - 4) {
			cout << w << ' ' << h << endl;
			exit(0);
		}
	}
	cout << "impossible" << endl;
}
