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
#define INF 1987654321
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
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int n,m;
int x1[50],y1[50],x2[50],y2[50];
bool chk[111][111];

struct Edge {
	int to, r;
	Edge* ori;
	Edge* rev;
	Edge(int T, int R)
	{
		to = T, r = R;
	}
};
vector<Edge *> v[203];
void addedge(int f, int t, int r)
{
	Edge* ori = new Edge(t, r);
	Edge* rev = new Edge(f, 0);
	ori->rev = rev;
	rev->rev = ori;
	v[f].push_back(ori);
	v[t].push_back(rev);
}
const int S = 201, T = 202;
int level[203],work[203];
bool bfs() {
	MEM_1(level);
	level[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto& nn : v[x]) {
			int next = nn->to;
			if (level[next] == -1 && nn->r > 0) {
				level[next] = level[x] + 1;
				q.push(next);
			}
		}
	}
	return level[T] != -1;
}
int dfs(int N, int des, int flow) {
	if (N == des) return flow;

	for (int &i = work[N]; i<v[N].size(); i++) {
		int next = v[N][i]->to;
		if (level[next] == level[N] + 1 && v[N][i]->r > 0) {
			int df = dfs(next, des, min(v[N][i]->r, flow));
			if (df > 0) {
				v[N][i]->r -= df;
				v[N][i]->rev->r += df;
				return df;
			}
		}
	}
	return 0;
}
int main() {
	Vi xx,yy;
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1)
	{
		scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
		x2[i]++,y2[i]++;
		xx.pb(x1[i]);xx.pb(x2[i]);
		yy.pb(y1[i]);yy.pb(y2[i]);
	}
	sort(ALL(xx));xx.resize(unique(ALL(xx))-xx.begin());
	sort(ALL(yy));yy.resize(unique(ALL(yy))-yy.begin());
	int nx=xx.size(),ny=yy.size();
	fup(i,0,m-1,1)
	{
		x1[i]=lower_bound(ALL(xx),x1[i])-xx.begin();
		x2[i]=lower_bound(ALL(xx),x2[i])-xx.begin();
		y1[i]=lower_bound(ALL(yy),y1[i])-yy.begin();
		y2[i]=lower_bound(ALL(yy),y2[i])-yy.begin();
		fup(ii,x1[i],x2[i]-1,1)
			fup(jj,y1[i],y2[i]-1,1)chk[ii][jj]=1;
	}
	fup(i,0,nx-2,1)addedge(S,i,xx[i+1]-xx[i]);
	fup(i,0,ny-2,1)addedge(i+nx,T,yy[i+1]-yy[i]);
	fup(i,0,nx-2,1)
		fup(j, 0, ny-2, 1)
	{
		if(chk[i][j])addedge(i,j+nx,INF);
	}
	int ans = 0;
	while (bfs())
	{
		MEM0(work);
		while (1)
		{
			int f = dfs(S, T, INF);
			if (f == 0)break;
			ans += f;
		}
	}
	printf("%d\n", ans);
}