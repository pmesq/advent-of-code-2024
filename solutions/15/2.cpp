#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<string> g;
    string a;

    string ln;
    while (getline(cin, ln)) {
        if (ln[0] == '#') {
            string s;
            for (char ch : ln) {
                if (ch == '#') s += "##";
                if (ch == 'O') s += "[]";
                if (ch == '.') s += "..";
                if (ch == '@') s += "@.";
            }
            g.push_back(s);
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
        if (di == 0) {
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
        } else {
            int psb = 1;
            queue<pair<int, int>> q;
            vector<pair<int, int>> ord;
            set<pair<int, int>> vis;
            q.push({ui, uj});
            vis.insert({ui, uj});
            while (!q.empty()) {
                auto [vi, vj] = q.front(); q.pop();
                ord.emplace_back(vi, vj);
                int wi = vi + di, wj = vj + dj;
                if (g[wi][wj] == '#') {
                    psb = 0;
                    break;
                } else if (g[wi][wj] == '[') {
                    if (vis.find({wi, wj}) == vis.end()) {
                        vis.insert({wi, wj});
                        q.push({wi, wj});
                    }
                    if (vis.find({wi, wj + 1}) == vis.end()) {
                        vis.insert({wi, wj + 1});
                        q.push({wi, wj + 1});
                    }
                } else if (g[wi][wj] == ']') {
                    if (vis.find({wi, wj}) == vis.end()) {
                        vis.insert({wi, wj});
                        q.push({wi, wj});
                    }
                    if (vis.find({wi, wj - 1}) == vis.end()) {
                        vis.insert({wi, wj - 1});
                        q.push({wi, wj - 1});
                    }
                }
            }
            if (psb) {
                reverse(ord.begin(), ord.end());
                for (auto [vi, vj] : ord) {
                    int pi = vi + di, pj = vj + dj;
                    g[pi][pj] = g[vi][vj];
                    g[vi][vj] = '.';
                }
                ui += di;
                uj += dj;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '[') {
                ans += 100 * i + j;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
