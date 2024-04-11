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


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back
#define ITR ::iterator


#define MOD 1000000009LL
#define EPS 1e-8



int main(){
	int n, k;
	scanf("%d%d", &n, &k);

	vvint v(k, vint(n + 1, n));

	for(int i = 0; i < k; ++i){
		for(int j = 1; j <= n - 2; ++j){
			if(n - j >= (1 << i + 1)){
				v[i][j] = 1;
			}
			else if((n - j) & (1 << i)){
				v[i][j] = n - (n - j - (1 << i));
			}
		}
	}

	for(int i = 0; i < k; ++i){
		for(int j = 1; j <= n; ++j){
			if(j != 1){ putchar(' '); }
			printf("%d", v[i][j]);
		}
		puts("");
	}
}