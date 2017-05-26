#include<iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <ctime>
#define ll long long
using namespace std;

ll rand_partition(ll c[],ll s, ll e)
{
    ll temp;
    srand(time(NULL));
    ll pos=s+rand()%(e-s+1);


    temp=c[s];
    c[s]=c[pos];
    c[pos]=temp;

    ll i=s+1;
    ll piv=c[s];
    for(ll j=s+1;j<=e;j++)
    {
        if(c[j]<=piv)
        {
            temp=c[j];
            c[j]=c[i];
            c[i]=temp;
            i+=1;
        }
    }
    temp=c[s];
    c[s]=c[i-1];
    c[i-1]=temp;
    return i-1;
}

void quick_sort(ll b[],ll s,ll e)
{
    if(s<e)
    {
        ll piv_pos=rand_partition(b,s,e);
        quick_sort(b,s,piv_pos-1);
        quick_sort(b,piv_pos+1,e);
    }
}

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    quick_sort(a,0,n-1);
     for(ll i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

}
