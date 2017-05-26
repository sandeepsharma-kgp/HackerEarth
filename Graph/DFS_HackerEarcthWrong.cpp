#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18



    int main() {
        int edges, x, y, connectedComponents = 0;
        int nodes;
        cin >> nodes>> edges;
        vector<vector<int> > adj(nodes+1);
        vector<bool> visited(nodes+1,false);
        vector<int> check(nodes+1,0);
                      //Number of edges
        for(int i = 0;i < edges;++i) {
         cin >> x >> y;
     //Undirected Graph
         adj[x].push_back(y);                   //Edge from vertex x to vertex y
         adj[y].push_back(x);                   //Edge from vertex y to vertex x
        }
        int g;
        cin>>g;
        for(int i = 1;i <=nodes;++i)
         cout<<" "<<visited[i];
         for(int i = 1;i <= nodes;++i)
        {
            cout << "\nAdjacency list of node " << i << ": ";
            for(int j = 0;j < adj[i].size();++j)
                {
                if(j == adj[i].size() - 1)
                        cout << adj[i][j];
                else
                    cout << adj[i][j] << " --> ";
                }

        }
        cout<<endl;
        int totalComponents=nodes,flag=0;
        connectedComponents=0;
        check[g]=1;
        for(int i=1;i<=nodes;i++)
        {
            if(visited[i]==false){
                    visited[i]=true;

            for(int j = 0;j < adj[i].size();++j)
            {
            if(check[i]==1)
                {
                check[adj[i][j]]=1;
                }

             if(visited[adj[i][j]] == false)
                {
                 visited[adj[i][j]] = true;
//                 cout<<adj[i][j]<<" visited\n";

//                     cout<<adj[i][j] <<" ||checked\n";
                    if(visited[adj[i][j]] == false)
//                        cout<<adj[i][j] <<" ||visited\n";
                        visited[adj[i][j]]=true;

    //             if(i==g)

                }

                }

            }
            }

        for (int k=1;k<=nodes;k++)
        {
            if(check[k])
                cout<<" "<<k;
        }
        return 0;
    }
