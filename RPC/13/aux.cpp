// C++ program to create a priority queue of pairs. 
// By default a max heap is created ordered 
// by first element of pair. 
#include <bits/stdc++.h> 

using namespace std; 

// Driver program to test methods of graph class 
int main() 
{ 
	// By default a max heap is created ordered 
	// by first element of pair. 
	priority_queue<pair<int, int> > pq; 

	pq.push(make_pair(10, 200)); 
	pq.push(make_pair(20, 100)); 
	pq.push(make_pair(15, 400)); 

	pair<int, int> top = pq.top(); 
	cout << top.first << " " << top.second; 
	return 0; 
} 

