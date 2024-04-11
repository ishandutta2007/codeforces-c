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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

int n,m,q,p;
bool chk[300][300];
ll tot[300][300];
char s[300][301];
void bfs(int x,int y,int k)
{
	queue<iii> q;
	stack<Pi> st;
	chk[x][y]=1;
	st.push(mp(x,y));
	tot[x][y]+=k;
	q.push(iii(x,y,k));
	while(!q.empty())
	{
		int xx,yy,kk;
		tie(xx,yy,kk)=q.front();
		q.pop();
		if(kk/2==0)continue;
		fup(i,0,3,1)
		{
			int nx=xx+dx[i],ny=yy+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m&&!chk[nx][ny]&&s[nx][ny]!='*')
			{
				tot[nx][ny]+=kk/2;
				chk[nx][ny]=1;
				st.push(mp(nx,ny));
				q.push(iii(nx,ny,kk/2));
			}
		}
	}
	while(!st.empty())
	{
		Pi p=st.top();
		st.pop();
		chk[p.X][p.Y]=0;
	}
}
int main() {
	scanf("%d%d%d%d",&n,&m,&q,&p);
	fup(i,0,n-1,1)scanf("%s",s[i]);
	fup(i,0,n-1,1)fup(j,0,m-1,1)if(s[i][j]>='A' && s[i][j]<='Z')bfs(i,j,q*(s[i][j]-'A'+1));
	int ans=0;
	fup(i,0,n-1,1)fup(j,0,m-1,1)if(tot[i][j]>p)ans++;
	printf("%d",ans);
}