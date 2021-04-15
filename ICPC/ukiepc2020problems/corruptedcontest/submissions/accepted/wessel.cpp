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
	std::vector<int> t(n);
	std::vector<int> a(n, 0);

	for(int i = 0; i < n; i++) cin >> t[i];

	// first 0's
	int start = n;
	for(int i = n - 1; i >= 0; i--) {
		if(t[i] != 0) {
			start = i;
			break;
		}
	}

	// special all zeros, shouldn't be possible
	if(start == n) {
		//std::cout << "ambiguous" << std::endl;
		for(int i = 0; i < n; i++) std::cout << a[i] << std::endl;
		return 0;
	}

	// forward
	int pid  = 1;
	a[start] = pid;
	for(int i = start - 1; i >= 0; i--) {
		if(t[i] > t[i + 1]) pid++;
		a[i] = pid;
	}

	if(a[0] == p) {
		// good
		for(int i = 0; i < n; i++) { std::cout << a[i] << std::endl; }
	} else {
		std::cout << "ambiguous" << std::endl;
	}

	return 0;
}
