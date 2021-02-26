#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[10];
	for(int i=0;i<10; i++){
		cin>>a[i];
	}
	map<int, int>m;
	for(int i=0;i<10; i++){
		m[a[i]%42]++;
	}
	cout<<m.size()<<endl;
	return 0;
}
