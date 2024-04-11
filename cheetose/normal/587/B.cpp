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
#define INF 987654321987654231
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
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int a[1000000],cnt[1000000],cnt2[1000001];
int n,k;
ll l;
Vi vv;
int main() {
	scanf("%d%lld%d",&n,&l,&k);
	fup(i,0,n-1,1)
	{
		scanf("%d",a+i);
		vv.pb(a[i]);
	}
	sort(ALL(vv));
	vv.resize(unique(ALL(vv))-vv.begin());
	fup(i,0,n-1,1)
	{
		a[i]=lower_bound(ALL(vv),a[i])-vv.begin();
		cnt[a[i]]++;
	}
	fup(i,0,(l%n)-1,1)cnt2[a[i]]++;
	int N=vv.size();
	vector<Vll> d(N,Vll(k+1));
	fup(i,0,N-1,1)d[i][1]=cnt[i];
	fup(j,2,k,1)
	{
		ll t=0;
		fup(i,0,N-1,1)
		{
			t=(t+d[i][j-1])%MOD;
			d[i][j]=(t*cnt[i])%MOD;
		}
	}
	ll ans=0,p=l/n;
	fup(j,1,k,1)
	{
		ll tt=0;
		fup(i,0,N-1,1)tt=(tt+d[i][j])%MOD;
		tt=(tt*max(0LL,(p-j+1)%MOD))%MOD;
		ans=(ans+tt)%MOD;
	}
	fup(j,1,k,1)
		fup(i,1,N-1,1)d[i][j]=(d[i][j]+d[i-1][j])%MOD;
	ans=(ans+l%n)%MOD;
	fup(j,1,k-1,1)
	{
		if(j>p)break;
		ll tt=0;
		fup(i,0,N-1,1)tt=(tt+d[i][j]*cnt2[i])%MOD;
		ans=(ans+tt)%MOD;
	}
	printf("%lld",ans);
}