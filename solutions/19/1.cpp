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

    int ans = 0;
    while (getline(cin, s)) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (auto t : a) {
                int m = t.size();
                if (m <= i && dp[i - m] && t == s.substr(i - m, m)) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        ans += dp[n];
    }
    cout << ans << endl;

    return 0;
}
