%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x; scanf("%d", &x);
    if (x % 2 == 0) x--;
    printf("%d ", x);
  } 
  putchar('\n');
  return 0;
}