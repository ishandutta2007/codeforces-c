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
#define INF 1LL<<60
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //

  int n;
  cin >> n;

  vector<string> s(n);
  REP(i,n) cin >> s[i];

  int ans = 0;
  int dx[] = {-1,-1,1,1}, dy[] = {-1,1,-1,1};
  FOR(i,1,n-1){
    FOR(j,1,n-1){
      if(s[i][j] != 'X') continue;
      bool f = true;
      REP(k,4){
        if(s[i+dx[k]][j+dy[k]] != 'X') f = false;
      }
      if(f) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}