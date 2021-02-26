#include <iostream>

using namespace std;
const int N = 50000+10;
int a[N], ps[N+1];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n; i++){
		cin>>a[i];
	}
	for(int i=1;i<=n; i++){
		ps[i] = a[i-1]+ps[i-1];
	}
	int t; cin>>t;
	while(t--){
		int a, b; cin>>a>>b;
		b++;
		cout<<ps[b]-ps[a]<<endl;
	}
	return 0;
}
