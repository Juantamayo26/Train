#include <iostream>
using namespace std;
int main() {
	long long c, e, m;
	cin >> c >> e >> m;
	for(long long w = 2; (w-2)*(w-2) <= m; ++w) {
		long long h = (e-2*(w-2))/2+2;
		if(c == 4 and e == 2 * (w - 2 + h - 2) and m == (w - 2) * (h - 2)) {
			cout << w << ' ' << h << endl;
			return 0;
		}
	}
	cout << "impossible\n";
}
