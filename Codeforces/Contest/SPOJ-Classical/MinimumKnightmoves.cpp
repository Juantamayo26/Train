// time-limit: 1000
// problem-url: https://www.spoj.com/problems/NAKANJ/
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

int dx[]={2,2,-2,-2,1,1,-1,-1};
int dy[]={-1,1,1,-1,2,-2,2,-2};
map<char, int>mov;
vector<vector<int>>vis(8, vector<int>(8));
//vector<vector<int>>ans(8, vector<int>(8));
void pre(){
  char x = 'a';
  for(int i=0; i<8; i++){
    mov[x]=i;
    x++;
  }
}

void solve(){
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      vis[i][j] = 0;
   //   ans[i][j] = 0;
    }
  }
  string a, b;
  cin>>a>>b;
  pair<int, int> in, out;
  in = {mov[a[0]], a[1]-'0'-1};
  out = {mov[b[0]], b[1]-'0'-1};
  queue<pair<int, int>>q;
  q.push(in);
  vis[in.first][in.second] = 1;
  while(q.size()){
    in = q.front();
    q.pop();
    if(in == out){
      break;
    }
    for(int i=0; i<8; i++){
      int mx = dx[i] + in.first;
      int my = dy[i] + in.second;
      if(mx < 0 ||mx >=8 ||my < 0 ||my >=8 || vis[mx][my]){
        continue;
      }
      vis[mx][my] = vis[in.first][in.second]+1;
      //ans[mx][my] = ans[in.first][in.second]+1;
      q.push({mx, my});
    }
  }
  cout<<vis[in.first][in.second]-1<<endl;
 // cout<<ans[in.first][in.second]<<endl;
}

int main(){
  //ios::sync_with_stdio(0); cin.tie(0); 
  int T=1; 
  cin>> T;
  pre();
  while(T--){
    solve();
  }
  return 0;
}
