#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define present(m,v) (m.find(v)!=m.end())
#define INF 1e18
#define mod 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define forn(i,a,b) for(i=a;i<b;i++)

ll CeilIndex(std::vector<ll> &v, ll l, ll r, ll key) {
    while (r-l > 1) {
    ll m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }

    return r;
}

ll FloorIndex(std::vector<ll> &v, ll l, ll r, ll key) {
    while (r-l > 1) {
    ll m = l + (r-l)/2;
    if (v[m] >= key)
        l = m;
    else
        r = m;
    }

    return r;
}

ll LongestIncreasingSubsequenceLength(std::vector<ll> &v) {
    if (v.size() == 0)
        return 0;

    std::vector<ll> tail(v.size(), 0);
    ll length = 1;

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }
    return length;
}

ll LongestDecreasingSubsequenceLength(std::vector<ll> &v) {
    if (v.size() == 0)
        return 0;

    std::vector<ll> tail(v.size(), 0);
    ll length = 1;

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] > tail[0])
            tail[0] = v[i];
        else if (v[i] < tail[length-1])
            tail[length++] = v[i];
        else
            tail[FloorIndex(tail, -1, length-1, v[i])] = v[i];
    }
    return length;
}


int main()
{
	ll n,i;
	cin>>n;
	vector<ll> a(n);
	for(i=0;i<n;i++)
        cin>>a[i];
    ll l=LongestIncreasingSubsequenceLength(a);
    ll d=LongestDecreasingSubsequenceLength(a);
    cout<<min(n-l,n-d);
	return 0;
}
