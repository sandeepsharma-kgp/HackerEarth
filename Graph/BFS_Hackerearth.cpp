#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18
int n;
int main()
{
    int b,a,temp;
    cin>>n;
    vector<int> v[n+1];
    int level[n+1];
    bool vis[n+1];
    for(int i=0;i<n+1;i++)
    {
    	level[i]=0;
    }
    for(int i=0;i<n+1;i++)
    {
    	vis[i]=false;
    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>a>>b;
        if(b==1)
        {
            temp=a;
            a=b;
            b=temp;
        }
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue <int> q;
    int s=1;
    q.push(s);
    level[s]=0;
    vis[s]=true;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();

        for(int i = 0;i < v[ p ].size() ; i++)
        {
//            cout<<"\nv[ p ].size(): "<<v[ p ].size()<<"for p: "<<p;
            if(vis[ v[ p ][ i ] ] == false)
            {
//                cout << "Adjacency list of node " << p << ": "<<v[p][i] << " --> ";
//        Setting the level of each node with an increment in the level of parent node
                 level[ v[ p ][ i ] ] = level[ p ]+1;
                 q.push(v[ p ][ i ]);
                 vis[ v[ p ][ i ] ] = true;
            }
//            cout<<"\nNow queue front has: "<<q.front()<<" and it has visited: "<<vis[ v[ p ][ i ] ];
        }
//        cout<<endl<<"is empty for: "<<q.front()<<" : "<<q.empty()<<endl;

    }

//    cout<<"\n";
//    for (int i=1;i<=n;i++)
//    {
//        cout<<endl<<i<<" "<<level[i]<<" ";
//    }
    int g;
//    cout<<"\nSolution for : ";
    cin>>g;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(level[i]==g-1)
            cnt++;
    }
    cout<<cnt;
//    for(int i = 1;i <= n;++i)
//    {
//        cout << "\nAdjacency list of node " << i << ": ";
//        for(int j = 0;j < v[i].size();++j)
//            {
//            if(j == v[i].size() - 1)
//                    cout << v[i][j];
//            else
//                cout << v[i][j] << " --> ";
//            }
//
//    }
//    return 0;
}
