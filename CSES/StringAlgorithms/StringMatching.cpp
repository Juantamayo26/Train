#include <bits/stdc++.h>
//https://planetmath.org/goodhashtableprimes
using namespace std;

#define endl '\n'
#define ll long long
const ll maxi = 10000000;
//const ll M = 1e11;
const ll M = 999727999;
const ll P = 1610612741;
//const ll P = 1777771;
ll hasha[maxi];

int main(){
  ios::sync_with_stdio(0); cin.tie(0); 
  string a; cin>>a;
  string b; cin>>b;
  ll pot = 1;
  for(int i=0; i<a.length(); i++){
    hasha[i+1] = (hasha[i]+(pot*(a[i]-('a'-1))))%M;
    pot = (pot*P)%M;
  }
  pot = 1;
  ll hashb=0;
  for(int i=0; i<b.length(); i++){
    hashb = (hashb+(pot*(b[i]-('a'-1))))%M;
    pot = (pot*P)%M;
  }
  ll ans=0;
  ll tam = b.length();
  hasha[0]=0;
  for(int i=0; i<=a.length(); i++){
//    if(((hasha[tam]-hasha[i]+M)%M)==hashb){
    if((hasha[tam]-hasha[i])==hashb){
      ans++;
    }
    hashb=(hashb*P)%M;
    tam++;
  }
  cout<<ans<<endl;
}
