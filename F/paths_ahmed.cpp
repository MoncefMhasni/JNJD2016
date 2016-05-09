#include <bits/stdc++.h>

using namespace std;

const int mod = (int) 1e9 + 7;
const int M   = (int) 1e5 + 5;

int T, N, ff[M], ss[M], dp[M][2];

int main() {

   scanf("%d", &T);
   for(int qq=1; qq<=T; ++qq) {
      scanf("%d", &N);
      for (int i=1; i<N; i++) scanf("%d", ff + i);
      for (int i=1; i<N; i++) scanf("%d", ss + i);
      memset(dp, 0, sizeof(dp));
      dp[1][0] = 1;
      dp[1][1] = 1;
      for (int i=2; i<N; i++) {
         if (ff[i] > ff[i - 1]) dp[i][0] += dp[i - 1][0];
         if (ff[i] > ss[i - 1]) dp[i][0] += dp[i - 1][1];
         if (ss[i] > ff[i - 1]) dp[i][1] += dp[i - 1][0];
         if (ss[i] > ss[i - 1]) dp[i][1] += dp[i - 1][1];

         dp[i][0] %= mod;
         dp[i][1] %= mod;
      }

      int ans = (dp[N - 1][0] + dp[N - 1][1]) % mod;
      printf("%d\n", ans);
   }
   
   return 0;
}
