#define LOCAL
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
  return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

typedef long long int64;
typedef pair<int, int> ii;
const int INF = 1 << 29;
const int MOD = 1e9 + 7;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

const int N = 2000;
bool flag[N];
vector<int> prime;

void prime_gen(int n) {
  fill(flag, flag + n, false);
  for (int i = 2; i < n; ++i) {
    if (!flag[i]) prime.push_back(i);
    for (int j = 0, k; j < prime.size() && (k = prime[j] * i) < n; ++j) {
      flag[k] = true;
      if (i % prime[j] == 0) break;
    }
  }
  // printf("%lu\n", prime.size());
}

int main() {
  prime_gen(N);
  int cas;
  scanf("%d", &cas);
  while (cas--) {
    int n;
    scanf("%d", &n);
    vector<int> ret(n);
    for (int i = 0; i < n; ++i) {
      int m, k = -1;
      scanf("%d", &m);
      for (int j = 0; ; ++j) {
        if (m % prime[j] == 0) {
          k = j;
          break;
        }
      }
      ret[i] = k + 1;
    }
    vector<int> a = ret;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    printf("%d\n", (int)a.size());
    for (int i = 0; i < n; ++i) {
      ret[i] = lower_bound(a.begin(), a.end(), ret[i]) - a.begin() + 1;
      printf("%d%c", ret[i], " \n"[i + 1 == n]);
    }
  }
  return 0;
}