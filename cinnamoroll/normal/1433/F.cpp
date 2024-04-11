// warm heart, wagging tail,and a smile just for you!
//                                                                     
//                                                                   
//                                                                
//                                                   
//                                      
//                               
//                             
//                           
//                         
//                       
//                     
//                 
//     
//   
// 
// 
// 
// 
//   
//         
//                                                        
//
#include "bits/stdc++.h"
using namespace std;
#define INF (1<<30)
#define LINF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR2(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define RFOR2(i,a,b) for(int i = (b);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define REP2(i,n)  FOR2(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define RREP2(i,n) RFOR2(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define range2(i,a,b) ((a)<=(i) && (i)<=(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

void solve(){
	int N,M,K;
	cin >> N >> M >> K;

	vec dp(K,-INF);
	dp[0] = 0;
	REP(_,N){
		vector<int> a(M);
		REP(i,M) cin >> a[i];
		
		int dp2[77][40][70];
		REP(i,77) REP(j,40) REP(k,70) dp2[i][j][k] = -INF;
		dp2[0][0][0] = 0;

		REP(i,M){
			REP2(j,M/2){
				REP(k,K){
					chmax(dp2[i+1][j][k],dp2[i][j][k]);
					chmax(dp2[i+1][j+1][(k+a[i])%K],dp2[i][j][k]+a[i]);
				}
			}
		}

		vec tmp(K,-INF);
		REP2(j,M/2) REP(k,K){
			REP(x,K) chmax(tmp[(k+x)%K],dp[x]+dp2[M][j][k]);
		}

		dp = tmp;
	}

	cout << dp[0] << endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	// cin >> T;

	while(T--) solve();

	return 0;
}