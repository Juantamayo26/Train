#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)

int main()
{
	int i, j, n, m;
	assert(scanf("%d %d", &n, &m) == 2);
	int a[n], b[m];
	rep(i, n)
	{
		char c; assert(scanf(" %c", &c));
		if (c == '?')
		{
			a[i] = -1;
			continue;
		}
		scanf(" %d", &a[i]); a[i] *= 4;
		switch (c)
		{
			case 's': a[i] += 0; break;
			case 'n': a[i] += 1; break;
			case 'w': a[i] += 2; break;
			case 'e': a[i] += 3; break;
		}
	}
	rep(i, m)
	{
		char c; assert(scanf(" %c", &c));
		if (c == '?')
		{
			b[i] = -1;
			continue;
		}
		assert(scanf(" %d", &b[i]));
		b[i] *= 4;
		switch (c)
		{
			case 's': b[i] += 0; break;
			case 'n': b[i] += 1; break;
			case 'w': b[i] += 2; break;
			case 'e': b[i] += 3; break;
		}
	}
	//fprintf(stderr, ">> "); rep(i, n) fprintf(stderr, "%d ", a[i]); fprintf(stderr, "\n");
	//fprintf(stderr, ">> "); rep(i, m) fprintf(stderr, "%d ", b[i]); fprintf(stderr, "\n");
	int r = 0;
	rep(i, n - m + 1) 
	{
		rep(j, m) if (a[i + j] != -1 && b[j] != -1 && a[i + j] != b[j]) break;
		if (j == m) 
			r++;
		//printf("%d ", i + 1);
	}
	//printf("\n");
	printf("%d\n", r);
	return 0;
}
