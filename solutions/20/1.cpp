#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    const int K = 2;

    vector<string> a;
    string ln;
    while (getline(cin, ln)) a.push_back(ln);

    int n = a.size(), m = a[0].size();

    int si = -1, sj = -1, ei = -1, ej = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'S') si = i, sj = j;
            if (a[i][j] == 'E') ei = i, ej = j;
        }
    }

    vector<pair<int, int>> dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});

    vector<vector<int>> d(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({si, sj});
    d[si][sj] = 0;
    while (!q.empty()) {
        auto [ui, uj] = q.front(); q.pop();
        for (auto [di, dj] : dir) {
            int vi = ui + di, vj = uj + dj;
            if (a[vi][vj] == '#') continue;
            if (d[vi][vj] != -1) continue;
            d[vi][vj] = d[ui][uj] + 1;
            q.push({vi, vj});
        }
    }

    int ans = 0;

    for (int ui = 0; ui < n; ++ui) {
        for (int uj = 0; uj < m; ++uj) {
            if (a[ui][uj] == '#') continue;
            for (int vi = max(0, ui - K); vi < min(n, ui + K + 1); ++vi) {
                for (int vj = max(0, uj - K); vj < min(m, uj + K + 1); ++vj) {
                    if (a[vi][vj] == '#') continue;
                    int md = abs(ui - vi) + abs(uj - vj);
                    if (md > K) continue;
                    if (d[vi][vj] - d[ui][uj] - md >= 100) ++ans;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
