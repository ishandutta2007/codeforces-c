#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
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
#define INF 1987654321
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
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
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
int MOD = 1000000;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

Pi p[100000];
int cnt[100001];
set<int> leng;
set<Pi> range;
int main() {
	int n;
	scanf("%d", &n);
	fup(i, 0, n - 1, 1)
	{
		scanf("%d", &p[i].X);
		p[i].Y = i;
	}
	cnt[n] = 1;
	leng.insert(n);
	range.insert(Pi(n-1, 0));
	sort(p, p + n);
	int MAX = 1, ans = p[n - 1].X + 1;
	fdn(i, n - 1, 1, 1)
	{
		int t = p[i].Y;
		auto it = range.lower_bound(mp(t, -1));
		int L, R;
		tie(R, L) = *it;
		range.erase(it);
		cnt[R - L + 1]--;
		if (cnt[R - L + 1] == 0)leng.erase(leng.find(R - L + 1));
		if (L != t)
		{
			int l = L, r = t - 1;
			range.insert(mp(r,l));
			cnt[r - l + 1]++;
			if (cnt[r - l + 1] == 1)leng.insert(r - l + 1);
		}
		if (R != t)
		{
			int l = t+1, r = R;
			range.insert(mp(r, l));
			cnt[r - l + 1]++;
			if (cnt[r - l + 1] == 1)leng.insert(r - l + 1);
		}
		if (leng.size() == 1)
		{
			int t = *leng.begin();
			if (cnt[t] > MAX)
			{
				ans = p[i - 1].X + 1;
				MAX = cnt[t];
			}
			else if (cnt[t] == MAX) ans = p[i - 1].X + 1;
		}
	}
	printf("%d", ans);
}