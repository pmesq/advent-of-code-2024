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

    const int K = 40;
    long long po3[K] = {1}, po10[K] = {1};
    for (int i = 1; i < K; ++i) {
        po3[i] = 3 * po3[i - 1];
        po10[i] = 10 * po10[i - 1];
    }

    long long ans = 0;

    string ln;
    while (getline(cin, ln)) {
        stringstream ss(ln);
        long long y; ss >> y;
        ss.ignore();
        vector<long long> p;
        long long u;
        while (ss >> u) p.push_back(u);
        int n = (int) p.size();
        int psb = 0;
        for (int it = 0; it < po3[n - 1]; ++it) {
            int m = it;
            __int128 x = p[0];
            for (int i = 0; i < n - 1; ++i) {
                if (m % 3 == 0) {
                    x *= p[i + 1];
                } else if (m % 3 == 1) {
                    x += p[i + 1];
                } else {
                    x = x * po10[dig(p[i + 1])] + p[i + 1];
                }
                if (x > y) break;
                m /= 3;
            }
            if (x == y) psb = 1;
        }
        ans += psb * y;
    }

    cout << ans << endl;

    return 0;
}
