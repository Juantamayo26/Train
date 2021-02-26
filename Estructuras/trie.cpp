#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int N = 1e7;
int nxt[N][26];
bool finish[N];
int cnt[N];
int nodes = 1;

void add(string s){
  int cur = 0;
  for(char c: s){
    int v = c-'a';
    if(nxt[cur][v] == 0){
      nxt[cur][v] = nodes;
      nodes++;
    }
    cur = nxt[cur][v];
    cnt[cur]++;
  }
  finish[cur] = true;
}

int find(string s){
  int cur = 0;
  for(char c : s){
    int v = c-'a';
    if(nxt[cur][v] == 0){
      return 0;
    }
    cur = nxt[cur][v];
  }
  return cnt[cur];
}
  
int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n; cin>>n;
  for(int i=0;i<n; i++){
    string s; cin>>s;
    add(s);
  }
  int q; cin>>q;
  while(q--){
    string s; cin>>s;
    cout<<find(s)<<endl;
  }
  return 0;
}
