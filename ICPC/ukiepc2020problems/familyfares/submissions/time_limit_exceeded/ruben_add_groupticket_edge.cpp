/*
 * Loops over all nodes and adds an edge from that node to destination node with cost of group ticket
 */
#include <vector>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

#define pii pair<int, int>
#define ll long long 

struct E{
  int node;
  int weight;

	bool operator<(const E& a) const { return weight > a.weight; }
};


vector<ll> single_source_dijkstra(vector<vector<E>> & adj){
  int n = adj.size();
  vector<ll> dist(n, LLONG_MAX);
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
  return dist;
}


ll dijkstra(vector<vector<E>> & adj, vector<ll> &D, int s){
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
        if(edge.node != 0 && D[u] != D[edge.node]+ edge.weight) continue; // only use shortest paths
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

  ll best_cost = 0;
  auto dist = single_source_dijkstra(adj);
  for(auto person: v){
    best_cost += dist[person];
  }

  for(int i=1; i<n; i++){ // what if you can get a group ticket at node i 
    ll cur_cost = 0;

    adj[i].push_back({0, g});

    for(int person = 0; person < p; person++){
      cur_cost += dijkstra(adj, dist, v[person]);
    }

    //cerr << i << " : " << cur_cost << endl;
    best_cost = min(best_cost, cur_cost); 
    adj[i].pop_back();
  }

  cout << best_cost << endl;

  return 0;

}

