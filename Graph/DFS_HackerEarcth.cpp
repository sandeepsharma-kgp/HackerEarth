#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18

    vector <int> adj[100000];
    vector<bool> visited(100000,false);
    vector<int> check(100000,0);
    int cnt=0;

    void dfs(int s) {
        visited[s] = true;
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
             dfs(adj[s][i]);
        }
    }
    void dfs(int s,int g) {
        visited[s] = true;
        check[g]=1;
        for(int i = 0;i < adj[s].size();++i)    {
         if(check[adj[s][i]] == 0){
                check[adj[s][i]]=1;
             dfs(adj[s][i],g);
             }
        }

    }

    int main() {
        int nodes, edges, x, y, connectedComponents = 0;
        cin >> nodes>> edges;                       //Number of edges
        for(int i = 0;i < edges;++i) {
         cin >> x >> y;
     //Undirected Graph
         adj[x].push_back(y);                   //Edge from vertex x to vertex y
         adj[y].push_back(x);                   //Edge from vertex y to vertex x
        }
        int g;
        cin>>g;
        for(int i = 1;i <= nodes;++i) {
         if(i==g)     {
             dfs(i,g);
         }
         else if(visited[i] == false){
            dfs(i);
         }
        }
        for(int i=1;i<=nodes;i++){
            if(check[i])
                cnt++;
        }
        cout <<nodes-cnt<< endl;
        return 0;
    }
