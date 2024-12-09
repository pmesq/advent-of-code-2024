#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string ln; cin >> ln;
    int n = ln.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = ln[i] - '0';
    
    vector<vector<int>> s(n);
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < a[i]; ++j) {
                s[i].push_back(i / 2);
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (i % 2) continue;
        for (int j = 1; j < i; j += 2) {
            if (a[j] >= a[i]) {
                a[j] -= a[i];
                for (int k = 0; k < a[i]; ++k) {
                    s[j - 1].push_back(i / 2);
                    s[i].erase(s[i].begin());
                    ++a[i - 1];
                }
                break;
            }
        }
    }
    long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (auto x : s[i]) {
            ans += x * cnt;
            ++cnt;
        }
        if (i % 2) {
            cnt += a[i];
        }
    }
    cout << ans << '\n';

    return 0;
}
