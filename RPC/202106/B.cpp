#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

bool compare(const int a, const int b){
    return a > b;
}

int main(){
    int n;
    cin >> n;
    double t[n], p = 0.5, ans = 0;
    for(int i = 0; i < n; i++) cin >> t[i];
    sort(t, t+n, compare);
    for(int i = 0; i < n; i++){
        ans += t[i]*p;
        p *= 0.5;
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}