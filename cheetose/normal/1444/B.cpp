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
const int MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

ll a[300000];
ll fac[300005],inv[300005];
ll nCr(int n, int r)
{
	if(r>n)return 0;
	ll c = fac[n];
	c = (c*inv[r]) % MOD;
	c = (c*inv[n - r]) % MOD;
	return c;
}
int main(){
	int n;
	scanf("%d",&n);
	fup(i,0,2*n-1,1)scanf("%lld",a+i);
	sort(a,a+2*n);
	ll t1=0,t2=0;
	fup(i,0,n-1,1)t1=(t1+a[i])%MOD;
	fup(i,n,2*n-1,1)t2=(t2+a[i])%MOD;
	fac[0] = inv[0] = 1;
	fup(i, 1, 300004, 1)
		fac[i] = (fac[i - 1] * i) % MOD;
	inv[300004] = POW(fac[300004], MOD - 2);
	fdn(i, 300003, 1, 1)
		inv[i] = (inv[i + 1] * (i+1)) % MOD;
	ll C=2*nCr(2*n-1,n-1)%MOD;
	t2-=t1;
	if(t2<0)t2+=MOD;
	t2=t2*C%MOD;
	printf("%lld\n",t2);
}