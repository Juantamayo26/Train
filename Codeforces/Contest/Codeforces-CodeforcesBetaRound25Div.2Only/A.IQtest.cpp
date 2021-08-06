// time-limit: 2000
// problem-url: https://codeforces.com/contest/25/problem/A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vl;
#define sz(x) ((int)x.size())
#define MPI  3.14159265358979323846
#define pb push_back
#define all(x) x.begin(), x.end()

void __print(int x) {cerr << x;}
void __print(ll x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}

void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef Debug
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

void solve(){
  int n; cin>>n;
  vi pr(3);
  vi ps(3);
  int aux;
  for(int i=0; i<n ;i++){
    cin>>aux;
    pr[aux&1]++;
    ps[aux&1] = i+1;
  }
  dbg(pr, ps);
  cout<< (pr[0] > pr[1]? ps[1]: ps[0])<<endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int T=1; 
  //cin>> T;
  while(T--){
    solve();
  }
  return 0;
}
