#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18



void selectionsort(int b[],int n,int x)
{
    int minimum=0,temp=0;
    for(int i=0;i<n-1 && i<x;i++)
    {
        minimum=i;
        for(int j=i+1;j<n;j++)
        {
            if(b[j]<b[minimum])
            {
                minimum=j;
            }
        }
        temp=b[i];
        b[i]=b[minimum];
        b[minimum]=temp;
    }
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
}

int main()
{
	int n,x;
	cin>>n>>x;
	int a[n];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    selectionsort(a,n,x);

    return 0;
}
