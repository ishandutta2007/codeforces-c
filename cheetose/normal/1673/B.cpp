#include <bits/stdc++.h>
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
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define COMPRESS(a) sort(ALL(a));a.resize(unique(ALL(a))-a.begin())
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
typedef vector<ld> Vd;
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

char s[200005];
int a[26][200005];
bool chk[26];
Vi v[26];
void solve(){
	MEM0(chk);
	fup(i,0,25,1)v[i].clear();
	scanf("%s",s+1);
	int n=strlen(s+1);
	fup(i,1,n,1){
		chk[s[i]-'a']=1;
		fup(j,0,25,1)a[j][i]=a[j][i-1];
		a[s[i]-'a'][i]++;
		v[s[i]-'a'].pb(i);
	}
	fup(i,0,25,1){
		int N=v[i].size();
		fup(j,1,N-1,1){
			int x=v[i][j-1],y=v[i][j];
			fup(c,0,25,1){
				if(!chk[c])continue;
				if(a[c][y]==a[c][x]){
					puts("NO");
					return;
				}
			}
		}
	}
	puts("YES");
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}