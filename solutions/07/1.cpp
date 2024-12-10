#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    long long ans = 0;

    string ln;
    while (getline(cin, ln)) {
        stringstream ss(ln);
        long long y; ss >> y;
        ss.ignore();
        vector<long long> p;
        long long x;
        while (ss >> x) p.push_back(x);
        int n = (int) p.size();
        int psb = 0;
        for (int m = 0; m < (1 << (n - 1)); ++m) {
            x = p[0];
            for (int i = 0; i < n - 1; ++i) {
                if (m & (1 << i)) {
                    x *= p[i + 1];
                } else {
                    x += p[i + 1];
                }
                if (x > y) break;
            }
            if (x == y) psb = 1;
        }
        ans += psb * y;
    }

    cout << ans << endl;

    return 0;
}
