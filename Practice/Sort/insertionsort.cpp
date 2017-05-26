#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18



void insertionnsort(int b[],int n)
{
    int temp;
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=b[i];
    }
    int c[n];
    for(int i=0;i<n;i++)
    {
        temp=b[i];
        int j=i;
        while(j>0 && temp<b[j-1])
        {
            b[j]=b[j-1];
            j--;
        }
        b[j]=temp;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i]==a[j])
            {
                c[j]=i+1;
            }
        }
    }
//    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<c[i]<<" ";
    }
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertionnsort(a,n);

    return 0;
}
