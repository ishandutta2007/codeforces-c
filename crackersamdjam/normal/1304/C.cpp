#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;

int q, n;
ll m;

int main(){
    scan(q);
    while(q--){
        scan(n, m);
        bool b = 1;
        ll t = 0;
        ll lo = m, hi = m;
        for(int i = 0; i < n; i++){
            ll a, l, r;
            scan(a, l, r);
            hi = min(r, hi+a-t);
            lo = max(l, lo-(a-t));
            t = a;
            if(lo > r or hi < l)
                b = 0;
        }
        puts(b?"YES":"NO");
    }
    
    return 0;
}