// @EXPECTED_RESULTS@: WRONG_ANSWER, TIME_LIMIT_EXCEEDED
/*
 * Loops over all nodes and adds an edge from that node to destination node with cost of group ticket
 */
#include <vector>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

#define pii pair<int, int>

struct E{
  int node;
  int weight;

	bool operator<(const E& a) const { return weight > a.weight; }
};


int dijkstra(vector<vector<E>> & adj, int s){
  int n = adj.size();
  vector<int> dist(n, INT_MAX);
  vector<bool> visited(n, 0);
  priority_queue<E> q;
  q.push({s, 0});
  dist[s] = 0;
  while(!q.empty()){
    int u = q.top().node;
    int d = q.top().weight;
    q.pop();
    if(u == 0){
      return d;
    }
    if(!visited[u]){
      visited[u] = true;
      for(auto edge: adj[u]){
        if(d + edge.weight < dist[edge.node]){
          dist[edge.node] = d + edge.weight;
          q.push({edge.node, d + edge.weight});
        }
      }
    }
  }
  return INT_MAX;
}



int main(){

  int n, m, p, g;
  cin >> n >> m >> p >> g;

  vector<int> v(p);
  for(int i=0;i <p; i++){
    cin >> v[i];
    v[i]--;
  }

  vector<vector<E>> adj(n, vector<E>());
  for(int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  int best_cost = INT_MAX;
  for(int i=0; i<n; i++){ // what if you can get a group ticket at node i 
    int cur_cost = 0;

    if(i != 0) adj[i].push_back({0, g});

    for(int person = 0; person < p; person++){
      cur_cost += dijkstra(adj, v[person]);
    }

    best_cost = min(best_cost, cur_cost); 
    if(i != 0) adj[i].pop_back();
  }

  cout << best_cost << endl;

  return 0;

}
