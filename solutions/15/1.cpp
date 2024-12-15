#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<string> g;
    string a;

    string ln;
    while (getline(cin, ln)) {
        if (ln[0] == '#') {
            g.push_back(ln);
        } else {
            a += ln;
        }
    }

    int n = g.size(), m = g[0].size();

    int ui = -1, uj = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '@') {
                ui = i, uj = j;
                g[i][j] = '.';
            }
        }
    }

    pair<int, int> dir[128];
    dir['^'] = {-1, 0};
    dir['>'] = {0, 1};
    dir['v'] = {1, 0};
    dir['<'] = {0, -1};

    for (char ch : a) {
        auto [di, dj] = dir[ch];
        for (int k = 1; g[ui + di * k][uj + dj * k] != '#'; ++k) {
            if (g[ui + di * k][uj + dj * k] == '.') {
                for (int p = k; p >= 1; --p) {
                    g[ui + di * p][uj + dj * p] = g[ui + di * (p - 1)][uj + dj * (p - 1)];
                }
                ui += di;
                uj += dj;
                break;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'O') {
                ans += 100 * i + j;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
