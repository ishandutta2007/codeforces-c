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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n,k;
    cin >> n >> k;
    vector<ll> a(n+1,0);
    vector<int> p;
    for(int i=1;i<=k;++i)
    {
        int x;
        cin >> x;
        p.push_back(x);
    }
    for(int i=0;i<k;++i)
        cin >> a[p[i]];
    vector<ll> ans(n+1,INF);
    ll cur = INF;
    for(int i=1;i<=n;++i)
    {
        if(a[i])
            amin(cur,a[i] - i);
        amin(ans[i],cur + i);
    }
    cur = INF;
    for(int i=n;i>=1;--i)
    {
        if(a[i])
            amin(cur,a[i] + i);
        amin(ans[i],cur - i);
    }
    for(int i=1;i<=n;++i)
        cout << ans[i] << " ";
    cout << "\n";
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