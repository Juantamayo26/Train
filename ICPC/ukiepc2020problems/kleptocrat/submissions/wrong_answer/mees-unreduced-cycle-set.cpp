#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<pair<int, long long>>> adj(N);
    for(int i = 0; i < M; i++) {
        int a, b; long long w;
        cin >> a >> b >> w;
        a--; b--;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    set<long long> cycle_xors;
    cycle_xors.insert(0);
    stack<int> s; s.push(0);
    vector<bool> done(N, false);
    done[0] = true;
    vector<long long> values(N, 0);

    while(s.size() > 0) {
        int cur = s.top(); s.pop();
        for(auto p : adj[cur]) {
            int nb = p.first;
            long long w = p.second;
            if(done[nb]) {
                cycle_xors.insert(w ^ values[cur] ^ values[nb]);
            }
            else {
                values[nb] = w ^ values[cur];
                done[nb] = true;
                s.push(nb);
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        long long dist = values[x] ^ values[y];
        for(auto flipper : cycle_xors) {
            dist = min(dist, dist ^ flipper);
        }
        cout << dist << endl;
    }
    return 0;
}
