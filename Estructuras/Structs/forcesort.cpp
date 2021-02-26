#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long

//struct data{
//  int a, b;
//  bool operator < (const data &other) const{
//    return b < other.b;
//  }
//};
//
//int main(){
//  ios::sync_with_stdio(0); cin.tie(0); 
//  vector<data> v;
//  v.push_back({5,4});
//  v.push_back({4,8});
//  v.push_back({1,4});
//  v.push_back({8,9});
//
//  sort(v.begin(), v.end());
//  
//  for(auto i : v){
//    cout<<i.a<<" "<<i.b<<endl;
//  }
//}

bool cmp(const pair<int, int> &a, const pair<int, int> &b){
  return a.second > b.second;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  vector<pair<int, int> > v;
  v.push_back({5,4});
  v.push_back({4,8});
  v.push_back({1,4});
  v.push_back({8,9});
  sort(v.begin(), v.end(), cmp);
  for(auto i : v)
    cout<<i.first<<" "<<i.second<<endl;

}

