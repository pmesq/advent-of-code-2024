#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s = "XMAS";
    vector<pair<int, int>> dir({
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        {1, 1}, {1, -1}, {-1, -1}, {-1, 1},
    });

    vector<string> a;
    string ln;
    while (cin >> ln) a.push_back(ln);

    int ans = 0;
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (auto [di, dj] : dir) {
                int psb = 1;
                int ui = i, uj = j;
                for (int k = 0; k < 4; ++k) {
                    if (ui < 0 || uj < 0 || ui >= n || uj >= m || a[ui][uj] != s[k]) {
                        psb = 0;
                        break;
                    }
                    ui += di;
                    uj += dj;
                }
                ans += psb;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
