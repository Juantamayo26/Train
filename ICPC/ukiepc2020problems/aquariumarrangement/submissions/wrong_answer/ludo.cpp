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
	int n, k;
	cin >> n >> k;
	vector<int> p(k + 1), d(k + 1);
	for(int i = 0; i < k; i++) cin >> p[i];
	for(int i = 0; i < k; i++) cin >> d[i];

	p[k] = n - p[k - 1];
	d[k] = n - d[k - 1];

	for(int i = k - 1; i > 0; i--) {
		p[i] -= p[i - 1];
		d[i] -= d[i - 1];
	}

	p[0]--;
	d[0]--;

	/*
	    for (int i=0; i<=k; i++) cout << p[i] << " ";
	    cout << endl;
	    for (int i=0; i<=k; i++) cout << d[i] << " ";
	    cout << endl;
	*/

	int moves = 0;

	cerr << "Target: " << endl;
	for(int i = 0; i <= k; i++) cerr << d[i] << " ";
	cerr << endl;

	for(int i = 0; i <= k; i++) cerr << p[i] << " ";
	cerr << endl;
	for(int i = 0; i < 1'000'000; i++) { // 1'000'000; i++) {
		int lmoves = moves;
		while(p[0] >= 2 && p[0] > d[0]) {
			p[0]--;
			p[1]++;
			moves++;
		}
		for(int j = 1; j < k; j++) {
			while(p[j] > d[j] && p[j] >= 4) {
				p[j] -= 2;
				p[j - 1]++;
				p[j + 1]++;
				moves++;
			}
		}
		while(p[k] >= 2 && p[k] > d[k]) {
			p[k]--;
			p[k - 1]++;
			moves++;
		}

		if(p == d) {
			printf("%d\n", moves);
			return 0;
		}

		if(lmoves == moves) {
			if(p[0] >= 2) {
				p[0]--;
				p[1]++;
				moves++;
			} else if(p[k] >= 2) {
				p[k]--;
				p[k - 1]++;
				moves++;
			}
		}

		/* for (int i=0; i<=k; i++)
		    cerr << p[i] << " ";
		cerr << endl; */
	}

	puts("impossible");

	return 0;
}
