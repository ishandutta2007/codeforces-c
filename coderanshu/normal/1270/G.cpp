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

const int N = 1000005;

bitset<N> vis;
int r[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        vis[i] = 0;
        cin>>r[i];
        r[i] = i - r[i];
    }
    function<bool(int)> dfs = [&](int v)
    {
        if(r[v] == v)
        {
            cout<<"1\n"<<v<<"\n";return true;
        }
        int x = v;
        vector<int> ans;
        vis[v] = 1;
        ans.pb(v);
        v = r[v];
        for(;v;v = r[v])
        {
            if(vis[v])
            {
                vector<int> t;
                while(ans.back()!=v)
                    t.pb(ans.back()),ans.pop_back();
                t.pb(v);
                cout<<sz(t)<<"\n";
                for(auto j:t)
                    cout<<j<<" ";
                cout<<"\n";
                return true;
            }
            vis[v] = 1;
            ans.pb(v);
        }
        return false;
    };
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            if(dfs(i))
                return 0;
        }
    }
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