#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N=200005;
ll n;
ll a[N];
ll b[N];
ll c[N];
ll f[33];

int _runtimeTerror_()
{
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;++i)
        cin>>b[i],sum+=b[i];
    for(int i=1;i<=n;++i)
        cin>>c[i],sum+=c[i];
    if(sum%(2*n))
    {
        cout<<-1;
        return 0;
    }
    sum/=2*n;
    for(int i=1;i<=n;++i)
    {
        ll x=b[i]+c[i]-sum;
        if(x%n)
        {
            cout<<-1;
            return 0;
        }
        a[i]=x/n;
        for(int j=0;j<=32;++j)
            if(a[i]&(1LL<<j))
                f[j]++;
    }
    for(int i=1;i<=n;++i)
    {
        ll x=0,y=0;
        for(int j=0;j<=32;++j)
            if(a[i]&(1LL<<j))
                x+=(1LL<<j)*f[j];
        for(int j=0;j<=32;++j)
        {
            if(a[i]&(1LL<<j))
                y+=n*(1LL<<j);
            else
                y+=f[j]*(1LL<<j);
        }
        if(x!=b[i] || y!=c[i])
        {
            cout<<-1;
            return 0;
        }
    }
    for(int i=1;i<=n;++i)
        cout<<a[i]<<" ";
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