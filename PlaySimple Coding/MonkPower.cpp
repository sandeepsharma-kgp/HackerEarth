#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18

int main()
{
	ll T,N,k,A[100000],l,h,pdt;
	cin>>T;
	ll B[T];
	for(ll i=0;i<T;i++)
    {
        cin>>N;
        cin>>k;
        for(ll j=0;j<N;j++)
        {
            cin>>A[j];
        }

        l=0;
        h=N-1-k;
        pdt=1;
        for(ll p=0;p<k;p++)
        {
          if(pdt<A[l]*A[h])
            {
                pdt=A[l]*A[h];
            }
            l++;
            h++;

        }
        B[i]=1;
        B[i]=pdt;
    }

    for(ll i=0;i<T;i++)
    {
        cout<<B[i]<<"\n";
    }
}
