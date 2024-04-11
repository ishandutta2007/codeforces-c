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
#define INF 2000000001
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

iii p[250000];
int a[502][502];
int n,m,k,q;
bool ok(int kk)
{
	MEM0(a);
	int x,y;
	fup(i,0,kk,1)
	{
		tie(ignore,x,y)=p[i];
		a[x][y]=1;
	}
	fup(i,1,n,1)
		fup(j,1,m,1)
		a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	fup(i,k,n,1)
		fup(j,k,m,1)
	{
		if(a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k]==k*k)return 1;
	}
	return 0;
}
int main() {
	scanf("%d%d%d%d",&n,&m,&k,&q);
	fup(i,0,q-1,1)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		p[i]=iii(z,x,y);
	}
	sort(p,p+q);
	int l=0,r=q-1;
	while(l<=r)
	{
		int kk=(l+r)>>1;
		if(ok(kk))r=kk-1;
		else l=kk+1;
	}
	if(l==q)return !printf("-1");
	printf("%d",get<0>(p[l]));
	
}