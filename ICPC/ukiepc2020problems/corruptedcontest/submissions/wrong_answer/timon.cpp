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

int main() {
	int n, p;
	cin >> n >> p;
	vector<int> t(n), a(n);
	for(int i = 0; i < n; ++i) {
		cin >> t[i];
		if(t[i] == 0)
			a[i] = 0;
		else {
			if(t[i] < t[i - 1]) --p;
			a[i] = p;
		}
	}
	if(p != 1 || !is_sorted(a.rbegin(), a.rend())) {
		cout << "ambiguous" << endl;
	} else
		for(int v : a) cout << v << '\n';
}
