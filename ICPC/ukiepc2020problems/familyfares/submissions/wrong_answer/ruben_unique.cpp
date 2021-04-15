
#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>
#include <climits>
#include <ctime>
#include <cmath>
#include <cassert>

using namespace std;

#define pii pair<int, int>

double time_difference(timespec begin, timespec end)
{
	return (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / pow(10,9);
}

struct E{
  int node;
  int weight;

	bool operator<(const E& a) const { return weight > a.weight; }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  timespec t1, t2, t3, t4, t5, t6;

  int n, m, p, g;
  cin >> n >> m >> p >> g;

  vector<int> v(p);
  for(int i=0;i <p; i++){
    cin >> v[i];
    v[i]--;
  }

  vector<vector<E>> adj(n, vector<E>());
  int a, b, c;
  for(int i=0; i<m; i++){
    cin >> a >> b >> c;
    a--; b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  // compute for all nodes the distance to node 0, and also remember the next node on the shortest path
  vector<int> dist(n, INT_MAX);
  vector<int> next_node(n, -1);
  vector<bool> visited(n, 0);
  priority_queue<E> q;
  q.push({0, 0});
  dist[0] = 0;
  next_node[0] = 0;
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
          next_node[edge.node] = u;
        }
      }
    }
  }

  for(int person = 0; person < p; person++){
    assert(dist[v[person]] < INT_MAX); // if this triggers there is no path from this person to node 0 
  }

  // compute how many players will pass a certain node and the total cost when not using the groupticket
  vector<int> congestion = vector<int>(n, 0);
  int total_cost = 0;

  for(int person = 0; person < p; person++){
    int cur_node = v[person];
    total_cost += dist[cur_node];

    while(next_node[cur_node] != cur_node){
      congestion[cur_node]++;
      cur_node = next_node[cur_node];
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
