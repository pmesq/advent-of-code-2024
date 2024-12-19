#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<string> a;
    string ln;
    getline(cin, ln);
    stringstream ss(ln);
    string s;
    while (ss >> s) {
        if (s.back() == ',') s.pop_back();
        a.push_back(s);
    }
    getline(cin, ln);

    long long ans = 0;
    while (getline(cin, s)) {
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (auto t : a) {
                int m = t.size();
                if (m <= i && t == s.substr(i - m, m)) {
                    dp[i] += dp[i - m];
                }
            }
        }
        ans += dp[n];
    }
    cout << ans << endl;

    return 0;
}
