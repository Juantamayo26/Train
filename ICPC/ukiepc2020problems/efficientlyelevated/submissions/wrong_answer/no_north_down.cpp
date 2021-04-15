#include <iostream>
#include <algorithm>

int h, w, n;
long grid[500*500];
int sort[500*500];
int answer = 0;

void print() {
	for( int y = 0; y < h; ++y ) {
		for( int x = 0; x < w; ++x ) {
			std::cout << grid[w*y+x] << " ";
		}
		std::cout << std::endl;
	}
}

void floodfill( int i ) {
	int a = grid[i];
	grid[i] = 0;
	if( i >= w and 0 < grid[i-w] and grid[i-w] == a ) // This == should be <=
		floodfill( i-w );
	if( i < n - w and 0 < grid[i+w] and grid[i+w] <= a )
		floodfill( i+w );
	if( i % w != 0 and 0 < grid[i-1] and grid[i-1] <= a )
		floodfill( i-1 );
	if( i % w != w-1 and 0 < grid[i+1] and grid[i+1] <= a )
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
