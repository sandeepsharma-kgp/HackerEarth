/****
You are given a list of amount of money of T people, one by one. After each element in the list print the top 3 richest people's amount of money.

****/

#include<iostream>
#include<vector>
#include<stdio.h>
#define ll long long
using namespace std;

ll b[3];

void heapify(ll arr[], ll n, ll i)
{
    ll largest = i;  // Initialize largest as root
    ll l = 2*i + 1;  // left = 2*i + 1
    ll r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


// main function to do heap sort
void heapSort(ll arr[], ll n)
{
    // Build heap (rearrange array)
    for (ll i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (ll i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    ll j=0;
    for(ll i=n-1;i>=n-3;i--)
    {
        b[j]=arr[i];
        j++;
    }
}

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    ll h[4];

//    vector<ll > v[n+1];
    ll c[n][3];
//
//    v[1].push_back(-1);
//    v[0].push_back(-1);
    c[0][0]=-1;
    c[1][0]=-1;
    for(ll i=0;i<n;i++)
    {
        scanf(" %lld",&a[i]);
//        cin>>a[i];
//        cout<<"taken\n";
//        cout<<a[i];
        if(i==2)
        {
            h[2]=a[i];
            h[3]=0;
        }

        if(i>1)
        {
            if(i!=2) h[3]=a[i];
            for(ll j=0;j<3;j++)
            {
                b[j]=0;
            }

            heapSort(h,4);
            c[i][0]=b[0];
            c[i][1]=b[1];
            c[i][2]=b[2];
            h[0]=b[0];
            h[1]=b[1];
            h[2]=b[2];
//            v[i].push_back(b[0]);
//            v[i].push_back(b[1]);
//            v[i].push_back(b[2]);
        }
        else
        {
            h[i]=a[i];
        }
    }

    for(ll i=0;i<n;i++)
    {
        if(i>1)
        {
            for(ll j=0;j<3;j++)
            {
//              cout<<v[i][j]<<"***"<<c[i][j]<<" ";
                printf("%lld ",c[i][j]);
            }
            cout<<endl;
        }
        else
        {
//            cout<<v[i][0]<<endl;
            printf("%lld\n",c[i][0]);
        }

    }
    return 0;
}
