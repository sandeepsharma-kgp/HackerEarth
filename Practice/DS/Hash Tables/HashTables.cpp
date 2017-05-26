#include<iostream>
#define ll long long
//#define tableSize 1e4+1
#define keySize 100000 + 1
#include <conio.h>
#include <stdio.h>
#include<stack>
#include<vector>
#include<list>
using namespace std;

//ll keySize=10001;

vector<pair<ll,string> > hashTable[keySize];



void insertName(ll roll,string name)
{
    int index=roll%keySize;
//    for(int i=0;i<keySize;i++)
//    cout<<index<<" "<<roll<<" "<<name;
    while(hashTable[index][1].first!=0)
    {
            index=(index+1)%keySize;

    }
    hashTable[index].push_back(make_pair(roll,name));
//    cout<<(hashTable[index].begin()+1)->first<<" "; // Why value inserting at index 1 instead of 0??
//                                                    //Answer is we pushing back default value at index 0;
//    cout<<hashTable[index].begin()->second<<endl;
//    hashTable[index].push_back(name);

}

string searchName(ll roll)
{
    int index=roll%keySize;
//    cout<<index;
    while(hashTable[index][1].first!= roll && hashTable[index][1].first!=0)
            index = (index + 1) % keySize;
    return(hashTable[index][1].second);
}

int main()
{
    int n;
    cin>>n;
    ll roll;
    string name;
    for(int i=0;i<keySize+1;i++)
    {

        hashTable[i].push_back(make_pair(0,""));
//        cout<<"Initializing";
    }
//    cout<<"Enter Details: \n";
    for(int i=0;i<n;i++)
    {
        cin>>roll>>name;
//        cout<<"Inserting\n";
        insertName(roll,name);
    }
//    cout<<"Printing Result\n";
    int q;
    cin>>q;
    string a[q];
    for(int i=0;i<q;i++)
    {
//        cout<<"Query: \n"<<i;
        cin>>roll;
        a[i]=searchName(roll);
    }
    for(int i=0;i<q;i++)
    {
//        cout<<"Query: \n"<<i;
//        cin>>roll;
        cout<<a[i]<<endl;
    }
    return 0;
}
