
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long c, e, m;
    cin >> c >> e >> m;
    if (c % 4 != 0 || e % 2 == 1){
        cout << "impossible" << endl;
        return 0;
    }
    long long x = floor(sqrt(m));
    long long y = m / x;
    long long z = m - x * y;
    cout << y + 2 << ' ' << x + 2 << endl;
    if (z == 0){
        cout << e / 2 - x - y + 2 << ' ' << 2 << endl;
        c -= 8;
    }
    else{
        cout << z + 2 << ' ' << 3 << endl;
        cout << e / 2 - x - y - z + 1 << ' ' << 2 << endl;
        c -= 12;
    }
    for (long long i = 1; 4 * i <= c; ++i) cout << 2 << ' ' << 2 << endl;
    return 0;
}
