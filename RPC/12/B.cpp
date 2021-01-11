#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
#define pii pair<int, int>
const int maxi = 1e9;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  int n;
  cin>>n;
  int av=0, bx=0, cx=0;
  int bv=0;
  for(int i=0;i<n;i++){
    int a, b, c;
    cin>>a>>b>>c;
    bx+=b;
    cx+=c;
    if(b>c){
      av+=a;
    }else if(c>b){
      bv+=a;
    }
  }
  if(bx>cx&&av>bv){
    cout<<"1"<<endl;
  }else if(cx>bx&&bv>av){
    cout<<"2"<<endl;
  }else{
    cout<<0<<endl;
  }
  
  return 0;
}

