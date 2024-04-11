#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000003;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

ll a[100000];
Vi vv[60];
int cnt[60];
int ans=INF;
int n;
void bfs(int t)
{
	if(cnt[t]!=2)return;
	int S=vv[t][0],E=vv[t][1];
	if(S>E)swap(S,E);
	vector<Vi> v(n);
	Vi dist(n,-1);
	fup(i,0,59,1)
	{
		if(cnt[i]==2)
		{
			int s=vv[i][0],e=vv[i][1];
			if(s>e)swap(s,e);
			if(s==S && e==E)continue;
			v[s].pb(e);
			v[e].pb(s);
		}
	}
	queue<int> q;
	q.push(S);
	dist[S]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int y:v[x])
		{
			if(dist[y]==-1)
			{
				dist[y]=dist[x]+1;
				q.push(y);
			}
		}
	}
	if(dist[E]!=-1) ans=min(ans,dist[E]+1);
}
int main(){
	scanf("%d",&n);
	fup(i,0,n-1,1)
	{
		scanf("%lld",a+i);
		fup(j,0,59,1)
			if(a[i]&(1LL<<j))
			{
				cnt[j]++;
				vv[j].pb(i);
			}
	}
	int mx=0;
	fup(i,0,59,1)mx=max(mx,cnt[i]);
	if(mx<=1)return !printf("-1");
	if(mx>=3)return !printf("3");
	fup(i,0,59,1)bfs(i);
	if(ans==INF)return !printf("-1");
	printf("%d",ans);
}