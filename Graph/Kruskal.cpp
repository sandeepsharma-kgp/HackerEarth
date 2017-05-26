#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 1e18
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const ll MAX = 1e5 + 5;
ll id[MAX], nodes, edges;
pair <long long, pair<ll, ll> > p[MAX];

void initialize()
{
    for(ll i = 0;i < MAX;++i)
        id[i] = i;
}

ll root(ll x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(ll x, ll y)
{
    ll p = root(x);
    ll q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<ll, ll> > p[])
{
    ll x, y;
    long long cost, minimumCost = 0;
    for(ll i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    ll x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(ll i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}
