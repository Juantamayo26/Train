#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

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

const int maxi = 110;

struct data{
  string name;
  string has;
  string wants;
};

vector<data>a(maxi);
vector<int> vis(maxi);

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t; cin>>t;
  for(int i=0; i<t; i++){
    cin>>a[i].name>>a[i].has>>a[i].wants;
  }
  int ans = 0;
  int cur = 0;
  for(int i=0; i<t; i++){
    fill(vis.begin(), vis.end(), 0);
    int fi = i;
    int j =0;
    while(j < t){
      if(!vis[j] && a[j].wants == a[fi].has){
        fi = j;
        vis[j] = 1;
        cur++;
        j=0;
      }else{
        j++;
      }
    }
    if(vis[i]){
      ans = max(ans, cur);
    }
    cur = 0;
  }
  if(ans){
    cout<<ans<<endl;
  }else{
    cout<<"No trades possible"<<endl;
  }
  return 0;
}
