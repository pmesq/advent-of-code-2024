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

    int oi = -1, oj = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '^') oi = i, oj = j;
        }
    }

    vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(4, 0)));
    int ans = 0;
    for (int ui = 0; ui < n; ++ui) {
        for (int uj = 0; uj < m; ++uj) {
            if (a[ui][uj] != '.') continue;
            a[ui][uj] = '#';
            int pi = oi, pj = oj, dir = 0;
            int x = 1;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        vis[i][j][k] = 0;
                    }
                }
            }
            while (!vis[pi][pj][dir]) {
                vis[pi][pj][dir] = 1;
                int fnd = 0;
                for (int k = 0; k < 4; ++k) {
                    int qi = pi + di[dir], qj = pj + dj[dir];
                    if (qi < 0 || qj < 0 || qi >= n || qj >= m) {
                        x = 0;
                        break;
                    }
                    if (a[qi][qj] != '#') {
                        pi = qi, pj = qj;
                        fnd = 1;
                        break;
                    }
                    dir = (dir + 1) % 4;
                }
                if (!fnd) break;
            }
            ans += x;
            a[ui][uj] = '.';
        }
    }
    cout << ans << endl;

    return 0;
}
