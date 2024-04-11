#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
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
#define runSieve
bool notPrime[1000005];
ll divPrime[1000005];
void sieve(int n=1000000)
{
    int k=sqrt(n);
    memf(notPrime);
    notPrime[1]=true;
    for(int i=2;i<=k;++i)
    {
        if(!notPrime[i])
        {
            for(int k=i*i;k<=n;k+=i)
            {
                notPrime[k]=true;
                divPrime[k]=i;
            }
        }
    }
}
#define NCR 
const int N=5000005,MOD=M;
ll inv[N],fac_inv[N],fac[N];
void initialize()
{
    ll i;
    inv[1]=1;
    for(i=2;i<=N-2;i++)
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD; 
    fac[0]=fac[1]=1;
    for(i=2;i<=N-2;i++)
        fac[i]=i*fac[i-1]%MOD;
    fac_inv[0]=fac_inv[1]=1;
    for(i=2;i<=N-2;i++)
        fac_inv[i]=inv[i]*fac_inv[i-1]%MOD;
}
ll ncr(ll n,ll r)
{
    if(n<r) return 0;
    return (fac[n]*fac_inv[r]%MOD)*fac_inv[n-r]%MOD;
}

int _runtimeTerror_()
{
    ll k,y;
    cin>>k>>y;
    ll ans=1;
    while(k!=1 && notPrime[k])
    {
        ll z=divPrime[k],cnt=0;
        while(k%z==0)k/=z,++cnt;
        ans*=ncr(cnt+y-1,cnt);
        ans%=M;
    }
    if(k!=1)
        ans*=y;
    ans%=M;
    ans*=power(2,y-1,M);
    ans%=M;
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    cerr<<"\n"<<_time_;
    return 0;
}