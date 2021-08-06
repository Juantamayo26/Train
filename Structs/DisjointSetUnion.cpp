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
template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(f-1), cerr<<"->", __print(i); cerr << "}";}

void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef Debug
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

struct node{
  int parent;
  int size;
};

vector<node>s(9);

void make_set(int v){
  s[v].parent = v;
  s[v].size = 1;
}

int find_set(int v){
  if(s[v].parent == v){
    return v;
  }
  return s[v].parent = find_set(s[v].parent);
}

void union_sets(int a, int b){
  a = find_set(a);
  b = find_set(b);
  if(a != b){
    if(s[a].size < s[b].size){
      swap(a,b);
    }
    s[b].parent = a;
    s[a].size += s[b].size;
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  for(int i=1; i<=8; i++){
    make_set(i);
  }
  union_sets(5, 7);
  union_sets(6, 8);
  union_sets(3, 5);
  union_sets(3, 6);
  union_sets(2, 3);
  union_sets(2, 4);
  union_sets(1, 2);
  for(int i=1; i<=8; i++){
    dbg(s[i].parent);
  }
  for(int i=1; i<=8; i++){
    dbg(s[i].size);
  }
  return 0;
}

