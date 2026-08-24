// https://leetcode.com/problems/stone-game-viii/description/?envType=daily-question&envId=2026-08-24

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n+1, -1);

        for(int i =1; i<n; i++){
            stones[i]+=stones[i-1];
        }

        dp[n-1]=stones[n-1];
        for(int i = n-2; i>=1; i--){
            int take = stones[i]-dp[i+1];
            int ntake = dp[i+1];
            dp[i]=max(take,ntake);
        }
        return dp[1];
    }
};
