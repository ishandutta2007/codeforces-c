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
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

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
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t;
	cin>>t;
	while(t--)
	{
		int n,i,num,z=0;
		cin>>n;
		int sum=0;
		for(i=0;i<n;++i)
		{
			cin>>num;
			if(num==0)z++;
			else sum+=num;
		}
		if(z==0 && sum!=0)cout<<0;
		else
		{
			if(z==0)cout<<1;
			else
			{
				if(sum>=0)cout<<z;
				else
				{
					sum+=z;
					if(sum==0)cout<<z+1;
					else cout<<z;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}