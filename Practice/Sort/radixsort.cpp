#include<iostream>
#define ll long long

using namespace std;

void countsort(ll arr[],int n,int place)
{
    int range=10,temp=0;
    int i,freq[range];
    for(int i=0;i<range;i++)
    {
        freq[i]=0;
    }
    //range for integers is 10 as digits range from 0-9
    int output[n];
    for(i=0;i<n;i++)
    {
        freq[(arr[i]/place)%range]++;
        cout<<freq[i]<<endl;
    }

    for(i=1;i<range;i++)
    {
//        cout<<freq[i]<<endl;
        // temp=freq[i];
        freq[i]+=freq[i-1];
//        cout<<place<<" "<<temp<<" "<<freq[i]<<endl;
    }

    for(i=n-1;i>=0;i--)
    {
        temp=freq[(arr[i]/place)%range];
        output[temp-1]=arr[i];
//            cout<<(arr[i]/place)%range<<" "<<output[freq[(arr[i]/place)%range]-1]<<endl;
        freq[(arr[i]/place)%range]--;
    }
//    cout<<endl;
    for(i=0;i<n;i++)
    {
         arr[i]=output[i];
         cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void radixsort(ll arr[],int n,ll maxx)            //maxx is the maximum element in the array
{
        ll mul=1;
        while(maxx)
        {
                countsort(arr,n,mul);
                mul*=10;
                maxx/=10;
        }
}

int main()
{
    int n;
    cin>>n;
    ll a[n],maxx=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
//    cout<<maxx;
    radixsort(a,n,maxx);
    return 0;
}
