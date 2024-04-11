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
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
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
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m,c;
char a[2003],b[2003];
ll d[2001][2001][2];
ll go(int N,int M,int C, char s[])
{
	if(N==n)return M==0;
	ll &ret=d[N][M][C];
	if(ret!=-1)return ret;
	ret=0;
	int x=s[N]-'0';
	if(C==0)
	{
		if(N&1)
		{
			if(x==c)ret=(ret+go(N+1,(10*M+c)%m,0,s))%MOD;
			if(x<c)return ret=0;
			if(x>c)ret=(ret+go(N+1,(10*M+c)%m,1,s))%MOD;
		}
		else
		{
			fup(i,0,9,1)
			{
				if(i==0 && N==0)continue;
				if(i==c)continue;
				if(i>x)break;
				if(i<x)ret=(ret+go(N+1,(10*M+i)%m,1,s))%MOD;
				if(i==x)ret=(ret+go(N+1,(10*M+i)%m,0,s))%MOD;
			}
		}
	}
	else
	{
		if(N&1)ret=(ret+go(N+1,(10*M+c)%m,1,s))%MOD;
		else 
		{
			fup(i,0,9,1)
			{
				if(i==c)continue;
				ret=(ret+go(N+1,(10*M+i)%m,1,s))%MOD;
			}
		}
	}
	return ret;
}
int main() {
	scanf("%d%d%s%s",&m,&c,a,b);
	n=strlen(a);
	fdn(i,n-1,0,1)
	{
		a[i]--;
		if(a[i]<'0')a[i]='9';
		else break;
	}
	MEM_1(d);
	ll ans=go(0,0,0,b);
	if(a[0]!='0')
	{
		MEM_1(d);
		ans=(ans+MOD-go(0,0,0,a))%MOD;
	}
	printf("%lld",ans);
}