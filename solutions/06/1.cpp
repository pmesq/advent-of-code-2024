#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, 1, 0, -1};

    vector<string> a;
    string ln;
    while (cin >> ln) a.push_back(ln);
    int n = a.size(), m = a[0].size();

    int dir = 0;
    int pi = -1, pj = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '^') pi = i, pj = j;
        }
    }

    vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(4, 0)));
    while (!vis[pi][pj][dir]) {
        vis[pi][pj][dir] = 1;
        int fnd = 0;
        for (int k = 0; k < 4; ++k) {
            int qi = pi + di[dir], qj = pj + dj[dir];
            if (qi < 0 || qj < 0 || qi >= n || qj >= m) break;
            if (a[qi][qj] != '#') {
                pi = qi, pj = qj;
                fnd = 1;
                break;
            }
            dir = (dir + 1) % 4;
        }
        if (!fnd) break;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = 0;
            for (int k = 0; k < 4; ++k) {
                x |= vis[i][j][k];
            }
            ans += x;
        }
    }
    cout << ans << endl;

    return 0;
}
