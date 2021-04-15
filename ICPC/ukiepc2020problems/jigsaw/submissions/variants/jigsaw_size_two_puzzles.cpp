
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> primes, spf;
void sieve(long long n){
    spf.assign(n + 1, -1);
    for (long long i = 2; i <= n; ++i){
        if (spf[i] == -1){
            primes.push_back(i);
            spf[i] = i;
        }
        for (long long p : primes){
            if (i * p > n) break;
            spf[i * p] = p;
            if (p == spf[i]) break;
        }
    }
}

vector<long long> divisors(long long n){
    vector<long long> ds = {1};
    for (long long m = n; m > 1; ){
        long long k = 0, p = spf[m], s = ds.size();
        while (m % p == 0) {++k; m /= p;}
        for (long long i = 0; i < k * s; ++i) ds.push_back(ds[i] * p);
    }
    sort(ds.begin(), ds.end());
    while (ds.back() * ds.back() > n) ds.pop_back();
    return ds;
}

int main(){
    long long c, e, m;
    cin >> c >> e >> m;
    if (c != 8 || e % 2 == 1){
        cout << "impossible" << endl;
        return 0;
    }
    if (m == 0){
        cout << e / 2 + 2 << ' ' << 2 << endl << 2 << ' ' << 2 << endl;
        return 0;
    }
    sieve(m);
    for (long long x : divisors(m)) if (e / 2 >= x + m / x){
        cout << m / x + 2 << ' ' << x + 2 << endl << e / 2 - x - m / x + 2 << ' ' << 2 << endl;
        return 0;
    }
    for (long long n = 1; 2 * n <= m; ++n){
        vector<long long> ds1 = divisors(n), ds2 = divisors(m - n);
        for (long long i = 0, j = ds2.size() - 1; i < ds1.size() && j >= 0; ){
            long long x1 = ds1[i], y1 = n / ds1[i], x2 = ds2[j], y2 = (m - n) / ds2[j];
            if (e / 2 < x1 + y1 + x2 + y2) ++i;
            else if (e / 2 > x1 + y1 + x2 + y2) --j;
            else{
                cout << y1 + 2 << ' ' << x1 + 2 << endl << y2 + 2 << ' ' << x2 + 2 << endl;
                return 0;
            }
        }
    }
    cout << "impossible" << endl;
    return 0;
}
