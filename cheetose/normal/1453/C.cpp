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
typedef vector<db> Vd;
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

int a[2000][2000];
VPi v[10];
void solve(){
	int n;
	scanf("%d",&n);
	fup(i,0,9,1)v[i].clear();
	fup(i,0,n-1,1)fup(j,0,n-1,1){
		scanf("%1d",&a[i][j]);
		v[a[i][j]].pb(mp(i,j));
	}
	fup(i,0,9,1){
		if(v[i].size()<=1){
			printf("0 ");
			continue;
		}
		int ans=0;
		int N=v[i].size();
		int t=0;
		fup(j,1,N-1,1){
			if(v[i][j].X<v[i][t].X)t=j;
		}
		fup(j,0,N-1,1){
			int tt=max(v[i][j].Y,n-v[i][j].Y-1);
			ans=max(ans,tt*(v[i][j].X-v[i][t].X));
		}
		t=0;
		fup(j,1,N-1,1){
			if(v[i][j].X>v[i][t].X)t=j;
		}
		fup(j,0,N-1,1){
			int tt=max(v[i][j].Y,n-v[i][j].Y-1);
			ans=max(ans,tt*(v[i][t].X-v[i][j].X));
		}

		t=0;
		fup(j,1,N-1,1){
			if(v[i][j].Y<v[i][t].Y)t=j;
		}
		fup(j,0,N-1,1){
			int tt=max(v[i][j].X,n-v[i][j].X-1);
			ans=max(ans,tt*(v[i][j].Y-v[i][t].Y));
		}

		t=0;
		fup(j,1,N-1,1){
			if(v[i][j].Y>v[i][t].Y)t=j;
		}
		fup(j,0,N-1,1){
			int tt=max(v[i][j].X,n-v[i][j].X-1);
			ans=max(ans,tt*(v[i][t].Y-v[i][j].Y));
		}
		printf("%d ",ans);
	}
	puts("");
}
int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}