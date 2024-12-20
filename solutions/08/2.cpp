#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<string> a, b;
    string ln;
    while (cin >> ln) a.push_back(ln);
    b = a;
    int n = a.size();
    int m = a[0].size();

    for (int ui = 0; ui < n; ++ui) {
        for (int uj = 0; uj < m; ++uj) {
            for (int vi = 0; vi < n; ++vi) {
                for (int vj = 0; vj < m; ++vj) {
                    if (ui == vi && uj == vj) continue;
                    if (!(a[ui][uj] == a[vi][vj] && a[ui][uj] != '.')) continue;
                    int di = vi - ui, dj = vj - uj;
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < m; ++j) {
                            int dui = i - ui, duj = j - uj;
                            if (di * duj == dj * dui) b[i][j] = '#';
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += b[i][j] == '#';
        }
    }
    cout << ans << endl;

    return 0;
}
