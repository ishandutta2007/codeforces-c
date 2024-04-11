#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a)    memset(a,0,sizeof(a))
#define mem1(a)    memset(a,-1,sizeof(a))
#define memf(a)    memset(a,false,sizeof(a))
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

const long double PI = acos(-1);

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

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

const int N=200005,NN=11;
map<ll,ll> m[NN];
ll a[N],po[11];
int _runtimeTerror_()
{
    ll n,k;
    cin>>n>>k;
    ll pre[n+1];
    for(int i=0;i<n;++i){
        cin>>a[i];
        int x=sz(to_string(a[i]));
        pre[i]=x;
        m[x][a[i]%k]++;
    }
    ll ans=0;
    po[0]=1;
    for(int i=1;i<=10;++i)po[i]=po[i-1]*10%k;
    for(int i=0;i<n;++i)
    {
        // if num is in starting
        m[pre[i]][a[i]%k]--;
        for(int len=1;len<=10;++len)
        {
            ll val;
            val=a[i]%k;
            val*=po[len];
            val%=k;
            val=k-val;val%=k;
            if(m[len].count(val))
                ans+=m[len][val];
        }
        m[pre[i]][a[i]%k]++;
    }
    cout<<ans<<endl;
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
    cerr<<"\n"<<_time_;
    return 0;
}