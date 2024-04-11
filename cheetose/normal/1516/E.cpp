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

Vi berlekamp_massey(Vi x){
	Vi ls, cur;
	int lf, ld;
	for(int i=0; i<x.size(); i++){
		ll t = 0;
		for(int j=0; j<cur.size(); j++){
			t = (t + 1ll * x[i-j-1] * cur[j]) % MOD;
		}
		if((t - x[i]) % MOD == 0) continue;
		if(cur.empty()){
			cur.resize(i+1);
			lf = i;
			ld = (t - x[i]) % MOD;
			continue;
		}
		ll k = -(x[i] - t) * POW(ld, MOD - 2) % MOD;
		Vi c(i-lf-1);
		c.push_back(k);
		for(auto &j : ls) c.push_back(-j * k % MOD);
		if(c.size() < cur.size()) c.resize(cur.size());
		for(int j=0; j<cur.size(); j++){
			c[j] = (c[j] + cur[j]) % MOD;
		}
		if(i-lf+(int)ls.size()>=(int)cur.size()){
			tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % MOD);
		}
		cur = c;
	}
	for(auto &i : cur) i = (i % MOD + MOD) % MOD;
	return cur;
}
int get_nth(Vi rec, Vi dp, ll n){
	int m = rec.size();
	Vi s(m), t(m);
	s[0] = 1;
	if(m != 1) t[1] = 1;
	else t[0] = rec[0];
	auto mul = [&rec](Vi v, Vi w){
		int m = v.size();
		Vi t(2 * m);
		for(int j=0; j<m; j++){
			for(int k=0; k<m; k++){
				t[j+k] += 1ll * v[j] * w[k] % MOD;
				if(t[j+k] >= MOD) t[j+k] -= MOD;
			}
		}
		for(int j=2*m-1; j>=m; j--){
			for(int k=1; k<=m; k++){
				t[j-k] += 1ll * t[j] * rec[k-1] % MOD;
				if(t[j-k] >= MOD) t[j-k] -= MOD;
			}
		}
		t.resize(m);
		return t;
	};
	while(n){
		if(n & 1) s = mul(s, t);
		t = mul(t, t);
		n >>= 1;
	}
	ll ret = 0;
	for(int i=0; i<m; i++) ret += 1ll * s[i] * dp[i] % MOD;
	return ret % MOD;
}
int guess_nth_term(Vi x, ll n){
	if(n < x.size()) return x[n];
	Vi v = berlekamp_massey(x);
	if(v.empty()) return 0;
	return get_nth(v, x, n);
}
int d[1001][201];
int main(){
	ll n;
	int k;
	scanf("%lld%d",&n,&k);
	d[0][0]=1;
	fup(i,1,1000,1){
		d[i][0]=1;
		fup(j,1,k,1){
			d[i][j]=(d[i-1][j]+1ll*(i-1)*d[i-1][j-1])%MOD;
		}
	}
	Vi vv={1};
	fup(j,1,k,1){
		Vi v;
		fup(i,0,1000,1)v.pb(d[i][j]);
		vv.pb(guess_nth_term(v,n));
	}
	fup(i,1,k,1){
		if(i>1)vv[i]=(vv[i]+vv[i-2])%MOD;
		printf("%d ",vv[i]);
	}
}