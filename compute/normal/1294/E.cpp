#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
const int maxn=2e5+7;
int n,m;
inline int getid(int x,int y)
{
    return x*m+y+1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    vc<vi> maze(n,vi(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>maze[i][j];
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        vi cnt(n);
        int tar=i+1;
        for(int j=0;j<n;j++)
        {
            int cc=maze[j][i]%m;
            if(cc==0) cc=m;
            if(cc==tar)
            {
                int pos=maze[j][i]/m;
                if(cc==m) pos--;
                if(pos>=n) continue;
                int d=(j-pos+n)%n;
                cnt[d]++;
            }
        }
        int cost=n;
        for(int j=0;j<n;j++){
           // dbg(j,cnt[j]);
            cost=min(cost,j+n-cnt[j]);
        }
        ans+=cost;
    }
    cout<<ans<<'\n';
}