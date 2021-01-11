#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m=0,inn=0,aux,cont=0,no;
    vector<long long>A;
    map<long long,pair<long long,long long>>rep;
    cin>>n;
    for(long long i=0; i < n;i++)
    {
        cin>>aux;
        A.push_back(aux);

        if(rep[aux].first==0 && i!=0 && aux != no)
            rep[aux].first=i;
        else
        {
            if(i!=0)
                rep[aux].second++;
        }    
        if(i == 0)
            no = aux;
    }
    // for(auto i:rep)
    //     cout<<i.first<<" , "<<i.second.first<<" , "<< i.second.second<<"\n";
    for(long long i=0;i < n; i++)
    {
        if(rep[A[i]].first == i)
        {
            if(rep[A[i]].second > 1)
                inn += rep[A[i]].second -1;
            inn+=cont;
            if(rep[A[i]].second > 0)
                cont += rep[A[i]].second -1;
            inn +=( m * rep[A[i]].second);
            m++;
        }
        else
        {
            if(rep[A[i]].second > 1)
            {
                rep[A[i]].second--;
                cont--;
            }
            inn += A.size()-i-1;
        }
    }
    cout<<(((A.size()-1)*A.size())/2) - inn<<"\n";
}
