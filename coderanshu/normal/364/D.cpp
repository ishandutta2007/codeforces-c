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
	vector<ll> a(n);
	for(i=0;i<n;++i)
		cin>>a[i];
	shuffle(all(a),rng);
	ll count=12;
	ll ans=1;
	while(count--)
	{
		ll num=a[rng()%n];
		if(num==1)
			continue;
		ll kk=sqrt(num);
		vector<ll> divs;
		for(i=1;i<=kk;++i)
		{
			if(num%i==0)
			{
				divs.pb(i);
				if(i*i!=num)
					divs.pb(num/i);
			}
		}
		sort(all(divs));
		ll ff[sz(divs)]={0};
		map<ll,ll> index;
		for(i=0;i<sz(divs);++i)
			index[divs[i]]=i;
		for(i=0;i<n;++i)
			ff[index[__gcd(a[i],num)]]++;
		for(i=0;i<sz(divs);++i)
			for(ll j=i+1;j<sz(divs);++j)
				if(divs[j]%divs[i]==0)ff[i]+=ff[j];
		for(i=sz(divs)-1;i>=0;--i)
		{
			if(ff[i]*2>=n)
			{
				ans=max(ans,divs[i]);break;
			}
		}
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