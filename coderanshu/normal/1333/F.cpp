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
#define INF 2e18
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

int _runtimeTerror_()
{
	ll n,i;
	cin>>n;
	ll val[n+1]={0};
	for(ll i=1;i<=n/2;++i)
	{
		for(ll j=2*i;j<=n;j+=i)
		{
			val[j]=i;
		}
	}
	ll fac[n+1]={0};
	for(i=1;i<=n;++i)
		fac[val[i]]++;
	ll curr=n;
	vector<ll> ans;
	while(curr>=1)
	{
		while(fac[curr]==0)--curr;
		if(curr==0)break;
		for(ll k=0;k<fac[curr];++k)
			ans.pb(curr);
		--curr;
	}
	for(ll k=0;k<n-1-sz(ans);++k)
		ans.pb(1);
	reverse(all(ans));
	for(auto j:ans)
		cout<<j<<" ";
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