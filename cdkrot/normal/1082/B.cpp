// 2018, Sayutin Dmitry.

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

#define pb push_back
#define eb emplace_back

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    string s = "S" + input<string>();

    vector<int> a = {0};
    for (int i = 1; i < SZ(s); ++i)
        if (s[i] == s[i - 1])
            a.back() += 1;
        else
            a.push_back(1);

    int res = 0;
    for (int i = 1; i < SZ(a); i += 2)
        res = max(res, a[i] + int(SZ(a) >= 4));

    for (int i = 3; i < SZ(a); i += 2)
        if (a[i - 1] == 1)
            res = max(res, a[i - 2] + a[i] + int(SZ(a) >= 6));

    cout << res << "\n";
    
    return 0;
}