#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second

int main() {
  string a, b;
  cin >> a >> b;
  cout << a << ' ' << b << endl;
  int n;
  cin >> n;
  while (n--) {
    string c, d;
    cin >> c >> d;
    if (a == c) a = d;
    else b = d;
    cout << a << ' ' << b << endl;
  }
  return 0;
}