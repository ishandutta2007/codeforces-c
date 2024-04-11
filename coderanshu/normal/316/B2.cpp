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
const int N=1005;
vector<int> v[N];
bool dp[N];
int dep[N],x,cnt;
bool smartyBoi;
vector<int> root,comps;

void dfs(int s,int d)
{
	dep[s]=d;
	++cnt;
	if(s==x)
		smartyBoi=true;
	for(auto j:v[s])
		dfs(j,d+1);
}
int _runtimeTerror_()
{
	int n;
	cin>>n>>x;
	for(int i=1;i<=n;++i)
	{
		int xx;
		cin>>xx;
		if(!xx)
		{
			root.pb(i);continue;
		}
		v[xx].pb(i);
	}
	for(auto k:root)
	{
		cnt=0;
		smartyBoi=false;
		dfs(k,1);
		if(smartyBoi)
			dp[dep[x]]=true;
		else comps.pb(cnt);
	}
	for(auto j:comps)
	{
		for(int i=1001-j;i>=0;--i)
			dp[i+j]=dp[i+j] || (dp[i]);
	}
	for(int i=1;i<=n;++i)
		if(dp[i])
			cout<<i<<endl;
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