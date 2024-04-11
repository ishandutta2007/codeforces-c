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
struct SAT
{
    int n;
    vector<int> a;
    vector<vector<int>> g,rg;

    SAT(){}

    SAT(int n_):n(n_)
    {
        a.resize(2*n+1);
        g.resize(2*n+1);
        rg.resize(2*n+1);
    }
    void add_edge(int x,int y,bool negx,bool negy)
    {
        --x,--y;
        x *= 2,y *= 2;
        if(negx)
            x ^= 1;
        if(negy)
            y ^= 1;
        g[x].push_back(y);
        g[y^1].push_back(x^1);
        rg[y].push_back(x);
        rg[x^1].push_back(y^1);
    }

    vector<int> solve()
    {
        vector<int> order;
        vector<bool> vis(2*n+1,0);
        vector<int> comp(2*n+1,0);
        function<void(int)> dfs1 = [&](int u)
        {
            vis[u] = true;
            for(auto j:g[u])
                if(!vis[j])
                    dfs1(j);
            order.push_back(u);
        };
        for(int i=0;i<2*n;++i)
            if(!vis[i])
                dfs1(i);
        reverse(order.begin(),order.end());
        int cur = 1;

        function<void(int,int)> dfs = [&](int u,int cmp)
        {
            comp[u] = cmp;
            for(auto j:rg[u])
                if(comp[j] == 0)
                    dfs(j,cmp);
        };
        for(int i:order)
        {
            if(comp[i] == 0)
                dfs(i,cur++);
        }
        vector<int> ans(n+1);
        for(int i=0;i<n;++i)
        {
            int j = i * 2;
            if(comp[j] == comp[j+1])
                return {-1};
            ans[i+1] = comp[j] > comp[j+1];
        }
        return ans;
    }
};


int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<int> r(n+1);
    for(int i=1;i<=n;++i)
        cin>>r[i];
    SAT sat(m);
    vector<vector<int>> g(n+1);
    for(int i=1;i<=m;++i)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int x;
            cin>>x;
            g[x].push_back(i);
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(r[i])
        {
            sat.add_edge(g[i][0],g[i][1],0,0);
            sat.add_edge(g[i][1],g[i][0],0,0);
        }
        else
        {
            sat.add_edge(g[i][0],g[i][1],0,1);
            sat.add_edge(g[i][1],g[i][0],1,0);
        }
    }
    auto ans = sat.solve();
    if(ans[0] == -1)
        cout<<"NO\n";
    else
        cout<<"YES\n";
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}