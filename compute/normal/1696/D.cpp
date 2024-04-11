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
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
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

#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
struct D{
    ll lz,mx;
    D(ll v=-0x3f3f3f3f3f3f3f3f):lz(0),mx(v){}
    inline void add(ll v)
    {
        lz+=v;
        mx+=v;
    }
    inline void push(D &x,D &y)
    {
        x.add(lz);
        y.add(lz);
        lz=0;
    }
    inline void change(ll v)
    {
        mx=v;
        lz=0;
    }
    static D merge(D &x,D &y)
    {
        return D(min(x.mx,y.mx));
    }
};
int sz;
template<class D>
struct sgt{
    vc<D> tree;
    sgt(){}
    template<class T>
    sgt(const vc<T>& a)
    {
        int n=a.size();
        sz=1;
        while(sz<n) sz*=2;
        tree.resize(sz*2);
        for(int i=0;i<n;i++) tree[sz+i]=D(a[i]);
        for(int i=sz-1;i>=1;i--) upd(i);
    }
    inline void push(int o)
    {
        tree[o].push(tree[lson],tree[rson]);
    }
    inline void upd(int o)
    {
        tree[o]=D::merge(tree[lson],tree[rson]);
    }
    void add(int l,int r,int val,int L=0,int R=sz-1,int o=1)
    {
        if(l<=L&&r>=R)
        {
            tree[o].add(val);
            return;
        }
        push(o);
        int mid=L+R>>1;
        if(l<=mid) add(l,r,val,Lson);
        if(r>mid) add(l,r,val,Rson);
        upd(o);
    }
    ll query(int l,int r,int L=0,int R=sz-1,int o=1)
    {
        if(l<=L&&r>=R)
            return tree[o].mx;
        push(o);
        int mid=L+R>>1;
        ll ret=0x3f3f3f3f3f3f3f3f;
        if(l<=mid) ret=min(ret,query(l,r,Lson));
        if(r>mid) ret=min(ret,query(l,r,Rson));
        return ret;
    }
    void change(int p, int val,int L=0, int R=sz-1,int o=1)
    {
        if(L==R)
        {
            tree[o].change(val);
            return;
        }
        push(o);
        int mid=L+R>>1;
        if(p<=mid) change(p,val,Lson);
        else change(p,val,Rson);
        upd(o);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vi a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<int> up,down;
        vi dp(n+1);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            while(up.size()&&a[i]<a[up.back()])
                up.pop_back();
            while(down.size()&&a[i]>a[down.back()])
                down.pop_back();
            int pup=up.empty()?0:up.back();
            int pdown=down.empty()?0:down.back();
            if(i>1)
                dp[i]=dp[i-1]+1;
            else dp[i]=0;
            // dbg(pup,pdown);
            // dbg(up);
            // dbg(int(sup.query(pdown+1, i)+1));
            // dbg(int(sdown.query(pup+1, i)+1));
            // dbg(up);
            // dbg(down);
            up.push_back(i);
            down.push_back(i);
            dp[i]=min({dp[i],dp[*lower_bound(up.begin(),up.end(),pdown+1)]+1,dp[*lower_bound(down.begin(),down.end(),pup+1)]+1});
            // dbg(i, dp[i]);
        }
        print(dp[n]);
    }
}