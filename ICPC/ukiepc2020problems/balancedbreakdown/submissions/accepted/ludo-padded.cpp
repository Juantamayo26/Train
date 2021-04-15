#include<cstdio>
using ll = long long;
ll p10[19], a[19], L=0;

ll solve(ll n) {
	L=0;
	for (ll x = n; x; x /= 10)
		a[L++] = x % 10;
	bool p = true;
	for (int i = L; i--; )
		p &= a[i] == a[L-1-i];

	if (p) return n;
	if (p10[L-1] == n) return n-1;

	ll hi = 0, lo = 0;
	for (int i = 0; i < (L+1)/2; i++)
		hi = hi*10 + a[L-1-i];
	for (int i = L/2; i--; )
		lo = lo*10 + a[L-1-i];

	if (hi*p10[L/2] + lo <= n)
		return hi*p10[L/2] + lo;
	lo = 0;
	for (ll x = --hi / ((L&1)?10:1); x; x /= 10)
		lo = 10LL*lo + (x%10);
	return hi*p10[L/2] + lo;
}

int main() {
	p10[0] = 1;
	for (int i = 1; i <= 18; i++)
		p10[i] = p10[i-1] * 10;

	ll n, m;
	scanf("%lld", &n);
	printf("10\n");
	for (int i=10; i--; ) {
		m = solve(n);
		n -= m;
		printf("%lld\n", m);
	}
	return 0;
}
