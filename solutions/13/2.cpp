#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    const long long ADD = 10000000000000ll;

    long long ans = 0;

    string s;
    while (getline(cin, s)) {
        int ax = (s[12] - '0') * 10 + s[13] - '0';
        int ay = (s[18] - '0') * 10 + s[19] - '0';
        getline(cin, s);
        int bx = (s[12] - '0') * 10 + s[13] - '0';
        int by = (s[18] - '0') * 10 + s[19] - '0';
        getline(cin, s);
        long long x = 0, y = 0;
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

        x += ADD;
        y += ADD;

        long long l = lcm(bx, by);

        long long num = l / bx * x - l / by * y;
        long long den = l / bx * ax - l / by * ay;
        if (num % den) continue;
        long long at = num / den;

        if ((x - ax * at) % bx) continue;
        long long bt = (x - ax * at) / bx;        

        if (at < 0 || bt < 0) continue;

        ans += 3 * at + bt;
    }

    cout << ans << endl;

    return 0;
}
