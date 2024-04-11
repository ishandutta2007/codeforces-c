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
#define PI 3.1415926536
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
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

int n;
const int N=300005;
vector<int> v[N];
bool vis[N];
int val[N];
int dp[N][2],ans=0;
void dfs(int s)
{
	vis[s]=true;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			dfs(j);
			dp[s][0]+=dp[j][0];
			dp[s][1]+=dp[j][1];
		}
	}
	if(val[s])
		++dp[s][val[s]-1];
}
void dfs2(int s=1)
{
	vis[s]=true;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			int k=(dp[j][0]>0);
			if((k>0 && dp[j][1]==0) || (k==0 && dp[j][1]>=0))
			{
				int z=((dp[1][0]-dp[j][0])>0);
				if((z>0 && dp[1][1]-dp[j][1]==0) || (z==0 && dp[1][1]-dp[j][1]>=0))
					++ans;
			}
			dfs2(j);
		}
	}
}	
int _runtimeTerror_()
{
	int i;
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>val[i];
	for(i=0;i<n-1;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	dfs(1);
	memf(vis);
	dfs2();
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