#include <bits/stdc++.h>
using namespace std;
//template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

vi read(int n) {
    vi arr(n);
    rep(i,0,n) {
        string s;
        cin >> s;
        if (s == "?") {
            arr[i] = 0;
            continue;
        }

        int k;
        cin >> k;
        k *= 4;
        if (s == "n") k += 0;
        if (s == "w") k += 1;
        if (s == "e") k += 2;
        if (s == "s") k += 3;

        arr[i] = k;
    }
    return std::move(arr);
}

int main() {
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vi a = read(n),
	   b = read(m);

	int r = 0;
	rep(i,0,n-m+1) {
		bool ok = true;
		rep(j,0,m) {
			if (a[i+j] == 0) continue;
			if (b[j] == 0) continue;
			if (a[i+j] != b[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			r++;
		}
	}
	cout << r << endl;

	return 0;
}

