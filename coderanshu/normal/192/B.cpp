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
ll a[1005],n;
bool check(ll m)
{
	ll pos=0,i;
	for(i=1;i<n;i++)
	{
		if(a[i]-m>0 && i-pos<3)pos=i;
		else if(i-pos>2)return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll k,be,en;
	cin>>n;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	k=min(a[0],a[n-1]);
	be=0;en=k-1;
	while(be<=en)
	{
		ll mid=(be+en)>>1;
		if(check(mid))
			be=mid+1;
		else
			en=mid-1;
	}
	cout<<be;

	return 0;
}