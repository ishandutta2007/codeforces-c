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

bool chk[2004];
Vi v[2004];
int a[2004],c[2];
int main(){
	SYNC;
	int n;
	cin>>n;
	cout<<"? 1"<<endl;
	fup(i,1,n,1){
		cin>>a[i];
		if(i==1)continue;
		c[a[i]&1]++;
		if(a[i]==1){
			v[1].pb(i);
		}
	}
	if(c[0]<c[1]){
		fup(i,2,n,1){
			if(a[i]%2==0){
				cout<<"? "<<i<<endl;
				fup(j,1,n,1){
					int x;
					cin>>x;
					if(x==1)v[min(i,j)].pb(max(i,j));
				}
			}
		}
	}else{
		fup(i,2,n,1){
			if(a[i]%2==1){
				cout<<"? "<<i<<endl;
				fup(j,1,n,1){
					int x;
					cin>>x;
					if(x==1)v[min(i,j)].pb(max(i,j));
				}
			}
		}
	}
	cout<<"!"<<endl;
	fup(i,1,n,1){
		COMPRESS(v[i]);
		for(int j:v[i])cout<<i<<' '<<j<<endl;
	}
}