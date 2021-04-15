//https://www.codechef.com/problems/FLOW016
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  ll a, b, auxa, auxb;
  int t;
  cin>>t;
  while(t){
    cin>>a>>b;
    auxa = a, auxb = b;
    while(b){
      a%=b;
      swap(a, b);
    }
    cout<<a<<" "<<(auxa*auxb)/a<<endl;
    t--;
  }
	return 0;
}

