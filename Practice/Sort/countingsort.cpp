#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],sort_a[n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        k=max(k,a[i]);
    }
//    cout<<k<<endl;
    int aux[k+1];
    for(int i=0;i<k+1;i++)
    {
        aux[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        aux[a[i]]++;
    }
    int temp,j=0;

    for(int i=0;i<=k;i++)
    {
        temp=aux[i];
        while(temp--)
        {
            sort_a[j]=i;
            j++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<sort_a[i]<<" "<<aux[sort_a[i]]<<endl;
        while(sort_a[i]==sort_a[i+1])
            i++;
    }
    return 0;
}
