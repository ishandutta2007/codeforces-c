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
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define pb push_back
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,x;
  cin >> n >> x;

  vec a(n);
  REP(i,n) cin >> a[i];

  mat dp(n+1,vec(3,0));
  int ans = 0;
  REP(i,n){
    dp[i+1][0] = max(dp[i][0]+a[i],a[i]);
    dp[i+1][1] = max(dp[i][1]+x*a[i],max(0LL,dp[i][0])+x*a[i]);
    dp[i+1][2] = max(dp[i][2]+a[i],max(0LL,dp[i][1])+a[i]);
    ans = max({ans,dp[i+1][0],dp[i+1][1],dp[i+1][2]});
  }

  cout << ans << endl;
  

  return 0;
}