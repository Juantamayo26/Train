
#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <cassert>
#include <algorithm>

using namespace std;

#define pii pair<int, int>

struct E{
  int node;
  int weight;

	bool operator<(const E& a) const { return weight > a.weight; }
};

int main(){

  int n, m, p, g;
  cin >> n >> m >> p >> g;

  vector<int> ps(p);
  for(int i=0;i <p; i++){
    cin >> ps[i];
    ps[i]--;
  }

  vector<vector<E>> adj(n, vector<E>());
  for(int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  // compute for all nodes the distance to node 0, and also remember the next node on the shortest path
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
      for(const auto &edge: adj[u]){
        if(d + edge.weight < dist[edge.node]){
          dist[edge.node] = d + edge.weight;
          q.push({edge.node, d + edge.weight});
        }
      }
    }
  }

  auto dist_index = vector<pair<int, int>>(n);
  for(int i=0; i<n; i++){
    dist_index[i] = {dist[i], i};
  }
  sort(dist_index.begin(), dist_index.end(), [](const pair<int, int>& a, const pair<int, int> &b){
      return a.first > b.first;
      });

  int total_cost = 0;
  vector<int> congestion = vector<int>(n, 0);
  for(const auto &loc : ps){
    congestion[loc]++;
    total_cost += dist[loc];
  }

  int best_cost = total_cost;
  for(const auto &node : dist_index){
    int u = node.second;
    for(const auto &edge : adj[u]){
      int v = edge.node;
      if(dist[v] + edge.weight == dist[u]){
        congestion[v] += congestion[u];
      }
    }
    best_cost = min(best_cost, total_cost - congestion[u] * dist[u] + congestion[u] * g);

  }

  cout << best_cost << endl;

}
