// time-limit: 2000
// problem-url: https://codeforces.com/group/gXivUSZQpn/contest/337396/problem/K
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define sz(x) ((int)x.size())
#define MPI  3.14159265358979323846
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
  int n, a, b;  cin>>n>>a>>b;
  vector<int>arr(n+1);
  a++; b++;
  for(int i=1; i<=n; i++){
    cin>>arr[i];
  }
  sort(arr.begin(), arr.end());
  for(int i=1; i<=n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  if(a==b){
    cout<<arr[b]-arr[a-1]<<endl;
  }else{
    cout<<arr[b]-arr[a]<<endl;
  }

}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int T=1; 
 // cin>>T;

  while(T--){
    solve();
  }
  return 0;
}
