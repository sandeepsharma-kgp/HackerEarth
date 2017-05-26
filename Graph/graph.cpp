#include <iostream>
using namespace std;


ll main()
{
	ll n,m,a,b,q;
	cin>>n>>m;
	ll A[n][n];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			A[i][j]=0;

	for(ll i=0;i<m;i++)
	{
		cin>>a>>b;
		A[a][b]=1;
		A[b][a]=1;
	}
	cin>>q;
	ll check[q];
	for(ll i=0;i<q;i++)
	{
		cin>>a>>b;
		check[i]=A[a][b];
	}
	for (ll i=0;i<q;i++)
	{
		if(check[i])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

    return 0;
}
