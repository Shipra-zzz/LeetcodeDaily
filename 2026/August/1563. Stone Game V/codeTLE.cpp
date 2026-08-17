// https://leetcode.com/problems/stone-game-v/description/?envType=daily-question&envId=2026-08-17
class Solution {
public:
    int solve(int l, int r, vector<int>& s, vector<vector<int>> &dp, vector<int> &cs){
        if(l>=r) return 0;

        int ans = 0;

        for(int i=l; i<r; i++){
            int lsum = cs[i]- (l-1>=0 ? cs[l-1] : 0);
            int rsum = cs[r]-cs[i];
            if(lsum>rsum)
                ans = max(ans,rsum + solve(i+1, r, s, dp, cs));
            else if(rsum>lsum)
                ans = max(ans,lsum + solve(l, i, s, dp, cs));
            else
                ans = max(ans, max(rsum + solve(i+1, r, s, dp, cs), lsum + solve(l, i, s, dp, cs)));
        }
        return dp[l][r]=ans;

    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> cs (n,0);
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        cs[0]=stoneValue[0];
        for(int i=1; i<n;i++){
            cs[i]=cs[i-1]+stoneValue[i];
        }
        return solve(0, n-1, stoneValue, dp,cs);
    }
};
