#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define ll long long
const int maxi = 500100;
vector<int>a(maxi);

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	for(int j=1; j<=t; j++){
		int n; cin>>n;
		for(int i =0; i<n ;i++){
			cin>>a[i];
		}
		stack<int>s;
		vector<int>ans(n+1);
		for(int i =0; i<n ;i++){
			while(s.size() && (a[i] > a[s.top()])){
				ans[s.top()] = a[i];
				s.pop();
			}
			s.push(i);
		}
		while(s.size()){
			s.pop();
		}
		for(int i =0; i<n ;i++){
			if(ans[i] == 0){
				ans[i] = -1;
			}
		}
		cout<<"Case #"<<j<<": ";
		for(int i =0; i<n ;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;

	}
	return 0;
}
