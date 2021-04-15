#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
	ll a, b, w;
	Edge(ll a_, ll b_, ll w_) { a = a_; b = b_; w = w_; };
	bool operator<(const Edge& r) const {
		return (w < r.w);
	}
};

int N, M;
vector<Edge> E;
int R[100005];
int P[100005];

int findSet(int x) {
	if (P[x] == x) return x;
	else {
		P[x] = findSet(P[x]);
		return P[x];
	}
}

void unite(int x, int y) {
	int a = findSet(x);
	int b = findSet(y);
	if (a == b) return;

	if (R[a] > R[b]) P[b] = a;
	else if (R[b] > R[a]) P[a] = b;
	else {
		R[a]++;
		P[b] = a;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		ll k, w;
		cin >> k >> w;
		E.push_back(Edge(0, k, w));
	}
	for (int i = 0; i < N; i++) {
		ll w;
		cin >> w;
		if (i < N-1) E.push_back(Edge(i+1, i+2, w));
		else E.push_back(Edge(1, N, w));
	}

	for (int i = 0; i <= N; i++) {
		R[i] = 0; P[i] = i;
	}

	sort(E.begin(), E.end());
	ll W = 0;
	for (int i = 0; i < E.size(); i++) {
		if (findSet(E[i].a) == findSet(E[i].b)) continue;
		unite(E[i].a, E[i].b);
		W += E[i].w;
	}

	cout << W << endl;

	return 0;
}