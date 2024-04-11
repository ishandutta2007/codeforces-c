#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[33;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
	cout<<x;
	if(suc==1) cout<<'\n';
	else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
	for(int i=0;i<v.size();i++)
	print(v[i],i==(int)(v.size())-1?suc:2);
}
void solve()
{
	int n,m;
	cin>>n>>m;
	vc<vi> a(n+1,vi(m+1));
	vi mx(m+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			mx[j]=max(mx[j],a[i][j]);
		}
	}
	vi id(m);
	iota(id.begin(),id.end(),1);
	sort(id.begin(),id.end(),[&](int x,int y){
		return mx[x]>mx[y];
	});
	vc<vi> b(n+1,vi(min(n,m)+1));
	for(int j=1;j<=min(n,m);j++)
	{
		for(int i=1;i<=n;i++)
			b[i][j]=a[i][id[j-1]];
	}
	a=b;
	m=min(n,m);
	vc<vi> dp(m+1,vi(1<<n,-1));
	dp[0][0]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<n;j++)
		{
			vi cur=dp[i-1];
			for(int S=0;S<(1<<n);S++)
			{
				for(int k=0;k<n;k++)
				{
					if(cur[S]==-1) continue;
					int pos=(k+j)%n;
					if(S>>pos&1^1)
						cur[S|(1<<pos)]=max(cur[S|(1<<pos)],cur[S]+a[k+1][i]);
				}
			}
			for(int S=0;S<(1<<n);S++)
				dp[i][S]=max(dp[i][S],cur[S]);
		}
		//dbg(i,dp[i]);
	}
	print(dp[m][(1<<n)-1]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--) solve();
}