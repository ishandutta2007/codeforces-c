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
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };

int a[1000000],cnt,tot;
int tree[2097152];
int b[1000000];
bool chk[1000000];
void upd(int node, int S, int E, int k, int dif)
{
	tree[node] += dif;
	if (S == E)return;
	if (k <= (S + E) / 2)upd(node * 2, S, (S + E) / 2, k, dif);
	else upd(node * 2 + 1, (S + E) / 2 + 1, E, k, dif);
}

int findK(int node, int S, int E, int k)
{
	if (S == E)return S;
	if (k <= tree[node * 2])return findK(node * 2, S, (S + E) / 2, k);
	return findK(node * 2 + 1, (S + E) / 2 + 1, E, k - tree[node * 2]);
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	fup(i,0,m-1,1)scanf("%d",a+i);
	fup(i,0,n-1,1)
	{
		int x;
		scanf("%d",&x);
		if(x==-1)
		{
			int i=0;
			while(i<m && a[i]<=cnt)
			{
				int t=findK(1,0,n-1,a[i]-i);
				chk[t]=1;
				upd(1,0,n-1,t,-1);
				i++;
			}
			cnt-=i;
		}
		else
		{
			upd(1,0,n-1,tot,1);
			b[tot++]=x;
			cnt++;
		}
	}
	bool ok=0;
	fup(i,0,tot-1,1)
	{
		if(!chk[i])
		{
			ok=1;
			printf("%d",b[i]);
		}
	}
	if(!ok)return !printf("Poor stack!");
}