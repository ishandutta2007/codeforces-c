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

template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(F f,T ti):f(f),ti(ti){}
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }
  void build(const vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }
  void update(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }
  void add(int k,T x){
    dat[k+=n]+=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }
  T query(int a,int b){
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }
  //lower_find(l,r,fanc): fanc[0,id)id. ng < ok
  template<typename C>
  int lower_find(int a, int b, C &check, T x, int k=1, int l=0, int r=-1){
    if(r<0) r=n;
    if(!check(f(x,dat[k]))||r<=a||b<=l) return -1;
    if(r-l==1) return r;
    int xl = lower_find(a,b,check,x,(k<<1),l,(l+r)/2);
    if(xl>=0)return xl;
    x = f(x,dat[(k<<1)]);
    return lower_find(a,b,check,x,(k<<1)|1,(l+r)/2,r);
  }
  template<typename C>
  int lower_find(int a, int b, C &check){
    T x=ti;
    if(check(x)) return a;
    return lower_find(a,b,check,x);
  }

  //upper_find(l,r,fanc): fanc[id,N)id. ok < ng
  template<typename C>
  int upper_find(int a, int b, C &check, T x, int k=1, int l=0, int r=-1){
    if(r<0)r=n;
    if(!check(f(x,dat[k]))||r<=a||b<=l) return -1;
    if(r-l==1) return l;
    int xr = upper_find(a,b,check,x,(k<<1)|1,(l+r)/2,r);
    if(xr>=0)return xr;
    x = f(x,dat[(k<<1)|1]);
    return upper_find(a,b,check,x,(k<<1),l,(l+r)/2);
  }
  template<typename C>
  int upper_find(int a, int b, C &check){
    T x=ti;
    if(check(x)) return b;
    return upper_find(a,b,check,x);
  }
};

void solve(){
  int N;
  cin >> N;

  vector<int> a(N),b(N);
  map<int,int> id;
  REP(i,N){
    cin >> a[i] >> b[i];
    if(b[i]>0) id[b[i]]++;
  }
  int tmp = 0;
  ITR(itr,id) itr->sc = tmp++; 

  auto f = [](int a, int b){return a+b;};
  SegmentTree<int> cnt(f,0), sum(f,0);
  cnt.build(vec(N,0)); sum.build(vec(N,0));

  set<int> st;
  REP(i,N){
    int in = id[abs(b[i])];
    sum.add(in,b[i]);
    if(b[i]>0){
      cnt.add(in,1);
      if(a[i]==1) st.insert(b[i]); 
    }
    else{
      cnt.add(in,-1);
      if(a[i]==1) st.erase(st.find(-b[i]));       
    }
    if(!st.size()) cout << sum.query(0,N) << endl;
    else{
      int mn = *st.begin();
      int now = sum.query(0,N);

      sum.add(id[mn],-mn);
      cnt.add(id[mn],-1);

      int k = cnt.query(0,N);
      auto check = [&](int a){return a >= k-st.size();};
      int ok = cnt.lower_find(0,N,check);
      cout << now + sum.query(0,N) - sum.query(0,ok) << endl;

      sum.add(id[mn],mn);
      cnt.add(id[mn],1);
    }
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}