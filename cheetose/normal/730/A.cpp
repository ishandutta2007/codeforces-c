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
#define INF (1e18+5)
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

int cnt[101];
int ans[10000][100],cc;
priority_queue<Pi> q;
int main() {
	int n;
	scanf("%d",&n);
	if(n==2)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)
			return !printf("%d\n0",x);
		else
		{
			puts("0");
			puts("100");
			fup(i,1,100,1)puts("11");
			return 0;
		}
	}
	else
	{
		fup(i,0,n-1,1)
		{
			int x;
			scanf("%d",&x);
			cnt[x]++;
			q.push(mp(x,i));
		}
		while(1)
		{
			if(cnt[q.top().X]==n)
			{
				printf("%d\n",q.top().X);
				printf("%d\n",cc);
				fup(i,0,cc-1,1)
				{
					fup(j,0,n-1,1)printf("%d",ans[i][j]);
					puts("");
				}
				return 0;
			}
			if(cnt[q.top().X]==3 && cnt[q.top().X-1]==n-3)
			{
				printf("%d\n",q.top().X-1);
				fup(i,0,2,1)
				{
					ans[cc][q.top().Y]=1;
					q.pop();
				}
				cc++;
				printf("%d\n",cc);
				fup(i,0,cc-1,1)
				{
					fup(j,0,n-1,1)printf("%d",ans[i][j]);
					puts("");
				}
				return 0;
			}
			Pi p1=q.top();q.pop();
			Pi p2=q.top();q.pop();
			cnt[p1.X]--,cnt[p2.X]--;
			ans[cc][p1.Y]=ans[cc][p2.Y]=1;
			cc++;
			if(p1.X>0)p1.X--;
			if(p2.X>0)p2.X--;
			cnt[p1.X]++,cnt[p2.X]++;
			q.push(p1);
			q.push(p2);
		}
	}
}