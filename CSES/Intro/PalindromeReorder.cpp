#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long
string ans;

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  string n;
  cin>>n;
  unordered_map<char,int>s;
  //map<char, int>s;
  string imp;
  for(char i: n){
    s[i]++;
  }
  int impar=0;
  for(auto i: s){
    if(i.second&1){
      for(int j=0; j<i.second; j++){
        imp.push_back(i.first);
      }
      impar++;
    }else{
      for(int j=0; j<(i.second/2); j++){
        ans.push_back(i.first);
      }
    }
  }
  if(impar>=2){
    cout<<"NO SOLUTION"<<endl;
    return 0;
  }
  string rev = ans+imp;
  reverse(ans.begin(), ans.end());
  rev = rev+ans;
  cout<<rev<<endl;
}

