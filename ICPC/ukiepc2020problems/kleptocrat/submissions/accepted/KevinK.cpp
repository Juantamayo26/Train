#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

struct Edge {
	ull t, w;
	Edge(ull t_, ull w_) { t = t_; w = w_; };
};

struct Node {
	vector<Edge> adj;
	bool visited;
	ull label;
};

int N, M, Q;
Node V[10005];
vector<ull> cycles;

void computeLabels(int v, ull label) {
	if (V[v].visited) {
		cycles.push_back(label ^ V[v].label);
		return;
	}
	V[v].visited = true;
	V[v].label = label;
	for (int i = 0; i < V[v].adj.size(); i++) {
		Edge e = V[v].adj[i];
		computeLabels(e.t, label ^ e.w);
	}
}

int main() {
	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) {
		V[i].adj.clear(); V[i].label = 0ull; V[i].visited = false;
	}
	for (int i = 0; i < M; i++) {
		ull a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		V[a].adj.push_back(Edge(b, w));
		V[b].adj.push_back(Edge(a, w));
	}

	cycles.clear();
	computeLabels(0, 0ull);

	sort(cycles.begin(), cycles.end(), greater<ull>());
	if (cycles.size() > 0) {
		int cur = 0;
		for (ull x = (1ull << 60); x > 0ull; x /= 2ull) {
			int r = -1;
			for (int i = cur; i < cycles.size(); i++) {
				if ((cycles[i] & x) > 0ull) {
					r = i; 
					break;
				}
			}
			if (r >= 0) {
				ull h = cycles[cur]; cycles[cur] = cycles[r]; cycles[r] = h;
				for (int i = cur+1; i < cycles.size(); i++) {
					if ((cycles[i] & x) > 0ull) cycles[i] = cycles[i] ^ cycles[cur];
				}
				cur++;
			}
		}
		while (cycles.size() > 0 && cycles[cycles.size() - 1] == 0ull) cycles.pop_back();
	}

	for (int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		ull lab = V[a].label ^ V[b].label;
		for (int j = 0; j < cycles.size(); j++) {
			lab = min(lab, lab ^ cycles[j]);
		}
		cout << lab << endl;
	}

	return 0;
}