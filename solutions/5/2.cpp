#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int g[100][100] = {0};
    vector<vector<int>> pv;

    string a;
    while (cin >> a) {
        if (a.size() == 0) {
            continue;
        } else if (a[2] == '|') {
            int u = (a[0] - '0') * 10 + a[1] - '0';
            int v = (a[3] - '0') * 10 + a[4] - '0';
            g[u][v] = 1;
        } else {
            vector<int> p;
            for (int i = 0; i < (int) a.size(); i += 3) {
                p.push_back((a[i] - '0') * 10 + a[i + 1] - '0');
            }
            pv.push_back(p);
        }
    }
    
    long long ans = 0;
    for (auto p : pv) {
        int psb = 1;
        int f[100] = {0};
        for (int x : p) {
            for (int i = 10; i < 100; ++i) {
                if (f[i] && g[x][i]) psb = 0;
            }
            f[x] = 1;
        }
        if (psb) continue;

        int deg[100] = {0};
        for (int i = 0; i < (int) p.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int u = p[j], v = p[i];
                if (g[u][v]) ++deg[v];
                if (g[v][u]) ++deg[u];
            }
        }

        int d[100] = {0};
        queue<int> q;
        for (int u : p) {
            if (deg[u] == 0) q.push(u);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : p) {
                if (u == v) continue;
                if (!g[u][v]) continue;
                if (--deg[v] == 0) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        sort(p.begin(), p.end(), [&](int u, int v) {
            return d[u] < d[v];
        });
        ans += p[(int) p.size() / 2];
    }
    cout << ans << endl;

    return 0;
}
