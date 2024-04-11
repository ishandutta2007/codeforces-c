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
#define pi 3.1415926536

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
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll i,m;
	string s,t;
	cin>>s>>t;
	ll k=s.length();
	vector<ll> v1,v2;
	m=0;
	for(i=0;i<k;i++)
	{
		if(s[i]==t[m] && m<t.length())
		{
			v1.pb(i);m++;
		}
	}
	m=t.length()-1;
	for(i=k-1;i>=0;i--)
	{
		if(s[i]==t[m]&& m>=0)
		{
			v2.pb(i);m--;
		}
	}
	m=v1.size();
	ll ans=0;
	for(i=0;i<m-1;i++)
	{
		ans=max(ans,v2[m-i-2]-v1[i]-1);
	}
	ans=max(k-v1[m-1]-1,ans);
	ans=max(ans,v2[m-1]);
	cout<<ans;
	return 0;
}