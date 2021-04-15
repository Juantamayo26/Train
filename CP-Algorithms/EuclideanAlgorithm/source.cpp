#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int a, b;
  cin>>a>>b;
  while(b){
    a%=b;
    swap(a,b);
  }
  cout<<a<<endl;
	return 0;
}

