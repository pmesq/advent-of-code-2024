#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<pair<int, int>> dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});

    vector<string> a;
    string ln;
    while (cin >> ln) a.push_back(ln);
    int n = a.size(), m = a[0].size();

    vector<pair<int, int>> f[10];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            f[a[i][j] - '0'].emplace_back(i, j);
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, 0));

    long long ans = 0;
    for (int d = 9; d >= 0; --d) {
        for (auto [i, j] : f[d]) {
            if (d == 9) dp[i][j] = 1;
            for (auto [di, dj] : dir) {
                int ui = i + di, uj = j + dj;
                if (ui < 0 || uj < 0 || ui >= n || uj >= m) continue;
                if (a[ui][uj] != a[i][j] + 1) continue;
                dp[i][j] += dp[ui][uj];
            }
            if (d == 0) ans += dp[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}
