// Har Har Mahadev
#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

int _runtimeTerror_()
{
    ll ans = 0;
    int a,b,n;
    cin>>a>>b>>n;
    vector<int> aa(n+1),bb(n+1);
    map<int,int> x,y;
    map<pii,int> z;
    for(int i=1;i<=n;++i)
    {
        cin>>aa[i];
        ++x[aa[i]];
    }
    for(int i=1;i<=n;++i)
    {
        cin>>bb[i];
        ++y[bb[i]];
        ++z[{aa[i],bb[i]}];
    }
    for(int i=1;i<=n;++i)
    {
        ll u = n - x[aa[i]] - y[bb[i]] + z[{aa[i],bb[i]}];
        ans += u;
    }
    ans /= 2;
    cout<<ans<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}