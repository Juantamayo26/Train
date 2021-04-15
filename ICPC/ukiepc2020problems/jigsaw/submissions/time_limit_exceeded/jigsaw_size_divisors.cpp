
#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long c, e, m;
    cin >> c >> e >> m;
    if (c != 4 || e % 2 == 1){
        cout << "impossible" << endl;
        return 0;
    }
    if (m == 0){
        cout << e / 2 + 2 << ' ' << 2 << endl;
        return 0;
    }
    vector<long long> ds = {1};
    long long x = m;
    for (long long p = 2; p * p <= x; ++p) if (x % p == 0){
        long long k = ds.size();
        for (long long q = p; x % p == 0; q *= p, x /= p) for (long long i = 0; i < k; ++i) ds.push_back(ds[i] * q);
    }
    if (x > 1) for (long long i = 0; 2 * i < ds.size(); ++i) ds.push_back(ds[i] * x);
    for (long long x : ds) if (x * x <= m && e / 2 == x + m / x){
        cout << m / x + 2 << ' ' << x + 2 << endl;
        return 0;
    }
    cout << "impossible" << endl;
    return 0;
}
