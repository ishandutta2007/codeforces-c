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
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 998244353;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={-1,-2,1,-2,2,-1,2,1},ddy[]={-2,-1,-2,1,-1,2,1,2};

int a[200000],b[200000],c[200003];
struct FenwickTree{
	int n;
	Vi tree;
	
	FenwickTree(int N){
		n=N;
		tree.resize(N+2);
	}
	
	void upd(int i)
	{
		while (i <= n+1)
		{
			tree[i]++;
			i += (i&-i);
		}
	}
	int sum(int i)
	{
		int c = 0;
		while (i > 0)
		{
			c += tree[i];
			i -= (i&-i);
		}
		return c;
	}
};
int d[2][200005];
int chk[200002];
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int N=n+m+k;
	FenwickTree A(N);
	fup(i,0,n-1,1)scanf("%d",a+i),A.upd(a[i]);
	fup(i,0,m-1,1)scanf("%d",b+i),chk[b[i]]=1;
	fup(i,0,k-1,1)scanf("%d",c+i),chk[c[i]]=2;
	int w=0;
	fdn(i,N,1,1)
	{
		if(chk[i]==0)
		{
			d[0][i]=d[0][i+1];
			d[1][i]=d[1][i+1];
		}
		else if(chk[i]==1)
		{
			w++;
			d[1][i]=w;
			d[0][i]=min(d[0][i+1],d[1][i+1]);
		}
		else
		{
			d[1][i]=w;
			d[0][i]=min(d[0][i+1]+1,d[1][i+1]+1);
		}
	}
	c[k]=INF;
	int ans=INF;
	fup(i,0,N,1)
	{
		int tmp=i+A.sum(N)-2*A.sum(i);
		ans=min(ans,tmp+min(d[0][i+1],d[1][i+1]));
	}
	printf("%d",ans);
}