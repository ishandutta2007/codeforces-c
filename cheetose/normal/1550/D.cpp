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

ll fac[200001],inv[200001];
ll nCr(int n,int r){
	if(n<0 || r<0 || r>n)return 0;
	ll c=fac[n];
	c=c*inv[r]%MOD;
	c=c*inv[n-r]%MOD;
	return c;
}
Pi p[200005];
void solve(){
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	fup(i,1,n,1){
		p[i]=mp(l-i,r-i);
	}
	ll ans=0;
	int t=min(-p[1].X,p[n].Y);
	if(t>=1)ans=nCr(n,n/2)*(t-1)%MOD;
	if(n&1)ans=ans*2%MOD;
	if(-p[1].X<p[n].Y){
		for(int i=1,j=n;i<=n;i++){
			int c=t+i-1;
			while(j>0 && p[j].Y<c)j--;
			if(j==0)break;
			int tot=j-i+1;
			if(p[i].X!=0){
				ans=(ans+nCr(tot,n/2-(i-1)))%MOD;
				if(n&1)ans=(ans+nCr(tot,(n+1)/2-(i-1)))%MOD;
			}
		}
	}else{
		for(int i=1,j=n;j>=1;j--){
			int c=t+n-j;
			while(i<=n && -p[i].X<c)i++;
			if(i>n)break;
			int tot=j-i+1;
			if(p[j].Y!=0){
				ans=(ans+nCr(tot,n/2-(n-j)))%MOD;
				if(n&1)ans=(ans+nCr(tot,(n+1)/2-(n-j)))%MOD;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	fac[0]=inv[0]=1;
	fup(i,1,200000,1)fac[i]=fac[i-1]*i%MOD;
	inv[200000]=POW(fac[200000],MOD-2);
	fdn(i,199999,1,1)inv[i]=inv[i+1]*(i+1)%MOD;
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}