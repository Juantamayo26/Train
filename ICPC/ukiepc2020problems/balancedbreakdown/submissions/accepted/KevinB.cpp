#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll X;

void breakdown(ll a, vector<ll>& v) {
	if (a == 0L) return;
	if (a < 10L) {
		v.push_back(a);
		return;
	}
	if (a == 10L) {
		v.push_back(9L); v.push_back(1L);
		return;
	}
	if (a <= 20L) {
		v.push_back(11L);
		breakdown(a - 11L, v);
		return;
	}
	string s1 = to_string(a);
	string s2 = s1.substr(0, (s1.length() + 1) / 2);
	ll b = stoll(s2)-1L;
	string s3 = to_string(b);
	string s4 = s3.substr(0, s3.length() - s1.length() % 2);
	reverse(s4.begin(), s4.end());
	s3 += s4;
	ll c = stoll(s3);
	v.push_back(c);
	breakdown(a - c, v);
}

int main() {
	cin >> X;
	vector<ll> v;
	breakdown(X, v);

	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << endl;

	return 0;
}