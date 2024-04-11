#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll d[606];
ll a[606][606];
bool chk[606];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,n-1,1)fup(j,0,n-1,1)a[i][j]=INF;
	fup(i,0,m-1,1){
		int x,y;
		ll z;
		scanf("%d%d%lld",&x,&y,&z);
		a[x][y]=z;
	}
	fup(i,0,n-1,1){
		fup(j,0,n-1,1){
			d[j]=a[i][j];
			chk[j]=0;
		}
		while(1){
			int t=-1;
			fup(j,0,n-1,1){
				if(chk[j])continue;
				if(t==-1 || d[t]>d[j])t=j;
			}
			if(t==-1)break;
			chk[t]=1;
			d[(t+1)%n]=min(d[(t+1)%n],d[t]+1);
			fup(j,0,n-1,1){
				if(a[t][j]==INF)continue;
				d[(j+d[t])%n]=min(d[(j+d[t])%n],d[t]+a[t][j]);
			}
		}
		fup(j,0,n-1,1)printf("%lld ",i==j?0:d[j]);
		puts("");
	}
}