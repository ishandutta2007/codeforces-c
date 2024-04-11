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
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    int n;
    cin >> n;

    vector<int> a[n];
    REP(i,n){
      int x,y;
      cin >> x >> y;
      a[x].push_back(y);
    }

    vec s(n,0);
    REP(i,n) s[i] = a[i].size();
    REP(i,n-1) s[i+1] += s[i];

    priority_queue<int,vec,greater<int>> que;
    int ans = 0, now = 0;
    RREP(i,n){
      //debug(s[i]);
      if(s[i]+now >= i+1){  
        for(int x:a[i]) que.push(x);
        continue;
      }
      REP(_,(i+1)-(s[i]+now)) ans += que.top(), que.pop();
      now += (i+1)-(s[i]+now);
      for(int x:a[i]) que.push(x);
    }

    cout << ans << "\n";
  }

  return 0;
}