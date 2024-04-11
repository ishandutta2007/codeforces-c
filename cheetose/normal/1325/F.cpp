#include <bits/stdc++.h>
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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
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
typedef vector<ld> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int sq;
Vi v[100005];
bool chk[100005],cc[100005];
int dist[100005],parent[100005];
void dfs(int N,int p=-1,int d=0){
	cc[N]=1;
	parent[N]=p;
	dist[N]=d;
	for(int next:v[N]){
		if(next==p)continue;
		if(!cc[next])dfs(next,N,d+1);
		else if(dist[N]-dist[next]+1>=sq){
			puts("2");
			printf("%d\n%d ",dist[N]-dist[next]+1,N);
			while(N!=next){
				N=parent[N];
				printf("%d ",N);
			}
			exit(0);
		}
	}
	if(!chk[N]){
		for(int next:v[N])chk[next]=1;
	}
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	while(sq*sq<n)sq++;
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);
	puts("1");
	for(int i=1;sq>0 && i<=n;i++){
		if(!chk[i]){
			printf("%d ",i);
			sq--;
		}
	}
}