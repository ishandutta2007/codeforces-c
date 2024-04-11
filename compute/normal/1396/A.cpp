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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vc<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1)
    {
        cout<<"1 1\n";
        cout<<-a[0]<<'\n';
        for(int i=0;i<2;i++)
        {
            cout<<"1 1\n";
            cout<<0<<'\n';
        }
    }
    else{
        cout<<"1 "<<n<<'\n';
        vc<ll> b(n);
        vc<ll> cur;
        for(int i=0;i<n;i++)
        {
            ll B=-a[i];
            b[i]=B;
            ll A=(a[i]-B*(n-1))/n;
            assert((a[i]-B*(n-1))%n==0);
            cur.push_back(-A*n);
        }
        print(cur);
        cout<<"2 "<<n<<'\n';
        cur.clear();
        for(int i=1;i<n;i++) cur.push_back(-b[i]*(n-1));
        print(cur);
        cout<<"1 1"<<'\n';
        cout<<-b[0]*(n-1)<<'\n';
    }
}