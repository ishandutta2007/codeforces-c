#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
using namespace std;


typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t){
    stringstream ss;
    ss << f;
    ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


int m;
vector<int> digs;
VV(LL) dp;

LL dfs(bool fst, int d, int S){
    if(!S){
        return (d ? 0 : 1);
    }
    
    LL &res = dp[d][S];
    if(res != -1){ return res; }
    res = 0;

    int use = (fst ? 1 : 0);
    for(int i = digs.size(); i--; ){
        if(S >> i & 1 && !(use >> digs[i] & 1)){
            res += dfs(false, (d * 10 + digs[i]) % m, S ^ (1 << i));
            use |= 1 << digs[i];
        }
    }

    return res;
}


int main(){
    string s;
    cin >> s >> m;
    int n = s.size();
    digs.resize(n);
    for(int i = 0; i < n; ++i){
        digs[i] = s[i] - '0';
    }

    initvv(dp, m, 1 << n, -1LL);

    LL ans = dfs(true, 0, (1 << n) - 1);
    cout << ans << endl;
}