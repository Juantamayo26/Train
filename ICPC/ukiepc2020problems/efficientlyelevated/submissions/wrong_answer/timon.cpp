#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using vi  = vector<int>;
using vvi = vector<vi>;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
struct xy {
	int x, y;
};
struct X {
	int val;
	xy pos;
	bool operator<(const X& o) { return val > o.val; }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	vvi E(n, vi(m));
	vector<X> Xs;
	for(int x = 0; x < n; ++x)
		for(int y = 0; y < m; ++y) cin >> E[x][y], Xs.push_back(X{E[x][y], xy{x, y}});

	int ans = 0;
	sort(Xs.begin(), Xs.end());
	for(auto& xs : Xs) {
		if(E[xs.pos.x][xs.pos.y] < 0) continue;
		queue<xy> q;
		q.push(xs.pos);
		++ans;
		while(!q.empty()) {
			xy u = q.front();
			q.pop();
			if(E[u.x][u.y] < 0) continue;
			for(int i = 0; i < 4; ++i) {
				int nx = u.x + dx[i], ny = u.y + dy[i];
				if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if(E[u.x][u.y] >= E[nx][ny]) q.push(xy{nx, ny});
			}
			E[u.x][u.y] = -1;
		}
	}
	cout << ans << endl;
}
