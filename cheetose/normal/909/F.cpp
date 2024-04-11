#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a))
#define MEM_1(a) memset((a),-1,sizeof(a))
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
typedef vector<db> Vd;
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
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

bool chk[100005];
int ans[100005];
int main(){
	int n;
	fup(i,0,16,1)chk[1<<i]=1;
	scanf("%d",&n);
	if(n&1){
		puts("NO");
	}else{
		puts("YES");
		priority_queue<int> q;
		fup(i,1,n,1)q.push(i);
		fup(i,1,n/2,1){
			while(!q.empty() && ans[q.top()])q.pop();
			int x=q.top();
			q.pop();
			int t=32-__builtin_clz(x);
			int y=((1<<t)-1)^x;
			ans[x]=y; ans[y]=x;
		}
		fup(i,1,n,1)printf("%d ",ans[i]);
		puts("");
	}
	if(n<=5 || chk[n]){
		puts("NO");
	}else{
		puts("YES");
		if(n==6){
			puts("3 6 2 5 1 4");
		}else{
			printf("3 6 1 5 4 7 2 ");
			fup(i,8,n,1){
				if(chk[i])printf("%d ",min(2*i-1,n));
				else printf("%d ",i-1);
			}
		}
	}
}