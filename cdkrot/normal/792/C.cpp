// Copyright (C) 2017 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; version 3

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <assert.h>
#include <iterator>
#include <cstdint>
#include <cinttypes>
#include <string.h>
#include <random>
#include <numeric>


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

struct dp {
    int n[3]; // min possible to do this, solution must be non-empty(!)

    int tk[3];
};

const int inf = TYPEMAX(int) / 2;

dp adv(dp d, int ch) {
    dp r = d;
    r.tk[0] = r.tk[1] = r.tk[2] = false;
    for (int i = 0; i != 3; ++i)
        if (r.n[(i + ch) % 3] < d.n[i] + 1) {
            r.n[(i + ch) % 3] = d.n[i] + 1;
            r.tk[(i + ch) % 3] = 1;
        }
    
    
    if (ch != 0 and r.n[ch % 3] <= 0) {
        r.n[ch % 3] = 1;
        r.tk[ch % 3] = 2;
    }
    return r;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    string st = input<string>();
    vector<dp> DP(st.size() + 1);
    DP[0] = dp {{-inf, -inf, -inf}, {1, 2, 228}};

    for (int i = 0; i != SZ(st); ++i)
        DP[i + 1] = adv(DP[i], st[i] - '0');

    if (DP.back().n[0] <= 0) {
        if (std::find(ALL(st), '0') != st.end())
            cout << "0\n";
        else
            cout << "-1\n";
    } else {
        vector<char> ans;
        int tr = 0;
        for (int i = SZ(st); i != 0; --i) {
            int t;
            if ((t = DP[i].tk[tr])) {
                ans.push_back(st[i - 1]);
                tr = (9 + tr - (st[i - 1] - '0')) % 3;
            }

            if (t == 2)
                break;
        }

        std::reverse(ALL(ans));
        ans.push_back('\n');
        ans.push_back(0);
        cout << ans.data();
    }
    
    return 0;
}