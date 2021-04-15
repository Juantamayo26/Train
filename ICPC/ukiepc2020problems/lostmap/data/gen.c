#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)

int main(int argc, char** argv)
{
	assert(argc > 4);
	srand(atoi(argv[4]));
	int i, j, n, m, k;
	n = atoi(argv[1]);
	m = atoi(argv[2]);
	k = atoi(argv[3]);
	assert(m <= n);
	printf("%d %d\n", n, m);
	rep(j, n + m)
	{
		if (rand()%10)
		{
			printf("Take %d steps ", rand()%k + 1);
			switch (rand()%4)
			{
				case 0: printf("north\n"); break;
				case 1: printf("south\n"); break;
				case 2: printf("east\n"); break;
				case 3: printf("west\n"); break;
			}
		}
		else printf("?\n");
	}
}
