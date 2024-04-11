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
    int n;
    cin>>n;
    vector<pii> op;
    if(n>8)
    {
        for(int i=3;i<=7;++i)
            op.pb({i,n});
        for(int i=9;i<n;++i)
            op.pb({i,n});
        for(int i=1;i<=6;++i)
            op.pb({n,8});
        for(int i=1;i<=3;++i)
            op.pb({8,2});
    }
    else
    {
        for(int i=3;i<n;++i)
            op.pb({i,n});
        for(int i=1;i<=3;++i)
            op.pb({n,2});
    }
    cout<<sz(op)<<"\n";
    for(auto j:op)
        cout<<j.F<<" "<<j.S<<"\n";
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