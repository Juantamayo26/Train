#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

struct kosaraju{
  int N, cont;
  stack<int>order;
  vector<vector<int>>G,GT;
  vector<int>comp;
  vector<bool> used;
  kosaraju(int n): N(n), G(N), GT(N), comp(N){cont=0;}

  void add_edge(int a, int b){
    G[a].push_back(b);
    GT[b].push_back(a);
  }

  void dfs1(int v){
    used[v] = 1;
    for(int u: G[v]){
      if(!used[u]){
        dfs1(u);
      }
    }
    order.push(v);
  }
  
  void dfs2(int v){
    used[v] = 1;
    comp[v] = cont;
    for(int u: GT[v]){
      if(!used[u]){
        dfs2(u);
      }
    } 
  }

  void start(){
    used.assign(N, 0);
    for(int i=0; i<N; i++){
      if(!used[i]){
        dfs1(i);
      }
    }
    used.assign(N, 0);
    while(!order.empty()){
      int u = order.top();
      order.pop();
      if(!used[u]){
        dfs2(u);
        cont++;
      }
    }
  }
};

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n, m;
  cin>>n>>m;
  kosaraju conex(n);
  int a, b;
  for(int i=0; i<m; i++){
    cin>>a>>b; //a--; b--;
    conex.add_edge(a,b);
  }
  conex.start();
  cout<<conex.cont<<endl;
 // if(conex.cont==1){
 //   cout<<"YES"<<endl;
 // }else{
 //   cout<<"NO"<<endl;
    //for(int i=0; i<n; i++){
    //  if(conex.comp[i]==0){
    //    a = i+1;
    //  }
    //  if(conex.comp[i]==1){
    //    b = i+1;
    //  }
    //}
   // cout<<b<<" "<<a<<endl;
  //}
  return 0;
}

