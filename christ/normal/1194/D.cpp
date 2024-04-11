#include <bits/stdc++.h>
using namespace std;
#define min(...) minn(__VA_ARGS__)
#define max(...) maxx(__VA_ARGS__)
#define stringio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
char _;
typedef long long ll;
typedef pair<int,int> pii;
#define getchar_unlocked getchar
template<typename t>constexpr const t minn(const t x,const t y){return x<y?x:y;}
template<typename t,typename ...r>constexpr const t minn(const t x,const r ...xs){return minn(x,minn(xs...));}
template<typename t>constexpr const t maxx(const t x,const t y){return x>y?x:y;}
template<typename t,typename ...r>constexpr const t maxx(const t x,const r ...xs){return maxx(x,maxx(xs...));}
template <typename t> void scan (t& x) {do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MAXN = 1005;
int main() {
  int t;
  scan(t);
  while (t--) {
    int n,k;
    scan(n,k);
    if (k%3 || k > n) {
      printf (n%3 ? "Alice\n" : "Bob\n");
    }
    else {
      int cycle = k+1, mod = n%cycle;
      printf (mod%3 == 0 && mod != k ? "Bob\n" : "Alice\n");
    }
  }
    return 0;
}