#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<long long> a, b;
    long long x, y;
    while (cin >> x >> y) {
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    for (int i = 0; i < (int) a.size(); ++i) {
        ans += abs(a[i] - b[i]);
    }
    cout << ans << endl;

    return 0;
}
