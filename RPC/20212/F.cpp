#include <bits/stdc++.h>

using namespace std;
const int maxi = 10000+10;

int a[maxi];

int main(){
	int n;
	set<int>s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(i);
	}
	auto i = s.begin();
	while(s.size()>1){
		int x = (a[i]-s.size())%s.size();
		if(x==0){
			auto it = s.end();
			it--;
			s.erase(it);
		}else{
			auto it = s.begin();
			it+= x-1;
			s.erase(it);
		}
		i = s.begin();
		i+=x;
	}
	for(auto j: s){
		cout<<j<<endl;
	}
	return 0;
}
