#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int t, n, x, a[1005];

int main(){
	scan(t);
	while(t--){
		scan(n, x);
		bool b = 1, same = 0;
		int sum = 0;
		for(int i = 0; i < n; i++){
			scan(a[i]);
			same |= a[i] == x;
			b &= a[i] == x;
			sum += a[i]-x;
		}
		if(b){
			print(0);
		}
		else if(same or sum == 0){
			print(1);
		}
		else{
			print(2);
		}
	}
}