// time-limit: 1000
// problem-url: https://codeforces.com/problemset/problem/71/A
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

void _print(int x) {cerr << x;}
void _print(ll x) {cerr << x;}
void _print(float x) {cerr << x;}
void _print(double x) {cerr << x;}
void _print(long double x) {cerr << x;}
void _print(char x) {cerr << '\'' << x << '\'';}
void _print(string x) {cerr << '\"' << x << '\"';}
void _print(bool x) {cerr << (x ? "true" : "false");}

template <class T> void _print(vector<T> x){cerr<<"[ "; for(T i: x){_print(i); cerr<<" ";} cerr<<"]";}
template <class T, class V> void _print(pair <T, V> x) {cerr << "{"; _print(x.first); cerr << ","; _print(x.second); cerr << "}";}
template <class T> void _print(set <T> x) {cerr << "[ "; for (T i : x) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> x) {cerr << "[ "; for (T i : x) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> x) {cerr << "[ "; for (auto i : x) {_print(i); cerr << " ";} cerr << "]";}

#ifndef Debug
#define debug(x...) cerr << "[" << #x << "] = "; _print(x); cerr << endl;
#else
#define debug(x...)
#endif

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n; cin>>n;
  for(int i=0; i<n; i++){
    string s; 
    cin>>s;
    if(s.size()> 10){
      cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
    }else{
      cout<<s<<endl;
    }
  }
	return 0;
}
