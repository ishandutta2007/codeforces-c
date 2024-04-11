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
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8



int main(){
    int n, x;
    cin >> n;
    vint p, m;
    for(int i = 0; i < 2 * n - 1; ++i){
        cin >> x;
        if(x >= 0){ p.push_back(x); }
        else{ m.push_back(-x); }
    }
    sort(ALL(p));
    sort(ALL(m));

    if(n % 2){
        for(int i = 0; i < m.size(); ++i){
            p.push_back(m[i]);
        }
    }
    else{
        while(m.size() > 1){
            p.push_back(m.back());
            m.pop_back();
            p.push_back(m.back());
            m.pop_back();
        }
        if(!m.empty()){
            sort(ALL(p));
            if(m[0] > p[0]){
                p[0] = -p[0];
                p.push_back(m[0]);
            }
            else{
                p.push_back(-m[0]);
            }
        }
    }
    
    printf("%d\n", accumulate(ALL(p), 0));
}