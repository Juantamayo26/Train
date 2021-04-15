
#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <cassert>

using namespace std;

#define pii pair<int, int>

struct E{
  int node;
  int weight;

	bool operator<(const E& a) const { return weight > a.weight; }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

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

  // compute for all nodes the distance to node 0
  vector<int> dist(n, INT_MAX);
  vector<bool> visited(n, 0);
  priority_queue<E> q;
  q.push({0, 0});
  dist[0] = 0;
  while(!q.empty()){
    int u = q.top().node;
    int d = q.top().weight;
    q.pop();
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

  for(int person = 0; person < p; person++){
    assert(dist[v[person]] < INT_MAX); // if this triggers there is no path from this person to node 0 
  }

  // For every player mark every node which lies on a possible shortest path 
  vector<int> congestion = vector<int>(n, 0);
  int total_cost = 0;

  for(int person = 0; person < p; person++){
    total_cost += dist[v[person]];

    auto visited = vector<bool>(n, false);
    queue<int> q;
    q.push(v[person]);
    visited[v[person]] = true;
    congestion[v[person]]++;
    while(!q.empty()){
      int u = q.front(); q.pop();

      for(auto &edge : adj[u]){
        int v = edge.node;
        if(!visited[v] && dist[v] + edge.weight == dist[u]){ // implicitly also checks that dist[v] < dist[u]
          visited[v] = true;
          congestion[v]++;
          q.push(v);
        }
      }
    }

  }

  int best_cost = total_cost;
  // compute for every node what the cost is when you buy the group ticket there and remember the best one
  // note: you always want to let the group ticket end at the final destination
  for(int u = 0; u < n; u++){
    int current_cost = total_cost - congestion[u] * dist[u] + congestion[u] * g;

    best_cost = min(best_cost, current_cost);
  }

  cout << best_cost << endl;

}

