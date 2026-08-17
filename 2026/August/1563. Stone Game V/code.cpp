// https://leetcode.com/problems/stone-game-v/?envType=daily-question&envId=2026-08-17

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        // Prefix sum
        vector<int> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + stoneValue[i];
        }

        // dp[l][r] = maximum score for subarray [l...r]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // length of subarray
        for (int len = 2; len <= n; len++) {

            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;

                for (int i = l; i < r; i++) {

                    int lsum = ps[i + 1] - ps[l];
                    int rsum = ps[r + 1] - ps[i + 1];

                    if (lsum < rsum) {
                        dp[l][r] = max(
                            dp[l][r],
                            lsum + dp[l][i]
                        );
                    }
                    else if (rsum < lsum) {
                        dp[l][r] = max(
                            dp[l][r],
                            rsum + dp[i + 1][r]
                        );
                    }
                    else {
                        dp[l][r] = max(
                            dp[l][r],
                            max(
                                lsum + dp[l][i],
                                rsum + dp[i + 1][r]
                            )
                        );
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};
