#include <bits/stdc++.h>

using namespace std;

int dig(long long n) {
    int x = 0;
    while (n) {
        ++x;
        n /= 10;
    }
    return x;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    const int bli = 75;

    long long po10[40] = {1};
    for (int i = 1; i < 40; ++i) po10[i] = po10[i - 1] * 10;

    map<long long, long long> dp[bli + 1];
    long long x;
    while (cin >> x) ++dp[0][x];

    for (int i = 0; i < bli; ++i) {
        for (auto [x, v] : dp[i]) {
            int d = dig(x);
            if (x == 0) dp[i + 1][1] += v;
            else if (d % 2 == 0) {
                dp[i + 1][x / po10[d / 2]] += v;
                dp[i + 1][x % po10[d / 2]] += v;
            } else dp[i + 1][x * 2024] += v;
        }
    }

    long long ans = 0;
    for (auto [k, v] : dp[bli]) {
        ans += v;
    }
    cout << ans << endl;

    return 0;
}
