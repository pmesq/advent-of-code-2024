#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int g[100][100] = {0};

    long long ans = 0;
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
            int psb = 1;
            int f[100] = {0};
            for (int u : p) {
                for (int i = 10; i < 100; ++i) {
                    if (f[i] && g[u][i]) psb = 0;
                }
                f[u] = 1;
            }
            ans += psb * p[(int) p.size() / 2];
        }
    }
    cout << ans << endl;

    return 0;
}
