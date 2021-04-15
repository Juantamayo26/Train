#include <cassert>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> s(k), t(k);
	for(auto& x : s) cin >> x;
	for(auto& x : t) cin >> x;

	vector<bool> fixed(n, false);
	for(int i = 0; i < k - 1; ++i)
		if(t[i + 1] == t[i] + 1) fixed[i] = fixed[i + 1] = true;

	auto impossible = [] {
		cout << "impossible\n";
		exit(0);
	};

	int ans = 0;

	std::function<void(int)> left, right;

	left = [&](int i) {
		if(fixed[i]) impossible();
		if(i == 0) {
			if(s[i] <= 2) impossible();
			s[i] -= 1;
			ans += 1;
		} else {
			if(s[i - 1] >= s[i] - 3)
				left(i - 1);
			else {
				s[i - 1] += 1;
				s[i] -= 1;
				ans += 1;
				assert(s[i] - s[i - 1] >= 2);
			}
		}
	};

	right = [&](int i) {
		if(fixed[i]) impossible();
		if(i == k - 1) {
			if(s[i] >= n - 1) impossible();
			s[i] += 1;
			ans += 1;
		} else {
			while(s[i] >= s[i + 1] - 3) right(i + 1);
			s[i] += 1;
			s[i + 1] -= 1;
			ans += 1;
			assert(s[i + 1] - s[i] >= 2);
		}
	};

	while(s != t) {
		for(int i = 0; i < k; ++i) {
			while(s[i] > t[i]) left(i);
			while(s[i] < t[i]) right(i);
		}
	}

	cout << ans << endl;
}
