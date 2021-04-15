
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long c, e, m;
    cin >> c >> e >> m;
    long long D = e * e / 4 - 4 * m;
    long long s = floorl(sqrtl(abs(D)));
    if (c != 4 || e % 2 == 1 || s * s != D) cout << "impossible" << endl;
    else cout << (e / 2 + s) / 2 + 2 << ' ' << (e / 2 - s) / 2 + 2 << endl;
    return 0;
}
