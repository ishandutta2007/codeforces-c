// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int ans = n;

    vector<int> arr(n);
    input_seq(ALL(arr));
    
    for (int pref = 0; pref <= n; ++pref) {
        set<int> st;

        for (int i = 0; i < pref; ++i)
            st.insert(arr[i]);

        if (st.size() != pref)
            break;

        ans = min(ans, n - pref);
        for (int suf = 1; pref + suf <= n; ++suf) {
            if (st.count(arr[n - suf]))
                break;

            st.insert(arr[n - suf]);
            ans = min(ans, n - pref - suf);
        }
    }

    cout << ans << "\n";

    return 0;
}