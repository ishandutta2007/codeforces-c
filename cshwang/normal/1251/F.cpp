#include <bits/stdc++.h>

#define ll long long
#define poly std::vector<int>
#define ull unsigned long long

const int MAX_N = 3e5 + 10 , FFTN = 1 << 22 , mod = 998244353 ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

namespace FFT {
    int w[FFTN + 5] , W[FFTN + 5] , R[FFTN + 5] ;
    void FFTinit() {
        W[0] = 1 ;
        W[1] = qpow(3 , (mod - 1) / FFTN) ;
        for (int i = 2 ; i <= FFTN ; ++i) W[i] = 1ll * W[i - 1] * W[1] % mod ;
    }
    int FFTinit(int n) {
        int L = 1 ;
        for (; L <= n ; L <<= 1) ;
        for (int i = 0 ; i <= L - 1 ; ++i) R[i] = (R[i >> 1] >> 1) | ((i & 1) ? (L >> 1) : 0) ;
        return L ;
    }

    ull p[FFTN + 5] ;
    int A[FFTN + 5] , B[FFTN + 5] ;
    void DFT(int *a , int n) {
        for (int i = 0 ; i < n ; ++i) p[R[i]] = a[i] ;
        for (int d = 1 ; d < n ; d <<= 1) {
            int len = FFTN / (d << 1) ;
            for (int i = 0 , j = 0 ; i < d ; ++i , j += len) w[i] = W[j] ;
            for (int i = 0 ; i < n ; i += (d << 1))
                for (int j = 0 ; j < d ; ++j) {
                    int y = p[i + j + d] * w[j] % mod ;
                    p[i + j + d] = p[i + j] + mod - y ;
                    p[i + j] += y ;
                }
            if (d == (1 << 15))
                for (int i = 0 ; i < n ; ++i) p[i] %= mod ;
        }
        for (int i = 0 ; i < n ; ++i) a[i] = p[i] % mod ;
    }
    void IDFT(int *a , int n) {
        for (int i = 0 ; i < n ; ++i) p[R[i]] = a[i] ;
        for (int d = 1 ; d < n ; d <<= 1) {
            int len = FFTN / (d << 1) ;
            for (int i = 0 , j = FFTN ; i < d ; ++i , j -= len) w[i] = W[j] ;
            for (int i = 0 ; i < n ; i += (d << 1))
                for (int j = 0 ; j < d ; ++j) {
                    int y = p[i + j + d] * w[j] % mod ;
                    p[i + j + d] = p[i + j] + mod - y ;
                    p[i + j] += y ;
                }
            if (d == (1 << 15))
                for (int i = 0 ; i < n ; ++i) p[i] %= mod ;
        }
        int val = qpow(n , mod - 2) ;
        for (int i = 0 ; i < n ; ++i) a[i] = p[i] * val % mod ;
    }
    poly Plus(const poly &a , const poly &b) {
        int sza = a.size() - 1 , szb = b.size() - 1 ;
        poly ans(std::max(sza , szb) + 1) ;
        for (int i = 0 ; i <= sza ; ++i) ans[i] = a[i] ;
        for (int i = 0 ; i <= szb ; ++i) ans[i] = (ans[i] + b[i]) % mod ;
        return ans ;
    }
    poly Minus(const poly &a , const poly &b) {
        int sza = a.size() - 1 , szb = b.size() - 1 ;
        poly ans(std::max(sza , szb) + 1) ;
        for (int i = 0 ; i <= sza ; ++i) ans[i] = a[i] ;
        for (int i = 0 ; i <= szb ; ++i) ans[i] = (ans[i] + mod - b[i]) % mod ;
        return ans ;
    }
    poly Mul(const poly &a , const poly &b) {
        int sza = a.size() - 1 , szb = b.size() - 1 ;
        poly ans(sza + szb + 1) ;
        if (sza <= 30 || szb <= 30) {
            for (int i = 0 ; i <= sza ; ++i)
                for (int j = 0 ; j <= szb ; ++j)
                    ans[i + j] = (ans[i + j] + 1ll * a[i] * b[j]) % mod ;
            return ans ;
        }
        int L = FFTinit(sza + szb) ;
        for (int i = 0 ; i < L ; ++i) A[i] = (i <= sza ? a[i] : 0) ;
        for (int i = 0 ; i < L ; ++i) B[i] = (i <= szb ? b[i] : 0) ;
        DFT(A , L) , DFT(B , L) ;
        for (int i = 0 ; i < L ; ++i) A[i] = 1ll * A[i] * B[i] % mod ;
        IDFT(A , L) ;
        for (int i = 0 ; i <= sza + szb ; ++i) ans[i] = A[i] ;

        return ans ;
    }
    poly PolyPow(const poly &a , int b) {
        int sza = a.size() - 1 ;
        poly ans(sza * b + 1) ;
        int L = FFTinit(sza * b + 1) ;
        for (int i = 0 ; i < L ; ++i) A[i] = (i <= sza ? a[i] : 0) ;
        DFT(A , L) ;
        for (int i = 0 ; i < L ; ++i) A[i] = qpow(A[i] , b) ;
        IDFT(A , L) ;
        for (int i = 0 ; i <= sza * b ; ++i) ans[i] = A[i] ;

        return ans ;
    }
} ;

poly r[10] ;
int n , k , b[MAX_N] , cnt[MAX_N] ;

int main() {
    FFT::FFTinit() ;
    scanf("%d %d" , &n , &k) ;
    for (int i = 0 ; i < n ; ++i) {
        int v ; scanf("%d" , &v) ;
        ++cnt[v] ;
    }
    for (int i = 0 ; i < k ; ++i) {
        int v ; scanf("%d" , &v) ; b[i] = v ;

        int c1 = 0 , c2 = 0 ;
        poly f = {1 , 2} , g = {1 , 2 , 1} ;
        for (int j = 0 ; j < v ; ++j)
            if (cnt[j] == 1) ++c1 ;
            else if (cnt[j] > 1) ++c2 ;
        
        f = FFT::PolyPow(f , c1) ; g = FFT::PolyPow(g , c2) ;
        r[i] = FFT::Mul(f , g) ;
    }

    ///

    int q ; scanf("%d" , &q) ;
    for (; q-- ;) {
        int v , ans = 0 ; scanf("%d" , &v) ;
        for (int i = 0 ; i < k ; ++i) {
            int lef = (v - (b[i] << 1) - 2) >> 1 ;
            if (lef < 0 || lef >= r[i].size()) continue ;
            (ans += r[i][lef]) %= mod ;
        }
        printf("%d\n" , ans) ;
    }

    return 0 ;
}