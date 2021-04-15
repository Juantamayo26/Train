#include<algorithm>
#include<climits>
#include<iostream>
#include<queue>
#include<utility>
using namespace std;

int H[501][501];
bool gmax[501][501] = {};

struct UF {
	vector<int> par;
	vector<bool> dom;

	UF(int n) : par(n, -1), dom(n, false) {}

	void domd(int x) {
		dom[ find(x) ] = true;
	}
	int find(int x) {
		return par[x] < 0 ? x : par[x] = find(par[x]);
	}
	void merge(int a, int b) {
		if ((a = find(a)) == (b = find(b))) return;
		if (par[b] < par[a]) swap(a, b);
		par[a] += par[b];
		dom[a] = dom[a] | dom[b];
		par[b] = a;
	}
};

int main() {
	int a,b;
	cin >> a >> b;

	for (int i=0; i<a; i++)
		for (int j=0; j<b; j++)
			cin >> H[i][j];

	// WA: not handling height 1 buildings correctly
	if (*max_element(&H[0][0], &H[a][0]) <= 1) {
		cout << 0 << endl;
		return 0;
	}

	UF dsu(a*b);

	for (int i=0; i<a; i++) {
		for (int j=1; j<b; j++) {
			if (H[i][j] == H[i][j-1]) dsu.merge(i*b + j, i*b + (j-1));
			if (H[i][j]  < H[i][j-1]) dsu.domd(i*b + j);
			if (H[i][j]  > H[i][j-1]) dsu.domd(i*b + j-1);
		}
	}

	for (int i=1; i<a; i++) {
		for (int j=0; j<b; j++) {
			if (H[i][j] == H[i-1][j]) dsu.merge(i*b + j, (i-1)*b + j);
			if (H[i][j]  < H[i-1][j]) dsu.domd(i*b + j);
			if (H[i][j]  > H[i-1][j]) dsu.domd((i-1)*b + j);
		}
	}

	int res = 0;
	for (int i=0; i < a*b; i++)
		res += dsu.par[i] < 0 && !dsu.dom[i]; // WA: && H[i/b][i%b] > 1;

	cout << res << endl;
	return 0;
}
