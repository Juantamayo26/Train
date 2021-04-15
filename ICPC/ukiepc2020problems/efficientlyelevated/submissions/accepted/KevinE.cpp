#include <bits/stdc++.h>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct Point {
	int x, y, h;
	Point(int x_, int y_, int h_) { x = x_; y = y_; h = h_; };
	bool operator<(const Point& r) const {
		return (h < r.h);
	}
};

int H, W;
int A[505][505];
bool done[505][505];
priority_queue<Point> Q;

void floodfill(int x, int y) {
	if (x < 0 || x >= W || y < 0 || y >= H || done[x][y]) return;
	done[x][y] = true;
	for (int i = 0; i < 4; i++) {
		if (A[x + dx[i]][y + dy[i]] <= A[x][y]) floodfill(x + dx[i], y + dy[i]);
	}
}

int main() {
	cin >> H >> W;
	for (int j = 0; j < H; j++) {
		for (int i = 0; i < W; i++) {
			cin >> A[i][j];
			done[i][j] = (A[i][j] <= 1);
			Q.push(Point(i, j, A[i][j]));
		}
	}

	int C = 0;
	while (!Q.empty()) {
		Point p = Q.top();
		Q.pop();
		if (!done[p.x][p.y]) {
			C++;
			floodfill(p.x, p.y);
		}
	}

	cout << C << endl;

	return 0;
}