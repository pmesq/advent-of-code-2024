#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string a; cin >> a;
    int n = a.size();

    vector<int> s;
    for (int i = 0; i < n; ++i) {
        int x = a[i] - '0';
        for (int j = 0; j < x; ++j) {
            if (i % 2) s.push_back(-1);
            else s.push_back(i / 2);
        }
    }

    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != -1) ++l;
        else {
            s[l] = s[r];
            s[r] = -1;
            --r;
        }
    }
    long long ans = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] == -1) continue;
        ans += i * s[i];
    }
    cout << ans << '\n';

    return 0;
}
