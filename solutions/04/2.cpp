#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<string> a;
    string ln;
    while (cin >> ln) a.push_back(ln);

    int ans = 0;
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != 'A' || i - 1 < 0 || i + 1 >= n || j - 1 < 0 || j + 1 >= m) continue;
            ans += 
                (
                    a[i - 1][j - 1] == 'M' && a[i + 1][j + 1] == 'S'
                    ||
                    a[i - 1][j - 1] == 'S' && a[i + 1][j + 1] == 'M'
                ) && (
                    a[i - 1][j + 1] == 'M' && a[i + 1][j - 1] == 'S'
                    ||
                    a[i - 1][j + 1] == 'S' && a[i + 1][j - 1] == 'M'
                );
        }
    }
    cout << ans << endl;

    return 0;
}
