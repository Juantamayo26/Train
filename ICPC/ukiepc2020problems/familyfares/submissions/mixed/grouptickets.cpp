// @EXPECTED_RESULTS@: WRONG_ANSWER, TIME_LIMIT_EXCEEDED
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
typedef vector<vector<pair<int, int>>> vvpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;
typedef vector<int> vi;

const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int>& d, vector<int>& p) {
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);
	vector<bool> u(n, false);

	d[s] = 0;
	for(int i = 0; i < n; i++) {
		int v = -1;
		for(int j = 0; j < n; j++) {
			if(!u[j] && (v == -1 || d[j] < d[v])) v = j;
		}

		if(d[v] == INF) break;

		u[v] = true;
		for(auto edge : adj[v]) {
			int to  = edge.first;
			int len = edge.second;

			if(d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
}

int main() {
	int n, m, p, g;
	cin >> n >> m >> p >> g;

	vi v_start;
	for(int i = 0; i < p; i++) {
		int x;
		cin >> x;
		v_start.push_back(x - 1);
	}

	for(int i = 0; i < n; i++) { adj.push_back(vpii()); }

	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1].push_back(pii(b - 1, c));
		adj[b - 1].push_back(pii(a - 1, c));
	}

	vi dist, pred;

	dijkstra(0, dist, pred);

	bool is_shortest[n][p];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < p; j++) { is_shortest[i][j] = false; }
	}

	for(int i = 0; i < p; i++) {
		int cur_v = v_start[i];
		while(cur_v != 0) {
			is_shortest[cur_v][i] = true;
			cur_v                 = pred[cur_v];
		}
	}

	int cost[n];
	for(int v = 0; v < n; v++) {
		int sum = 0;
		for(int i = 0; i < p; i++) {
			if(is_shortest[v][i]) {
				sum += dist[v_start[i]] - dist[v] + g;
			} else {
				sum += dist[v_start[i]];
			}
		}
		cost[v] = sum;
	}

	int all_sep = 0;
	for(int i = 0; i < p; i++) { all_sep += dist[v_start[i]]; }

	int min_cost = all_sep;
	for(int v = 0; v < n; v++) { min_cost = min(min_cost, cost[v]); }

	cout << min_cost << endl;

	return 0;
}
