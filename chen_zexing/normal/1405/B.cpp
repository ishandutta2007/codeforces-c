#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[100005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        long long ans=0,temp=0;
        for(int i=1;i<=n;i++) temp+=a[i],ans=min(ans,temp);
        printf("%lld\n",-ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp