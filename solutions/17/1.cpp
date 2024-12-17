#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string ln;
    getline(cin, ln);
    long long A = stoll(ln.substr(12));
    getline(cin, ln);
    long long B = stoll(ln.substr(12));
    getline(cin, ln);
    long long C = stoll(ln.substr(12));
    getline(cin, ln);
    getline(cin, ln);

    vector<int> a;
    for (int i = 9; i < (int) ln.size(); i += 2) {
        a.push_back(ln[i] - '0');
    }

    vector<int> ans;
    int n = a.size();
    for (int i = 0; i < n; i += 2) {
        int opd = a[i + 1];
        long long com = opd;
        if (opd == 4) com = A;
        if (opd == 5) com = B;
        if (opd == 6) com = C;

        if (a[i] == 0) {
            A >>= com;
        } else if (a[i] == 1) {
            B ^= opd;
        } else if (a[i] == 2) {
            B = com & 7ll;
        } else if (a[i] == 3) {
            if (A != 0) i = opd - 2;
        } else if (a[i] == 4) {
            B ^= C;
        } else if (a[i] == 5) {
            ans.push_back(com & 7ll);
        } else if (a[i] == 6) {
            B = A >> com;
        } else if (a[i] == 7) {
            C = A >> com;
        }
    }

    int k = ans.size();
    for (int i = 0; i < k; ++i) {
        cout << ans[i] << ",\n"[i == k - 1];
    }

    return 0;
}
