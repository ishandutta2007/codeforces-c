#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...);
}

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

const int N = 3000005;
const int inf = N;

char s[N];
ll n, m;

void work() {
  scanf("%lld%lld", &n, &m);
  scanf("%s", s + 1); n = strlen(s + 1);
  int lst = inf;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      if (lst == inf) continue;
      if (i - lst <= m) {
        m -= i - lst;
        swap(s[lst], s[i]);
        lst++;
      }
      else {
        lst = i - m;
        swap(s[lst], s[i]);
        break;
      }
    }
    else lst = min(lst, i);
  }
  for (int i = 1; i <= n; i++)
    putchar(s[i]);
  puts("");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) work();
  return 0;
}