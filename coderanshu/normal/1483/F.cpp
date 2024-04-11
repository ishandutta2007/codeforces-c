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

template<typename T=long long>
struct fenwick {
    T a[N],bit[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            a[i] = T(0),bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;j+=j&-j)
                bit[j] += a[i];
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
};
fenwick<int> fenw;
// call fenw.build(n);

struct node {
    map<char,int> next;
    int end = -1;
    int link;
    node(){}
};

vector<int> g[N];
int in[N],out[N],cur = 1;
void dfs(int u)
{
    in[u] = cur++;
    for(auto &j:g[u])
        dfs(j);
    out[u] = cur-1;
}
int par[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<string> a(n+1);
    int nxt = 1;
    vector<node> tr{1};
    auto add = [&](string &t,int id)
    {
        int cur = 0;
        for(auto &j:t)
        {
            if(!tr[cur].next.count(j))
                tr[cur].next[j] = nxt++,tr.push_back(node());
            cur = tr[cur].next[j];
        }
        tr[cur].end = id;
    };
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        add(a[i],i);
    }
    auto link = [&]()
    {
        queue<int> Q;
        Q.push(0);
        tr[0].link = -1;
        // tr[0].up = N;
        tr[0].end = n+1;
        while(!Q.empty())
        {
            int u = Q.front(); Q.pop();
            for(auto &j:tr[u].next)
            {
                char c = j.F;
                int v = j.S;
                int k = tr[u].link;
                while(k != -1 && !tr[k].next.count(c))
                    k = tr[k].link;
                if(k == -1)
                    tr[v].link = 0;
                else
                    tr[v].link = tr[k].next[c];
                Q.push(v);
                if(tr[v].end != -1)
                {
                    g[tr[tr[v].link].end].push_back(tr[v].end);
                    par[tr[v].end] = tr[tr[v].link].end;
                }
                if(tr[v].end == -1)
                    tr[v].end = tr[tr[v].link].end;
            }
        }
    };
    link();
    fenw.build(n+10);
    dfs(n+1);
    ll ans = 0;
    for(int i=1;i<=n;++i)    
    {
        int sz = sz(a[i]);
        int best = sz;
        vector<int> nodes(sz);
        int cur = 0;
        for(int j=0;j<sz;++j)
        {
            cur = tr[cur].next[a[i][j]];
            nodes[j] = cur; 
        }
        set<int> check;
        vector<int> bad;
        for(int j=sz-1;j>=0;--j)
        {
            int v = tr[nodes[j]].end;
            if(j == sz-1)
                v = par[v];
            if(v == n+1)
                continue;
            int l = j - sz(a[v]) + 1;
            if(l < best)
            {
                best = l;
                check.insert(v);
                v = par[v];
            }
            if(v != n+1)
            {
                bad.push_back(v);
            }
        }
        for(auto &j:bad)
            fenw.update(in[j],1);
        for(auto &j:check)
            ans += fenw.query(in[j],out[j]) == 0;
        for(auto &j:bad)
            fenw.update(in[j],-1);
    }
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}