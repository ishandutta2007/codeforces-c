#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 1000000007
#define ll long long

int f[4010][4010], g[4010], C[4010][4010], n, ans;

int main(){
    scanf("%d", &n);
    f[0][0] = 1, g[0] = 1, C[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            f[i][j] = (f[i - 1][j - 1] + (ll)f[i - 1][j] * j % M) % M;
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % M;
            g[i] = (g[i] + f[i][j]) % M;
        }
        C[i][0] = 1;
    }
    for(int i = 1; i <= n; i++){
        ans = (ans + (ll)C[n][i] * g[n - i] % M) % M;
    }
    printf("%d\n", ans);
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/