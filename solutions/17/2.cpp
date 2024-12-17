#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string ln;
    for (int i = 0; i < 5; ++i) getline(cin, ln);

    vector<int> a;
    for (int i = 9; i < (int) ln.size(); i += 2) {
        a.push_back(ln[i] - '0');
    }

    const int n = 1 << 10, k = (int) a.size();

    vector<int> f(n);
    for (int A = 0; A < n; ++A) {
        int B = (A & 7) ^ 5;
        int C = (A >> B);
        B ^= (6 ^ C);
        f[A] = B & 7;
    }

    vector<vector<long long unsigned>> dp(n, vector<long long unsigned>(k, -1));
    for (int j = k - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            if (f[i] != a[j]) continue;
            if (j == k - 1) {
                dp[i][j] = i;
                continue;
            }
            for (int cto = 0; cto < 8; ++cto) {
                int to = (i >> 3) ^ (cto << 7);
                if (dp[to][j + 1] == -1) continue;
                dp[i][j] = min(dp[i][j], (dp[to][j + 1] << 3) ^ (i & 7));
            }
        }
    }

    long long unsigned ans = -1;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[i][0]);
    }
    cout << ans << endl;

    return 0;
}
