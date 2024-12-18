#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<pair<int, int>> a;

    string ln;
    while (cin >> ln) {
        int p = -1;
        int x = 0, y = 0;
        int fnd = 0;
        for (int i = 0; i < (int) ln.size(); ++i) {
            if (ln[i] == ',') {
                fnd = 1;
            } else {
                if (!fnd) x = 10 * x + ln[i] - '0';
                else y = 10 * y + ln[i] - '0';
            }
        }
        a.emplace_back(x, y);
    }

    vector<pair<int, int>> dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});

    const int n = 71;
    vector<vector<int>> g(n, vector<int>(n, 1));
    vector<vector<int>> d(n, vector<int>(n, -1));

    int l = 1, r = (int) a.size();
    while (l < r) {
        int mid = (l + r) / 2;

        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                g[y][x] = 1;
                d[y][x] = -1;
            }
        }

        for (int i = 0; i < mid; ++i) {
            auto [x, y] = a[i];
            g[y][x] = 0;
        }        

        queue<pair<int, int>> q;
        q.push({0, 0});
        d[0][0] = 0;
        while (!q.empty()) {
            auto [ui, uj] = q.front(); q.pop();
            for (auto [di, dj] : dir) {
                int vi = ui + di, vj = uj + dj;
                if (vi < 0 || vj < 0 || vi >= n || vj >= n) continue;
                if (d[vi][vj] != -1) continue;
                if (g[vi][vj] == 0) continue;
                d[vi][vj] = d[ui][uj] + 1;
                q.push({vi, vj});
            }
        }

        if (d[n - 1][n - 1] == -1) r = mid;
        else l = mid + 1;
    }

    auto [ansx, ansy] = a[l - 1];
    cout << ansx << ',' << ansy << endl;

    return 0;
}
