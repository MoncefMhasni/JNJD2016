#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int MOD = (long long)1e9 + 7;

int main( void ) {

    freopen("input.txt", "r", stdin);

    int t;

    cin >> t;
    while(t--) {
        int n;

        cin >> n; // Nodes

        n -= 1;

        vector<int> A(n);
        vector<int> B(n);

        for(int i = 0; i < n; i++)
            cin >> A[i];

        for(int i = 0; i < n; i++)
            cin >> B[i];

        vector<long long> f(n, 0);
        vector<long long> g(n, 0);

        f[0] = g[0] = 1;
        for(int i = 1; i < n; i++) {
            if(A[i] > A[i - 1]) f[i] += f[i - 1];
            if(A[i] > B[i - 1]) f[i] += g[i - 1];
            if(B[i] > A[i - 1]) g[i] += f[i - 1];
            if(B[i] > B[i - 1]) g[i] += g[i - 1];

            f[i] %= MOD;
            g[i] %= MOD;
        }

        long long ans = (f[n - 1] + g[n - 1]) % MOD;
        cout << ans << endl;
    }

    return 0;
}
