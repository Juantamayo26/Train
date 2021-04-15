// Stop simulation after STEPS steps, and print the computed answer.
#include <cassert>
#include <functional>
#include <iostream>
#include <numeric>
#include <optional>
#include <vector>
using namespace std;

int STEPS = 10'000'000;

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

	auto expected_answer = [&] {
		vector<long long> m(k + 1, 0);
		long long minl = 0;
		optional<long long> fixl;
		for(long long i = 0; i < k; ++i) {
			if(fixed[i]) {
				long long targetl = -m[i];
				if(fixl and *fixl != targetl) impossible();
				fixl = targetl;
			}
			m[i + 1] = t[i] - s[i] + m[i];
			minl     = max(minl, -m[i + 1]);
		}
		cout << accumulate(begin(m), end(m), 0ll) + (k + 1) * minl << endl;
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
			while(s[i - 1] >= s[i] - 3) left(i - 1);
			s[i - 1] += 1;
			s[i] -= 1;
			ans += 1;
			assert(s[i] - s[i - 1] >= 2);
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
		if(ans > STEPS) expected_answer();
	}

	cout << ans << endl;
}
