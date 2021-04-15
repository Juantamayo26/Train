#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vb = vector<bool>;

static mt19937_64 rng;

struct problem{
    ll n, k;
    vll p, d;
};

vll random_arrangement(ll n, ll k){
    vll p(k);
    ll j = 0;
    for (ll i = 0; i < n; i++){
        if (rng() % (n - i) < (k - j)){
            p[j] = i + 1;
            j++;
        }
    }
    return p;
}

void update_safe(ll i, ll n, ll k, const vll &d, vb &safe, ll &c){
    if (safe[i]) c--;
    if (i == 0) safe[i] = d[0] > 2;
    else if (i == k) safe[i] = d[k - 1] < n - 1;
    else safe[i] = d[i] - d[i - 1] > 3;
    if (safe[i]) c++;
}

vll move_piranhas(ll n, ll k, vll d, ll m){
    vb safe(k+1);
    ll c = 0;
    for (ll i = 0; i <= k; i++) update_safe(i, n, k, d, safe, c);
    for (ll i = 0; i < m; i++){
        if (c == 0) break;
        ll r = rng() % c + 1;
        ll j = -1;
        while (r > 0){
            j++;
            if (safe[j]) r--;
        }
        if (j == 0)
            d[0]--;
        else if (j < k){
            d[j - 1]++;
            d[j]--;
        }
        else
            d[k - 1]++;
        for (ll l = max((ll) 0, j - 1); l <= min(k, j + 1); l++)
            update_safe(l, n, k, d, safe, c);
    }
    return d;
}

void mutate_arrangement(ll n, ll k, vll &d, ll prob){
    if (rng() % prob == 0 && d[0] > 2) d[0]--;
    if (rng() % prob == 0 && d[1] - d[0] > 2) d[0]++;
    for (ll i = 1; i < k - 1; i++){
        if (rng() % prob == 0 && d[i] - d[i - 1] > 2) d[i]--;
        if (rng() % prob == 0 && d[i + 1] - d[i] > 2) d[i]++;
    }
    if (rng() % prob == 0 && d[k - 1] - d[k - 2] > 2) d[k - 1]--;
    if (rng() % prob == 0 && d[k - 1] < n - 1) d[k - 1]++;
}

problem random_problem(ll n, ll min_k, ll max_k, ll m, ll prob){
    ll k = rng() % (max_k - min_k + 1) + min_k;
    vll p = random_arrangement(n, k);
    vll d = move_piranhas(n, k, p, m);
    if (prob > 0) mutate_arrangement(n, k, d, prob);
    problem pr = problem{n, k, p, d};
    return pr;
}

void print_problem(problem pr){
    cout << pr.n << " " << pr.k << endl << pr.p[0];
    for (ll i = 1; i < pr.k; i++){
        cout << " "  << pr.p[i];
    }
    cout << endl << pr.d[0];
    for (ll i = 1; i < pr.k; i++){
        cout << " " << pr.d[i];
    }
    cout << endl;
}

int main(int argc, char** argv){
    ll n = stoll(argv[1]);
    ll min_k = stoll(argv[2]);
    ll max_k = stoll(argv[3]);
    ll m = stoll(argv[4]);
    ll prob = stoll(argv[5]);
    rng.seed(stoll(argv[6]));
    problem pr = random_problem(n, min_k, max_k, m, prob);
    print_problem(pr);
    return 0;
}
