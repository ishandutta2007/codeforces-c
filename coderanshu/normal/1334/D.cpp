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


int _runtimeTerror_()
{
	ll n,l,r,i;
	cin>>n>>l>>r;
	if(l==n*(n-1)+1)
	{
		cout<<1<<endl;return 0;
	}
	vector<ll> v;
	ll j;
	ll sum=0;i=0;
	while(sum<l)
	{
		++i;
		sum+=2*(n-i);
	}
	ll k=l-(sum-2*(n-i));
	for(j=k;j<=2*(n-i);++j)
	{
		if(j&1)
			v.pb(i);
		else
		{
			ll z=j/2;;
			v.pb(i+z);
		}
	}
	//for(auto j:v)
	//	cout<<j<<endl;
	for(j=i+1;j<=n-1 && sum<=l+100000;++j)
	{
		for(ll k=1;k<=2*(n-j);++k)
		{
			if(k&1)
				v.pb(j);
			else v.pb(k/2+j);
		}
		sum+=2*(n-j);
	}
	if(j==n)
		v.pb(1);
	for(i=0;i<r-l+1;++i)
		cout<<v[i]<<" ";
	cout<<endl;
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