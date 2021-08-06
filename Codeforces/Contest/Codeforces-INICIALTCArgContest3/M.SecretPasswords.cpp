// time-limit: 1000
// problem-url: https://codeforces.com/group/gXivUSZQpn/contest/336660/problem/M
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define sz(x) ((int)x.size())
#define MPI 3.14159265358979323846
#define all(x) x.begin(), x.end()

void __print(int x) { cerr << x; }
void __print(ll x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T> void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}

void _print() { cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

#ifndef Debug
#define dbg(x...)                                                              \
  cerr << "[" << #x << "] = [";                                                \
  _print(x)
#else
#define dbg(x...)
#endif
const int maxi = 2e6 + 10;
vector<vector<int>> graph(maxi);
vector<int> visited(maxi);

void dfs(int u) {
  visited[u] = 1;
  for (auto i : graph[u]) {
    if (!visited[i]) {
      dfs(i);
    }
  }
}

void solve() {
  int n;
  cin >> n;
  map<char, vector<int>> a;
  for (int k = 1; k <= n; k++) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      a[s[i]].push_back(k);
    }
  }
  for (auto i : a) {
    for (int j = 1; j < i.second.size(); j++) {
      graph[i.second[j - 1]].push_back(i.second[j]);
      graph[i.second[j]].push_back(i.second[j - 1]);
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      ans++;
      dfs(i);
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T = 1;
  // cin>>T;

  while (T--) {
    solve();
  }
  return 0;
}
