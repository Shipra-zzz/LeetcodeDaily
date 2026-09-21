// https://leetcode.com/problems/find-x-value-of-array-i/description/?envType=daily-question&envId=2026-09-21

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k), dp(k);

        for (int x : nums) {
            vector<long long> cur(k);
            int r = x % k;

            cur[r]++;

            for (int j = 0; j < k; j++)
                cur[j * r % k] += dp[j];

            for (int j = 0; j < k; j++)
                ans[j] += cur[j];

            dp = cur;
        }

        return ans;
    }
};
