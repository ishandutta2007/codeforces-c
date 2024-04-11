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
	long n,m,i,d,num,check;
	long ans=0;
	vector<long> v;
	cin>>n>>m>>d;
	rep(i,0,n*m)
	{
		cin>>num;
		if(i==0)
			check=num%d;
		if(num%d!=check)
			ans=-1;
		v.pb(num);
	}
	if(ans==-1)
	{
		cout<<-1;
		return 0;
	}
	sort(all(v));
	m=v[(n*m)/2];
	for(auto j:v)
		ans+=abs(j-m);
	cout<<ans/d;

	return 0;
}