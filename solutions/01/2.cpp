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
    map<long long, int> c;
    for (auto x : b) ++c[x];
    long long ans = 0;
    for (auto x : a) {
        ans += x * c[x];
    }
    cout << ans << endl;

    return 0;
}
