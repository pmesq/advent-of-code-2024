#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    const int inf = INT_MAX;

    int ans = 0;

    string s;
    while (getline(cin, s)) {
        int ax = (s[12] - '0') * 10 + s[13] - '0';
        int ay = (s[18] - '0') * 10 + s[19] - '0';
        getline(cin, s);
        int bx = (s[12] - '0') * 10 + s[13] - '0';
        int by = (s[18] - '0') * 10 + s[19] - '0';
        getline(cin, s);
        int x = 0, y = 0;
        int fnd = 0;
        for (int i = 0; i < (int) s.size(); ++i) {
            if (isdigit(s[i]) && !fnd) {
                x *= 10;
                x += s[i] - '0';
            } else if (isdigit(s[i]) && fnd) {
                y *= 10;
                y += s[i] - '0';
            } else if (s[i] == ',') {
                fnd = 1;
            }
        }
        getline(cin, s);
        int mn = inf;
        for (int i = 0; i <= 100; ++i) {
            if (i * ax > x || i * ay > y) continue;
            if ((x - i * ax) % bx) continue;
            if ((y - i * ay) % by) continue;
            if ((x - i * ax) / bx != (y - i * ay) / by) continue;
            mn = min(mn, 3 * i + (x - i * ax) / bx);
        }
        if (mn != inf) ans += mn;
    }

    cout << ans << endl;

    return 0;
}
