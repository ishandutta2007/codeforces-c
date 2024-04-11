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
#define llevel 20
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
const int N=500002;
vector<ll> v[N];
ll from[N],to[N],curr=0,a[N],p[N];
bitset<N> vis;
void dfs(ll s=1)
{
	vis[s]=1;
	from[s]=curr;
	++curr;
	for(auto j:v[s])
	{
		if(!vis[j])
		{
			p[j]=s;
			dfs(j);
		}
	}
	to[s]=curr-1;
}
struct node
{
	int bit;
}fake={1};
// base value is assigned to fake node
node tree[4*N];
int lazy[4*N];
inline node combine(node a,node b)
{
	node ret;
	ret.bit=a.bit&b.bit;
	return ret;
}
inline node make_node(ll val)
{
	node ret;
	ret.bit=val;
	return ret;
}
inline void pushdown(ll v,ll st,ll en)
{
	tree[v].bit=lazy[v];
	if(st!=en)
	{
		lazy[v<<1]=lazy[v];
		lazy[v<<1 | 1]=lazy[v];
	}
	lazy[v]=-1;
	return ;
}
void buildTree(ll v,ll st,ll en)
{
	if(st==en)
	{
		tree[v]=make_node(a[st]);
		return ;
	}
	ll mid=(st+en)>>1;
	buildTree(v<<1,st,mid);
	buildTree(v<<1 | 1,mid+1,en);
	tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
}
void update(ll v,ll st,ll en,ll in,ll val)
{
	ll mid=(st+en)>>1;
	if(st==en)
	{
		tree[v]=make_node(val);
		a[st]=val;
		return ;
	}
	if(in<=mid)
		update(v<<1,st,mid,in,val);
	else
		update(v<<1 | 1,mid+1,en,in,val);
	tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
}
void rupdate(ll v,ll st,ll en,ll l,ll r,ll val)
{
	if(lazy[v]!=-1)
	{
		pushdown(v,st,en);
	}
	if(en<l || st>r)return ;
	if(st>=l && en<=r)
	{
		lazy[v]=val;
		pushdown(v,st,en);
		return ;
	}
	ll mid=(st+en)>>1;
	rupdate(v<<1,st,mid,l,r,val);
	rupdate(v<<1 | 1,mid+1,en,l,r,val);
	tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
}
node query(ll v,ll st,ll en,ll l,ll r)
{
	if(en<l || st>r)
		return fake;
	if(lazy[v]!=-1)
	{
		pushdown(v,st,en);
	}
	if(st>=l && en<=r)
		return tree[v];
	ll mid=(st+en)>>1;
	return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
}
int _runtimeTerror_()
{
	ll n,m,i;
	cin>>n;
	mem1(lazy);
	for(i=0;i<n-1;++i)
	{
		ll x,y;
		cin>>x>>y;
		v[x].pb(y);v[y].pb(x);
	}
	dfs();
	cin>>m;
	while(m--)
	{
		ll tt,vv;
		cin>>tt>>vv;
		if(tt==1)
		{
			ll kk=query(1,0,n-1,from[vv],to[vv]).bit;
			if(kk==0 && vv !=1)
				rupdate(1,0,n-1,from[p[vv]],from[p[vv]],0);
			rupdate(1,0,n-1,from[vv],to[vv],1);
		}
		else if(tt==2)
			rupdate(1,0,n-1,from[vv],from[vv],0);
		else
		{
			cout<<query(1,0,n-1,from[vv],to[vv]).bit<<endl;
		}
	}
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
	return 0;
}