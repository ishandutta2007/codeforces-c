#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "the " << #x << " -> "; err(x); } while (0)
void err() { cout << "" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
const int maxn=3e5+7;
int arr[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]!=arr[0]) {ans=i;break;}
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[n-1]) 
        {
            ans=max(ans,n-1-i);
            break;
        }
    }
    printf("%d\n",ans);


}