#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18
#define SIZE 100000 + 1
#define dis 1000000000

vector < pair < ll , ll > > v [SIZE];   // each vertex has all the connected vertices with the edges weights
ll dist [SIZE];
bool vis [SIZE];

void dijkstra(){
                                                // set the vertices distances as infinity
    memset(vis, false , sizeof vis);
    memset(dist,dis,sizeof dist);           // set all vertex as unvisited
    dist[1] = 0;
    multiset < pair < ll , ll > > s;          // multiset do the job as a min-priority queue

    s.insert({0 , 1});                          // insert the source node with distance = 0

    while(!s.empty()){

        pair <ll , ll> p = *s.begin();        // pop the vertex with the minimum distance
        s.erase(s.begin());

        ll x = p.ss; ll wei = p.ff;
        if( vis[x] ) continue;                  // check if the popped vertex is visited before
         vis[x] = true;

        for(ll i = 0; i < v[x].size(); i++){
            ll e = v[x][i].ff; ll w = v[x][i].ss;
            cout<<endl<<e<<" "<<w;
            if(dist[x] + w < dist[e]  ){            // check if the next vertex distance could be minimized
                dist[e] = dist[x] + w;
                s.insert({dist[e],  e} );           // insert the next vertex with the updated distance
            }
        }
        cout<<"\nfor";
        std::multiset<pair < ll , ll > >::iterator i;
        for (std::multiset<pair < ll , ll > >::iterator i=s.begin();  i != s.end();++i){
                    std::cout << i->first<<" "<<i->ss<< "\n";
                    cout<"first";
        }
    }
}

int main()
{
    ll x, y;
    ll weight, cost, minimumCost;
    ll nodes,edges;
    cin >> nodes >> edges;
    for(ll i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        v[x].push_back(make_pair(y, weight));
    }
    dijkstra();

    return 0;
}
