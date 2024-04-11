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
ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int b[2][100000];
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		if(m==1)
		{
			puts("YES");
			return !printf("1");
		}
		if(m<=3)return !printf("NO");
	}
	if(n==2 && m<=3)return !printf("NO");
	if(n==3)
	{
		if(m<=2)return !printf("NO");
		if(m==3)
		{
			puts("YES");
			return !printf("1 6 7\n8 4 3\n2 9 5");
		}
	}
	puts("YES");
	if(m==4)
	{
		int a[2][4]={{2,4,1,3},{3,1,4,2}};
		fup(i,1,n,1)
		{
			int t=i&1;
			fup(j,0,3,1)printf("%d ",4*(i-1)+a[t][j]);
			puts("");
		}
		return 0;
	}
	if(m>4)
	{
		fup(i,0,m-1,2)
		{
			b[1][i]=i/2+1;
			if(i<m-1)b[1][i+1]=b[1][i]+(m+1)/2;
		}
		fup(i,0,m-1,1)b[0][i]=b[1][(i+m-1)%m];
		fup(i,1,n,1)
		{
			int t=i&1;
			fup(j,0,m-1,1)printf("%d ",m*(i-1)+b[t][j]);
			puts("");
		}
		return 0;
	}
	if(n==4)
	{
		int a[2][4]={{2,4,1,3},{3,1,4,2}};
		fup(i,0,n-1,1)
		{
			fup(j,1,m,1)printf("%d ",a[j&1][i]*m+j-m);
			puts("");
		}
		return 0;
	}
	if(n>4)
	{
		fup(i,0,n-1,2)
		{
			b[1][i]=i/2+1;
			if(i<n-1)b[1][i+1]=b[1][i]+(n+1)/2;
		}
		fup(i,0,n-1,1)b[0][i]=b[1][(i+n-1)%n];
		fup(i,0,n-1,1)
		{
			fup(j,1,m,1)printf("%d ",b[j&1][i]*m+j-m);
			puts("");
		}
		return 0;
	}
}