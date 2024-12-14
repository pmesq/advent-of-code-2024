#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // const int n = 7, m = 11;
    const int n = 103, m = 101;

    vector<tuple<int, int, int, int>> a;

    string ln;
    while (getline(cin, ln)) {
        int cnt = 0;
        vector<int> b(4);
        string cur;
        for (int i = 0; i < (int) ln.size(); ++i) {
            if (ln[i] == ',' || ln[i] == ' ') {
                b[cnt] = stoi(cur);
                cur = "";
                ++cnt;
            } else if (isdigit(ln[i]) || ln[i] == '-') {
                cur.push_back(ln[i]);
            }
        }
        b[cnt] = stoi(cur);
        a.emplace_back(b[0], b[1], b[2], b[3]);
    }

    for (int t = 0; t < 100; ++t) {
        for (auto&[x, y, vx, vy] : a) {
            x = ((x + vx) % m + m) % m;
            y = ((y + vy) % n + n) % n;
        }
    }

    int q[3][3] = {0};
    for (auto [x, y, vx, vy] : a) {
        int px = 2, py = 2;
        if (x < m / 2) px = 0;
        else if (x > m / 2) px = 1;
        if (y < n / 2) py = 0;
        else if (y > n / 2) py = 1;
        ++q[px][py];
    }
    long long ans = q[0][0] * q[0][1] * q[1][0] * q[1][1];
    cout << ans << endl;

    return 0;
}
