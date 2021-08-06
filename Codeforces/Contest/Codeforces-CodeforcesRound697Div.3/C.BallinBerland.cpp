// time-limit: 2000
// problem-url: https://codeforces.com/contest/1475/problem/C
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define M_PI  3.14159265358979323846
#define pb push_back

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
  int a, b, k; 
  cin>>a>>b>>k;
  vector<int>boys(a+1, 0);
  vector<int>girls(b+1, 0);
  vector<int>a1,b1;
  int aux;
  for(int i=0; i<k; i++){
    cin>>aux;
    boys[aux]++;
    a1.pb(aux);
  }
  for(int i=0; i<k; i++){
    cin>>aux;
    girls[aux]++;
    b1.pb(aux);
  }
  ll ans = 0;
  int x, y;
  for(int i=0; i<k; i++){
    x = a1[i];
    y = b1[i];
    ans+= ((k-1)-boys[x]-girls[y]+2);
  }
  cout<<ans/2<<endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t; cin>>t;
  vector<pair<int, int>>s;
  while(t--){
    solve();
  }
  return 0;
}
