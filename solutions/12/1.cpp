#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pair<int, int>> dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});

    vector<string> a;
    string ln;
    while (cin >> ln) a.push_back(ln);

    int n = a.size(), m = a[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (vis[i][j]) continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            int area = 0, per = 0;
            vis[i][j] = 1;
            while (!q.empty()) {
                auto [ui, uj] = q.front(); q.pop();
                ++area;
                for (auto [di, dj] : dir) {
                    int vi = ui + di, vj = uj + dj;
                    if (vi < 0 || vj < 0 || vi >= n || vj >= m || a[vi][vj] != a[ui][uj]) {
                        ++per;
                        continue;
                    }
                    if (vis[vi][vj]) continue;
                    vis[vi][vj] = 1;
                    q.push({vi, vj});
                }
            }
            ans += (long long) area * per;
        }
    }
    cout << ans << endl;

    return 0;
}
