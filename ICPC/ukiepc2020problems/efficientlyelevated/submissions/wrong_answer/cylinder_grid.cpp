#include <iostream>
#include <algorithm>

int h, w, n;
long grid[500*500];
int sort[500*500];
int answer = 0;

void floodfill( int i ) {
	int a = grid[i];
	grid[i] = 0;
	if( i >= w and 0 < grid[i-w] and grid[i-w] <= a )
		floodfill( i-w );
	if( i < n - w and 0 < grid[i+w] and grid[i+w] <= a )
		floodfill( i+w );
	if( i > 0 and 0 < grid[i-1] and grid[i-1] <= a ) // i > 0 should be i%w > 0
		floodfill( i-1 );
	if( i < n-1 and 0 < grid[i+1] and grid[i+1] <= a ) // i < n-1 should be i%w < n-1
		floodfill( i+1 );
}

int main() {
	// input
	std::cin >> h >> w;
	n = w*h;
	for( int i = 0; i < n; ++i ) {
		std::cin >> grid[i];
		if( grid[i] == 0 )
			grid[i] = 1;
		sort[i] = i;
	}

	// unnecessary sort
	std::sort( sort, sort+n, 
		[]( int i, int j ) { 
			return grid[i] > grid[j];
	});

	// edge case
	if( grid[sort[0]] == 1 ) {
		std::cout << 0 << std::endl;
		return 0;
	}

	// iterate
	for( int i = 0; i < n; ++i ) {
		if( 0 < grid[sort[i]] ) {
			++answer;
			floodfill( sort[i] );
	}}

	// output
	std::cout << answer << std::endl;
}
