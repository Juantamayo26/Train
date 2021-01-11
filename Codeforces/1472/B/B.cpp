#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
  //ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    ll dos = 0;
    ll dos1 = 0;
    ll uno = 0;
    for(int i=0; i<n;i++){
      int a;
      cin>>a;
      if(a==2){
        dos1+=2;
        dos++;
      }else{
        uno++;
      }
    }
    if((uno+dos1)%2==0 && uno !=0 && uno%2 ==0){
      cout<<"YES"<<endl;
    }else if(uno==0 && dos%2==0){
      cout<<"YES"<<endl;
    }else if(dos==0 && uno%2==0){
      cout<<"YES"<<endl;
    }else if((uno%2==0 && dos%2==0)){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
  
  return 0;
}

