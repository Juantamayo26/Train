// time-limit: 2000
// problem-url: https://codeforces.com/group/gXivUSZQpn/contest/337396/problem/G
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

map<int, vector<int>>s;
vector<string>p = {"Grapes", "Carrots", "Kiwis"};
void solve(){
  int n, m, k, t; cin>>n>>m>>k>>t;
  //Carrots or Kiwis or Grapes or Waste
  for(int i=0; i<k; i++){
    int a, b; cin>>a>>b;
    s[a].push_back(b);
  }
  for(int i=0; i<t; i++){ // 10^3
    int a ,b; cin>>a>>b;
    int cua = 0;
    for(int j=1; j<a; j++){ // 10^4
      vector<int> x = s[j];
      cua+= x.size();
    }
    vector<int> x = s[a];
    bool wa = false;
    for(int k=0; k<x.size(); k++){
      if(x[k] < b){
        cua++;
      }
      if(x[k] == b){
        wa = true;
        break;
      }
    }
    if(wa) {
      cout<<"Waste"<<endl;
    }else{
      a--;
      cout<<p[((a*m+b)-cua)%3]<<endl;
    }
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
