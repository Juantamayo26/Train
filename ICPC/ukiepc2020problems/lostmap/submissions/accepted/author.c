#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <complex.h>
#define rep(E, F) for (E = 0; E < (F); E++)

int mabs(int a) { if (a > 0) { return a; } return -a; }
int min(int a, int b) { if (a > b) { return b; } return a; }
int max(int a, int b) { if (a < b) { return b; } return a; }

typedef struct { int x, y; } par;
typedef complex double cpx;

void fft(cpx* x, int n, int b)
{
	int i, j, m, mx;
	for (i = 0, j = 0; i < n; i++)
	{
		if (i < j)
		{
			cpx t = x[i];
			x[i] = x[j];
			x[j] = t;
		}
		int m = n >> 1;
		while (1 <= m && m <= j) j -= m, m >>= 1;
		j += m;
	}
	for (mx = 1; mx < n; mx <<= 1)
	{
		double g = (b ? -1 : 1)*M_PI/mx;
		cpx wp = cos(g) + sin(g)*I, w = 1.0;
		for (m = 0; m < mx; m++, w = w*wp)
		{
			for (i = m; i < n; i += mx << 1)
			{
				cpx t = x[i + mx]*w;
				x[i + mx] = x[i] - t;
				x[i] = x[i] + t;
			}
		}
	}
	if (b) for (i = 0; i < n; i++) x[i] /= n;
}
int iround(double a)
{
    if (a < 0) return -round(-a);
    return (int)(a + 0.5);
}

void multiply(int* a, int* b, int* r, int n, int m)
{
    int k = 1, i;
    while (k < max(n, m)) k <<= 1;
    k <<= 1;
	cpx c[k], d[k];
    rep(i, n) c[i] = a[i];
    while (i < k) c[i++] = 0.0;
    rep(i, m) d[i] = b[i];
    while (i < k) d[i++] = 0.0;
    fft(c, k, 0), fft(d, k, 0);
    for (i = 0; i < k; i++) c[i] = c[i]*d[i];
    fft(c, k, 1);
    for (i = 0; i < min(n + m, k); i++) r[i] = iround(creal(c[i]));
}

int cmp1(const void* p1, const void* p2) { return ((par*)p1)->x - ((par*)p2)->x; }
int cmp2(const void* p1, const void* p2) { return ((par*)p1)->y - ((par*)p2)->y; }

void rev(int* a, int n)
{
	int i;
	rep(i, n/2)
	{
		int t = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = t;
	}
}

