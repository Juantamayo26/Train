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
    vector<long long> cxl(cycle_xors.begin(), cycle_xors.end());
    vector<long long> flippers = {0};
    for(auto f : cxl)
        flippers[0] = max(flippers[0], f);
    while(flippers[flippers.size() - 1] > 1) {
        long long last = flippers[flippers.size() - 1];
        long long ne = 0;
        for(int i = 0; i < cxl.size(); i++) {
            cxl[i] = min(cxl[i], cxl[i] ^ last);
            ne = max(cxl[i], ne);
        }
        flippers.push_back(ne);
    }

    for(int i = 0; i < Q; i++) {
        int x, y; cin >> x >> y;
        x--; y--;
        values = vector<long long>(N, 0);
        done = vector<bool>(N, false);
        done[x] = true;
        s.push(x);

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
                if(nb == y) {
                    while(s.size())
                        s.pop();
                    break;
                }
            }
        }

        long long dist = values[y];
        for(auto flipper : flippers)
            dist = min(dist, dist ^ flipper);
        cout << dist << endl;
    }
    return 0;
}
