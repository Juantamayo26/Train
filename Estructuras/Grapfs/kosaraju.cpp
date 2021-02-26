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
