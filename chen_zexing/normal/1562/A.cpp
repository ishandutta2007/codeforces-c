#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l*2>r) printf("%d\n",r-l);
        else printf("%d\n",r-r/2-1);
    }
    return 0;
}
//
/// 
//01
//