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

  int n,m;
  cin >> n >> m;

  vec a(n);
  REP(i,n) cin >> a[i];

  set<int> st[n+1];
  REP(i,m){
    int x,y;
    cin >> x >> y;
    st[x].insert(y);
  }

  int ans = 0;
  vec perm; //Nastya
  perm.push_back(a[n-1]);
  RREP(i,n-1){
    bool flag = true;
    //NG
    for(int x:perm){
      if(st[a[i]].find(x) == st[a[i]].end()){
        flag = false;
        break; //breakmO(m)
      }
    }
    if(flag) ans++;
    //Nastya
    else perm.push_back(a[i]);
  }

  cout << ans << endl;

  return 0;
}