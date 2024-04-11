#pragma GCC optimize(2)
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

const int N = 200005;
int step[N], L[N], R[N];
char s[N];
int n, m;

char rev(char x) {
  if (x == 'W') return 'B';
  else return 'W';
}

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  memset(step, -1, sizeof(step));
  for (int i = 1; i <= n; i++) {
    if (i == 1) L[i] = n; else L[i] = i - 1;
    if (i == n) R[i] = 1; else R[i] = i + 1;
  }
  
  queue <int> q;
  for (int i = 1; i <= n; i++) {
    if (s[L[i]] == s[i] || s[i] == s[R[i]])
      step[i] = 0, q.push(i);
  }
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (step[L[u]] == -1) step[L[u]] = step[u] + 1, q.push(L[u]);
    if (step[R[u]] == -1) step[R[u]] = step[u] + 1, q.push(R[u]);
  }
  
  for (int i = 1; i <= n; i++) {
    if (step[i] > m || step[i] == -1) {
      if (m & 1)
        printf("%c", rev(s[i]));
      else
        printf("%c", s[i]);
    }
    else {
      if (step[i] & 1)
        printf("%c", rev(s[i]));
      else
        printf("%c", s[i]);
    }
  }
  return putchar('\n') & 0;
}