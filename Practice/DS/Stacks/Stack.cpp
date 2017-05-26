#include <iostream>
#include<stack>
using namespace std;

int main()
{
    int i,j,n,inp,cost;
    cin>>n;
    stack<int> s;
    int a[n];
    for(i=0,j=0;i<n;i++)
    {
        cin>>inp;
        if(inp==1)
        {
            if(s.empty())
                {
                    a[j]=0;
                    j++;
                }
            else
            {
                a[j]=s.top();
                j++;
                s.pop();
            }
        }
        else if(inp==2)
        {
            cin>>cost;
            s.push(cost);
        }

    }
    int m=j-1;
    for(j=0;j<=m;j++)
    {
        if(a[j])
        {
            cout<<a[j]<<endl;
        }
        else
        {
            cout<<"No Food";

        }
    }
    return 0;
}
