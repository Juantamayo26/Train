#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
	ll t, w;
	Edge(ll t_, ll w_) { t = t_; w = w_; };
};

struct Node {
	vector<Edge> adj;
	vector<int> parent;
	vector<int> sp;
	int famCount;
	ll dist;
	bool counted;
};

struct NodeDist {
	ll v, d;
	NodeDist(ll v_, ll d_) { v = v_; d = d_; };
	bool operator<(const NodeDist& r) const {
		return r.d < d;
	}
};

int N, M, P, G;
Node V[1005];


void Dijkstra(int v) {
	priority_queue<NodeDist> Q;
	V[v].dist = 0;
	Q.push(NodeDist(v, 0));
	while (!Q.empty()) {
		NodeDist nd = Q.top(); Q.pop();
		if (V[nd.v].dist < nd.d) continue;
		for (int i = 0; i < V[nd.v].adj.size(); i++) {
			Edge e = V[nd.v].adj[i];
			ll newD = nd.d + e.w;
			if (newD < V[e.t].dist) {
				V[e.t].dist = newD;
				V[e.t].parent.clear(); V[e.t].parent.push_back(nd.v);
				Q.push(NodeDist(e.t, newD));
			}
			else if (newD == V[e.t].dist) {
				V[e.t].parent.push_back(nd.v);
			}
		}
	}
}


int count(int v) {
	if (V[v].counted) return 0;
	V[v].counted = true;
	int r = V[v].famCount;
	for (int i = 0; i < V[v].sp.size(); i++) {
		r += count(V[v].sp[i]);
	}
	return r;
}


int main() {
	cin >> N >> M >> P >> G;
	for (int i = 0; i < N; i++) {
		V[i].adj.clear(); V[i].parent.clear(); V[i].sp.clear(); V[i].famCount = 0; V[i].dist = LLONG_MAX;
	}
	for (int i = 0; i < P; i++) {
		int k;
		cin >> k;
		V[k - 1].famCount++;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		V[a].adj.push_back(Edge(b, c));
		V[b].adj.push_back(Edge(a, c));
	}
	Dijkstra(0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < V[i].parent.size(); j++) {
			int k = V[i].parent[j];
			V[k].sp.push_back(i);
		}
	}

	ll T = 0;
	for (int i = 0; i < N; i++) T += V[i].dist * V[i].famCount;

	ll opt = T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) V[j].counted = false;
		int k = count(i);
		ll cost = T - k * V[i].dist + k * G;
		opt = min(opt, cost);
	}

	cout << opt << endl;

	return 0;
}