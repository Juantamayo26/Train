#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

template <typename T>
void subset_sort(std::vector<T>& v, std::vector<int> is) {
	std::vector<T> w;
	for(int i : is) w.emplace_back(v[i]);
	std::sort(w.begin(), w.end());
	for(int j = 0; j < is.size(); ++j) v[is[j]] = w[j];
}

int main() {
	// input
	int n, m;
	std::cin >> n;
	m = n / 4;
	std::vector<int> v(n);
	for(int i = 0; i < n; ++i) std::cin >> v[i];

	// output function calls
	std::cout << "3" << std::endl;

	for(int j = 0; j < 3; ++j) {
		// compute inverse map
		std::vector<std::pair<int, int>> s;
		for(int i = 0; i < n; ++i) s.emplace_back(v[i], i);
		std::sort(s.begin(), s.end());

		// determine subvector
		std::set<int> out;
		for(int i = j * m; out.size() < 2 * m; ++i) {
			out.insert(i);
			out.insert(s[i].second);
		}

		// output subvector
		for(int i : out) std::cout << (i + 1) << " ";
		std::cout << std::endl;

		// apply sort
		subset_sort(v, std::vector(out.cbegin(), out.cend()));
	}
}
