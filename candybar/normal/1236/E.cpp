#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio{
  int it,len;
  char s[LEN + 5];
  fastio(){
    it = len = 0;
  }
  char get(){
    if(it < len) return s[it++];
    it = 0, len = fread(s,1,LEN,stdin);
    return len ? s[it++] : EOF;
  }
  bool notend(){
    char c;
    for(c = get();c == ' ' || c == '\n';c = get());
    if(it) it--;
    return c != EOF;
  }
  void put(char c){
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush(){
    fwrite(s,1,it,stdout);
  }
}buff,bufo;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll(){
  char c; ll res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char(){
  char c;
  for(c = buff.get();c == ' ' || c == '\n';c = buff.get());
  return c;
}
#define maxm 100005
#define maxn 100005
int n,m,a[maxm];
int num[2 * maxm],rb[maxn],lb[maxn];
int main(){
  n = getint(), m = getint();
  for(int i = m + 2;i <= m + 1 + n;i++) num[i] = 1;
  for(int i = 1;i <= m;i++){
    a[i] = getint();
    int id = m + 1 - i + a[i];
    num[id - 1] += num[id];
    num[id] = 0;
  }
  int k = 0;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= num[i];j++){
      rb[++k] = i;
    }
  }
  for(int i = n + 1;i <= n + m + 1;i++){
    for(int j = 1;j <= num[i];j++){
      rb[++k] = n;
    }
  }
  memset(num,0,sizeof(num));
  for(int i = m + 2;i <= m + 1 + n;i++) num[i] = 1;
  for(int i = 1;i <= m;i++){
    int id = m + 1 - i + n - a[i] + 1;
    num[id - 1] += num[id];
    num[id] = 0;
  }
  k = 0;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= num[i];j++){
      lb[n - (++k) + 1] = n - i + 1;
    }
  }
  for(int i = n + 1;i <= n + m + 1;i++){
    for(int j = 1;j <= num[i];j++){
      lb[n - (++k) + 1] = 1;
    }
  }
  ll ans = 0;
  if(n > 1)
    for(int i = 1;i <= n;i++) ans += rb[i] - lb[i] + 1;
  printf("%I64d\n",ans);
  return 0;
}