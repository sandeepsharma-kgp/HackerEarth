#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char ch;
    queue<int> q;
    int j=0,a[n],in;
    int b[n];
    char c[n];
    for(int i=0;i<n;i++)
    {
        cin>>ch;
        if(ch=='E')
        {
            cin>>in;
            q.push(in);
            a[j]=q.size();
            b[j]=in;
            c[j]='E';
            j++;
        }
        if(ch=='D')
        {
            c[j]='D';

            if(!q.empty())
            {

                b[j]=q.front();
                q.pop();
                a[j]=q.size();
                j++;

            }
            else
            {
                a[j]=0;
                b[j]=-1;
                j++;
            }
        }
    }
    int m=j;
    for(j=0;j<m;j++)
    {
        if(c[j]=='E')
            cout<<a[j]<<endl;
        else
            cout<<b[j]<<" "<<a[j]<<endl;
    }
    return 0;
}
