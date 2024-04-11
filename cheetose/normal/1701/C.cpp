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

int cnt[200005],tmp[200005],rem[200005];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,1,n,1)cnt[i]=0;
	fup(i,1,m,1){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	int l=1,r=400000;
	while(l<=r){
		int k=l+r>>1;
		fup(i,1,n,1)tmp[i]=cnt[i],rem[i]=k;
		int tot=0;
		fup(i,1,n,1){
			int t=min(tmp[i],k);
			rem[i]-=t;
			tmp[i]-=t;
			tot+=tmp[i];
		}
		fup(i,1,n,1){
			int t=min(rem[i]>>1,tot);
			tot-=t;
		}
		if(!tot)r=k-1;
		else l=k+1;
	}
	printf("%d\n",l);
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}