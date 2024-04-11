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
#define popcount(x) __builtin_popcountll(x)
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

const int N=1004;
char a[N][N];
ll ans=0,n,m;
void dfs(ll i,ll j)
{
	if(a[i][j]=='.')
		return ;
	a[i][j]='.';
	if(i<n-1)dfs(i+1,j);
	if(i>0)dfs(i-1,j);
	if(j>0)dfs(i,j-1);
	if(j<m-1)dfs(i,j+1);
}
int _runtimeTerror_()
{
	cin>>n>>m;
	ll i,j;
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			cin>>a[i][j];
	ll r=0,c=0;
	for(i=0;i<n;++i)
	{
		vector<char> v;
		v.pb(a[i][0]);
		for(j=1;j<m;++j)
			if(a[i][j]!=v.back())
				v.pb(a[i][j]);
		if(sz(v)>=4)
		{
			cout<<-1;return 0;
		}
		if(sz(v)==1 && v[0]=='.')
			++r;
		if(sz(v)<=2)
			continue;

		if(v[0]=='.' && v[1]=='#' && v[2]=='.')
			continue;
		else {
			cout<<-1;return 0;
		}

	}
	for(i=0;i<m;++i)
	{
		vector<char> v;
		v.pb(a[0][i]);
		for(j=1;j<n;++j)
			if(a[j][i]!=v.back())
				v.pb(a[j][i]);
		if(sz(v)>=4)
		{
			cout<<-1;return 0;
		}
		if(sz(v)==1 && v[0]=='.')
			++c;
		if(sz(v)<=2)
			continue;
		if(v[0]=='.' && v[1]=='#' && v[2]=='.')
			continue;
		else {
			cout<<-1;return 0;
		}

	}
	r=(r>0);
	c=(c>0);
	if(r^c)
	{
		cout<<-1;
		return 0;
	}
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			if(a[i][j]=='#')
				dfs(i,j),++ans;
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