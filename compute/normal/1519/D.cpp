#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
	vc<ll> a(n+1),b(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=a[i]*b[i];
	vc<ll> pre(n+1),suf(n+2);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i]*b[i];
	for(int i=n;i>=1;i--) suf[i]=suf[i+1]+a[i]*b[i];
	for(int i=1;i<=n;i++)
	{
		{
			int l=i,r=i;
			ll cur=0;
			while(l>0&&r<=n)
			{
				cur+=a[l]*b[r];
				if(l!=r) cur+=b[l]*a[r];
				ans=max(ans,pre[l-1]+suf[r+1]+cur);
				l--,r++;
			}
		}
		{
			int l=i,r=i+1;
			ll cur=0;
			while(l>0&&r<=n)
			{
				cur+=a[l]*b[r]+a[r]*b[l];
				ans=max(ans,pre[l-1]+suf[r+1]+cur);
				l--,r++;
			}
		}
	}
	print(ans);
}