#include<bits/stdc++.h>
using namespace std;
 map<char,long long> frecl;
map<string,long long> pal;
string A;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long n,ans=0,aux=0;
    cin>>n;
    while(n--){
        cin>>A;
        frecl[A[0]]++;
        pal[A]++;
    }
    for(auto i: frecl){
        ans+=i.second * (i.second-1);
    }
    for(auto i: pal){
        if(i.second>1){
            ans=ans-(i.second*(i.second-1));
        }
    }
    cout<<ans<<endl;
}

