#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    ll c, e, m;
    cin >> c >> e >> m;

    if (c != 4 || e % 2 != 0) {
        cout << "impossible" << endl;
        return 0;
    }

    __int128 n = c + e + m;
    // w * h == n
    // => w = n / h
    // 2w + 2h - 8 = e
    // => h = (e + 8 - 2w) / 2
    ll low = 2, high = e / 4 + 2;
    while (low <= high) {
        ll w = (low + high) / 2;
        ll h = (e + 8 - 2 * w) / 2;
        __int128 area = (__int128) w * (__int128) h;
        if (area > n) { // w > n / h
            high = w - 1;
        } else if (area < n) { // w < n / h
            low = w + 1;
        } else { // w == n / h
            cout << w << " " << h << endl;
            return 0;
        }
    }

    cout << "impossible" << endl;
    return 0;
}
