#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
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
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[] = { -1,-2,1,-2,2,-1,2,1 }, ddy[] = { -2,-1,-2,1,-1,2,1,2 };

int a[50005];
int d[4];
void solve(){
	MEM0(d);
	int n,x;
	scanf("%d",&n);
	fup(i,0,n-1,1)scanf("%d",a+i);
	scanf("%d",&x);
	fup(i,0,n-1,1)a[i]-=x;
	if(n==1){
		puts("1");
		return;
	}
	if(n==2){
		if(a[0]+a[1]>=0)puts("2");
		else puts("1");
		return;
	}
	d[1]=d[2]=1;
	if(a[0]+a[1]>=0)d[3]=2;
	else d[3]=-INF;
	fup(i,2,n-1,1){
		int t[4];
		t[0]=max(d[0],d[2]);
		t[1]=max(d[0],d[2])+1;
		t[2]=max(d[1],d[3]);
		t[3]=d[3];
		if(a[i]+a[i-1]>=0){
			t[3]=max(t[3],d[1]+1);
			if(a[i]+a[i-1]+a[i-2]>=0){
				t[3]=max(t[3],d[3]+1);
			}
		}
		memcpy(d,t,sizeof(d));
	}
	printf("%d\n",*max_element(d,d+4));
}
int main(){
	int tc;
	scanf("%d",&tc);
	while(tc--)solve();
}