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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll ans=INF;
int n,k,l;
char s[1000005];
int a[1000005];
Pll d[1000005];
void f(ll mid){
	fill(d+1,d+n+1,mp(INF,INF));
	fup(i,0,n-1,1){
		d[i+1]=min(d[i+1],Pll(d[i].X+a[i+1],d[i].Y));
		d[min(n,i+l)]=min(d[min(n,i+l)],Pll(d[i].X+mid,d[i].Y+1));
	}
}
ll go(){
	ll l=0,r=n;
	while(l<=r){
		ll mid=l+r>>1;
		f(mid);
		if(d[n].Y<=k){
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	f(l);
	return d[n].X-l*k;
}
int main() {
	scanf("%d%d%d",&n,&k,&l);
	scanf("%s",s+1);
	fup(i,1,n,1){
		if(s[i]>='a' && s[i]<='z')a[i]=1;
	}
	ans=min(ans,go());
	fup(i,1,n,1)a[i]=1-a[i];
	ans=min(ans,go());
	printf("%lld\n",ans);
}