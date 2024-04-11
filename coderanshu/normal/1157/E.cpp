#pragma GCC optimize("Ofast")

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
int n;
map<int,int> m;
int bst(int num)
{
	auto it=m.lower_bound(num);
	if(it==m.end())
	{
		if(m.begin()->S==1)
		{
			int ans=m.begin()->F;
			m.erase(m.begin());
			return ans;
		}
		else
		{
			--(m.begin()->S);
			return m.begin()->F;
		}
	}
	else
	{
		if(it->S==1)
		{
			int ans=it->F;
			m.erase(it);return ans;
		}
		else
		{
			--m[it->F];
			return it->F;
		}
	}	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,num;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>num;m[num]++;
	}
	for(i=0;i<n;i++)
	{
		a[i]=(bst(n-a[i])+a[i])%n;
	}
	for(i=0;i<n;i++)cout<<a[i]<<" ";

	return 0;
}