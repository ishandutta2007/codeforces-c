#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
int T,n;
int a,b,c;
void solve(){
    cin>>n;
    if(n&1){
        cout<<-1<<'\n';return;
    }
    cout<<n/2<<' '<<0<<' '<<0<<'\n';
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}