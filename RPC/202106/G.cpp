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

struct dsu{
  int parent, size;
};
const int maxi = 250000;

vector<dsu>a(maxi);

void build(){
  for(int i=0; i<8; i++){
    a[i].parent = i;
    a[i].size = 1;
  }
}

int get_parent(int u){
  if(u == a[u].parent){
    return u;
  }
  return a[u].parent = get_parent(a[u].parent);
}

void set_union(int u, int v){
  u = get_parent(u);
  v = get_parent(v);
  if(u!= v){
    if(a[u].size < a[v].size){
      swap(u, v);
    }
    a[v].parent = u;
    a[u].size += a[v].size;
  }
}

int get_size(int u){
  u = get_parent(u);
  return a[u].size;
}

int movx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int movy[] = {0, 0, -1, 1, 1, -1, -1, 1};
void evaluate(int i, int j, int turn ,int n, int m, vector<vector<int>> &mat){
  for(int k=0; k<8; k++){
    int newi = i+movx[k];
    int newj = j+movy[k];
    if(newi >= 0 && newi < n && newj >=0 && newj< m){
      if(mat[newi][newj] == turn+1){
        cout<<"HOLA"<<endl;
      }
    }
  }
}


int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m, k;
  cin>>n>>m>>k;
  vector<int>high(m+1);
  vector<vector<int>>mat(n,vector<int>(m));
  int turn = 0;
  for(int i=0; i<n*m; i++){
    int aux;
    cin>>aux, aux--;
    if(turn){
      mat[high[aux]][aux] = turn+1;
    }else{
      mat[high[aux]][aux] = turn+1;
    }
    high[aux]+=1;
    turn^=1;
  }
  dbg(mat);
  return 0;
}

