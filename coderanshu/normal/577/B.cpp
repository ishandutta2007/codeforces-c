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
const int N=1005;
bool dp[N][N];
int a[N];

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    if(n>m)
    {
        cout<<"YES\n";
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]%=m;
        if(a[i]==0)
            a[i]+=m;
    }
    dp[0][0]=true;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
            dp[i][j]=dp[i-1][j];
        for(int j=0;j<=m;++j)
        {
            int x=j+a[i];
            if(j+a[i]>m)
                x%=m;
            dp[i][x]|=dp[i-1][j];
        }
    }
    cout<<(dp[n][m]?"YES\n":"NO\n");
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