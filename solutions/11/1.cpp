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

    const int bli = 25;

    long long po10[40] = {1};
    for (int i = 1; i < 40; ++i) po10[i] = po10[i - 1] * 10;

    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);

    for (int i = 0; i < bli; ++i) {
        vector<long long> b;
        for (long long x : a) {
            int d;
            if (x == 0) b.push_back(1);
            else if ((d = dig(x)) % 2 == 0) {
                b.push_back(x / po10[d / 2]);
                b.push_back(x % po10[d / 2]);
            } else b.push_back(x * 2024);
        }
        a = b;
    }
    cout << (int) a.size() << endl;

    return 0;
}
