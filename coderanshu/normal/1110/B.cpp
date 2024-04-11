#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e9
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m,k,i;
	cin>>n>>m>>k;
	vector<ll> a(n);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<ll> vec;
	for(i=1;i<n;i++)
	{
		vec.pb(a[i]-a[i-1]-1);
	}
	sort(all(vec),greater<ll>());
	ll sz=vec.size();
	ll j=min(sz,k-1);
	ll ans=a[n-1]-a[0]+1;
	for(i=0;i<j;i++)
		ans-=vec[i];
	cout<<ans;
	return 0;
}