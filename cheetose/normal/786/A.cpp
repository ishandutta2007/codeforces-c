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
#define INF 987654321
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

Vi v[2];
int res[2][7000],cnt[2][7000];
int main() {
	int k[2];
	res[0][0]=res[1][0]=1;
	int n;
	scanf("%d",&n);
	fup(i,0,1,1)
	{
		scanf("%d",k+i);
		fup(ii,0,k[i]-1,1)
		{
			int x;
			scanf("%d",&x);
			v[i].pb(x);
		}
	}
	fup(i,0,1,1)
		fup(j,1,n-1,1)cnt[i][j]=k[i];
	queue<Pi> q;
	q.push(mp(0,1));
	q.push(mp(n,1));
	while(!q.empty())
	{
		Pi p=q.front();q.pop();
		if(p.X<n)
		{
			fup(i,0,k[1]-1,1)
			{
				int next=(p.X-v[1][i]+n)%n;
				if(res[1][next])continue;
				if(p.Y==1)
				{
					res[1][next]=2;
					q.push(mp(n+next,2));
				}
				else
				{
					cnt[1][next]--;
					if(cnt[1][next]==0)
					{
						res[1][next]=1;
						q.push(mp(n+next,1));
					}
				}
			}
		}
		else
		{
			fup(i,0,k[0]-1,1)
			{
				int next=(p.X-v[0][i])%n;
				if(res[0][next])continue;
				if(p.Y==1)
				{
					res[0][next]=2;
					q.push(mp(next,2));
				}
				else
				{
					cnt[0][next]--;
					if(cnt[0][next]==0)
					{
						res[0][next]=1;
						q.push(mp(next,1));
					}
				}
			}
		}
	}
	fup(i,0,1,1)
	{
		fup(j,1,n-1,1)
		{
			if(res[i][j]==0)printf("Loop ");
			if(res[i][j]==1)printf("Lose ");
			if(res[i][j]==2)printf("Win ");
		}
		puts("");
	}
}