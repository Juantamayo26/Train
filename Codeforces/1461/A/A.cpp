#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int t;
  cin>>t;
  while(t--){
    int a, b;
    cin>>a>>b;
    char A[3]={'a','b','c'};
    int aux2=0;
    int i=0;
    while(i<a){
      for(int j=0; j<b && i<a; j++){
        i++;
        if(aux2>2){
          aux2=0;
        }
        cout<<A[aux2];
      }
      aux2++;
    }
    cout<<endl;
  } 
  return 0;
}