int main()
{
	int e, i, j, k, t, n, m;
  scanf("%d %d", &n, &m);
	par p[n + m];
	int v[n - m + 1];
	//rep(i, n) p[i].x = get_int(), p[i].y = i;
	//rep(i, m) p[n + i].x = get_int(), p[n + i].y = n + i;
	rep(i, n)
	{
		p[i].y = i;
    char c; scanf(" %c", &c);
		switch (c)
		{
			case '?': p[i].x = -1; continue;
			case 's': p[i].x = 0; break;
			case 'n': p[i].x = 1; break;
			case 'w': p[i].x = 2; break;
			case 'e': p[i].x = 3; break;
      default: assert(0);
		}
    int x; scanf(" %d", &x);
		p[i].x += 4*x;
	}
	int z = 0;
	rep(i, m)
	{
		p[n + i].y = n + i;
    char c; scanf(" %c", &c);
    switch (c)
		{
			case '?': p[n + i].x = -1; ++z; continue;
			case 's': p[n + i].x = 0; break;
			case 'n': p[n + i].x = 1; break;
			case 'w': p[n + i].x = 2; break;
			case 'e': p[n + i].x = 3; break;
      default: assert(0);
		}
    int x; scanf(" %d", &x);
		p[n+i].x += 4*x;
	}
	//fprintf(stderr, " pre >> "); rep(i, n) fprintf(stderr, "%d ", p[i]); fprintf(stderr, "\n");
	//fprintf(stderr, " pre >> "); rep(i, m) fprintf(stderr, "%d ", p[n + i]); fprintf(stderr, "\n");

	rep(i, n - m + 1) v[i] = 0;
	rep(i, m) if (p[i].x == -1) v[0]++;
	rep(i, n - m + 1) if (i != 0)
	{
		v[i] = v[i - 1];
		if (p[i - 1].x == -1) v[i]--;
		if (p[i + m - 1].x == -1) v[i]++;
	}
	//rep(i, n - m + 1) printf("%d ", v[i]); printf("\n");
	/*
	   qsort(p, n + m, sizeof(p[0]), cmp1);
	   i = k = 0;
	   while (p[i].x == -1) i++;
	   while (i < n + m)
	   {
	   j = i;
	   t = p[i].x;
	   while (j < n + m && t == p[j].x) p[j++].x = k;
	   k++;
	   i = j;
	   }
	   qsort(p, n + m, sizeof(p[0]), cmp2);
	//fprintf(stderr, "post >> "); rep(i, n) fprintf(stderr, "%d ", p[i].x); fprintf(stderr, "\n");
	//fprintf(stderr, "post >> "); rep(i, m) fprintf(stderr, "%d ", p[n + i].x); fprintf(stderr, "\n");
	*/
	int mx = 0;
	rep(i, m + n) mx = max(mx, p[i].x);
	k = 0;
	while (mx > 0) k++, mx /= 2;
	//printf(">> %d\n", k);
	int y = 3*k*(n + m);
	int a[3][k*n];
	int b[3][k*n];
	int c[3][y];
	rep(i, y) c[0][i] = c[1][i] = 0;
	rep(i, k*n) a[0][i] = b[0][i] = a[1][i] = b[1][i] = a[2][i] = b[2][i] = 0;

	rep(i, n)
	{
		if (p[i].x == -1)
		{
			rep(j, k) a[0][k*i + j] = 2;
			continue;
		}
		e = (1 << (k - 1));
		rep(j, k)
		{
			a[0][k*i + j] = ((e&(p[i].x)) ? 1 : 0);
			e = e/2;
		}
	}
	rep(i, m)
	{
		if (p[n + i].x == -1)
		{
			rep(j, k) b[0][k*i + j] = 2;
			continue;
		}
		e = (1 << (k - 1));
		rep(j, k)
		{
			b[0][k*i + j] = ((e&(p[n + i].x)) ? 1 : 0);
			e = e/2;
		}
	}

	rep(i, k*n) a[1][i] = (a[0][i] == 2 ? 2 : 1 - a[0][i]);
	rep(i, k*m) b[1][i] = (b[0][i] == 2 ? 2 : 1 - b[0][i]);

	rep(t, 2)
	{
		rep(j, k*n) if (a[t][j] == 2) a[t][j] = 0, a[2][j] = 1;
		rep(j, k*m) if (b[t][j] == 2) b[t][j] = 0, b[2][j] = 1;
	}

	rev(b[0], k*m);
	rev(b[1], k*m);
	rev(b[2], k*m);

	multiply(a[0], b[0], c[0], k*n, k*m);
	multiply(a[1], b[1], c[1], k*n, k*m);
	multiply(a[2], b[2], c[2], k*n, k*m);

	//printf(">> %d\n", k);
	//printf("a1: "); rep(i, n*k) { printf("%d", a[0][i]); if (i%k == k - 1 && i != 0) printf(" "); } printf("\n");
	//printf("a2: "); rep(i, n*k) { printf("%d", a[1][i]); if (i%k == k - 1 && i != 0) printf(" "); } printf("\n");
	//printf("a3: "); rep(i, n*k) { printf("%d", a[2][i]); if (i%k == k - 1 && i != 0) printf(" "); } printf("\n");
	//printf("b1: "); rep(i, m*k) { printf("%d", b[0][i]); if (i%k == k - 1 && i != 0) printf(" "); } printf("\n");
	//printf("b2: "); rep(i, m*k) { printf("%d", b[1][i]); if (i%k == k - 1 && i != 0) printf(" "); } printf("\n");
	//printf("b3: "); rep(i, m*k) { printf("%d", b[2][i]); if (i%k == k - 1 && i != 0) printf(" "); } printf("\n");

	int r = 0;
	rep(i, n - m + 1)
	{
		//printf(">> %d: %d %d %d %d\n", i, c[0][k*(m + i) - 1], c[1][k*(m + i) - 1], c[2][k*(m + i) - 1], k*(m - v[i] - z));
		if (
				c[0][k*(m + i) - 1] +
				c[1][k*(m + i) - 1] ==
				k*(m - v[i] - z) +
				c[2][k*(m + i) - 1]
			) 
			//printf(">> %d\n", i + 1),
				r++;
	}
	//printf("\n");
	printf("%d\n", r);

	//printf("  a1 "); rep(i, k*n) printf("%d ", a[0][i]); printf("\n");
	//printf("  a2 "); rep(i, k*n) printf("%d ", a[1][i]); printf("\n");
	//printf("  a3 "); rep(i, k*n) printf("%d ", a[2][i]); printf("\n");
	//printf("  b1 "); rep(i, k*m) printf("%d ", b[0][i]); printf("\n");
	//printf("  b2 "); rep(i, k*m) printf("%d ", b[1][i]); printf("\n");
	//printf("  b3 "); rep(i, k*m) printf("%d ", b[2][i]); printf("\n");
	//rep(i, n - m + 1) printf("%d %d %d %d %d\n", c[0][k*(m + i) - 1], c[1][k*(m + i) - 1], k*m, k*(v[i] + z), c[2][k*(m + i) - 1]);
	return 0;
}
